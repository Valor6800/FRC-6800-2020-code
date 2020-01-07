#include "Trajectory.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#define LOG_FILE_NAME "turn.csv"

#define TESTING true
#define LOGGING true

// Robot specific parameters
#define DEFAULT_MAX_VELOCITY 14.0
#define DEFAULT_MAX_ACCEL 14.0
#define DEFAULT_WHEEL_BASE 2.4

// feet necessary to max velcoity
#define D_1 7.14

Trajectory::Trajectory() : logfile(LOG_FILE_NAME)
{
    // Set some default gains. Shouldn't change
    kv = 1 / DEFAULT_MAX_VELOCITY;
    ka = 0;
    kp = 0;
    kd = 0;

    // Create default states
    curr_left_state = new State;
    curr_right_state = new State;

// Only log to a file if the logging macro is specified
#ifdef LOGGING
    if (logfile.is_open()) {
        logfile << "time, position, velocity, feed_forward, feed_back, output, error, error_d, position, velocity, feed_forward, feed_back, output, error, error_d\n";
    } else {
        printf("Unable to open log file\n");
    }
#endif
}

Trajectory::Trapezoid Trajectory::create_trapezoid(double distance) {
    Trajectory::trapezoid.max_velocity = DEFAULT_MAX_VELOCITY;
    Trajectory::trapezoid.max_accel = DEFAULT_MAX_ACCEL;
    Trajectory::trapezoid.distance = distance;

    Trajectory::trapezoid.t_1 = sqrt((2.0 * D_1) / Trajectory::trapezoid.max_accel);
    Trajectory::trapezoid.t_2 = Trajectory::trapezoid.t_1 + ((distance - (2.0 * D_1)) / Trajectory::trapezoid.max_velocity);
    Trajectory::trapezoid.d_1 = D_1;
    Trajectory::trapezoid.d_2 = Trajectory::trapezoid.d_1 + ((Trajectory::trapezoid.t_2 - Trajectory::trapezoid.t_1) * Trajectory::trapezoid.max_velocity);
    
    Trajectory::trapezoid.time = Trajectory::trapezoid.t_1 + Trajectory::trapezoid.t_2;

    return Trajectory::trapezoid;
}

void Trajectory::plan(Trajectory::Trapezoid *plan)
{
    // Calculate the rising edge of the trapezoid
    plan->t_1 = plan->max_velocity/plan->max_accel;
    plan->d_1 = 0.5 * plan->max_accel * plan->t_1 * plan->t_1;

    // Check if you never get up to full speed
    if (plan->d_1 > plan->distance / 2) {
        plan->d_1 = plan->distance / 2;
        plan->t_1 = sqrt(plan->d_1 / (0.5 * plan->max_accel));
    }

    // Calculate the straight, or constant top, of the trapezoid
    double straight_distance = plan->distance - (plan->d_1 * 2);
    plan->t_2 = straight_distance / plan->max_velocity + plan->t_1;
    plan->d_2 = plan->d_1 + straight_distance;

    // Calculate complete time to complete the entire trapezoid
    plan->time = plan->t_2 + plan->t_1;
}

void Trajectory::plan_straight(double target_distance, Trajectory::Trapezoid *straight_plan)
{
    // Both wheels can travel at max velocity or max acceleration
    straight_plan->distance = target_distance;
    straight_plan->max_accel = DEFAULT_MAX_ACCEL;
    straight_plan->max_velocity = DEFAULT_MAX_VELOCITY;

    // Create the trapezoid for both wheels being the same
    plan(straight_plan);
}

void Trajectory::plan_turn(double radius, int degree, Trajectory::Trapezoid *left_plan, Trajectory::Trapezoid *right_plan)
{
    double half_wheel_base = DEFAULT_WHEEL_BASE / 2;

    // Check if you are going left or right for sign inversion
    if (degree > 0) {
        // Use the left wheel as the max velocity wheel. Add half the drive base to the curve
        left_plan->distance = (radius + half_wheel_base) * M_PI * (degree / 180.0);
        left_plan->max_accel = DEFAULT_MAX_ACCEL;
        left_plan->max_velocity = DEFAULT_MAX_VELOCITY;

        // The right wheel cannot travel max velocity as then the robot will go straight.
        // Reduce the right wheel's speed the turning ratio so the robot arcs
        right_plan->distance = (radius - half_wheel_base) * M_PI * (degree / 180.0);
        right_plan->max_accel = DEFAULT_MAX_ACCEL * (right_plan->distance / left_plan->distance);
        right_plan->max_velocity = DEFAULT_MAX_VELOCITY * (right_plan->distance / left_plan->distance);
    } else {
        // Use the right wheel as the maximum velocity wheel
        right_plan->distance = (radius + half_wheel_base) * M_PI * (degree * -1 / 180.0);
        right_plan->max_accel = DEFAULT_MAX_ACCEL;
        right_plan->max_velocity = DEFAULT_MAX_VELOCITY;

        // The left wheel cannot travel max velocity. Same logic as the right wheel in the other turn case
        left_plan->distance = (radius - half_wheel_base) * M_PI * (degree * -1 / 180.0);
        left_plan->max_accel = DEFAULT_MAX_ACCEL * (left_plan->distance / right_plan->distance);
        left_plan->max_velocity = DEFAULT_MAX_VELOCITY * (left_plan->distance / right_plan->distance);
    }

    // Plan the left and right wheel trapezoids
    plan(left_plan);
    plan(right_plan);
}

void Trajectory::calculate(Trajectory::Trapezoid *plan, Trajectory::State *prev_state, Trajectory::State *new_state)
{
    double time = new_state->time;

    // Ramp up
    if (time < plan->t_1) {
        new_state->s = 0.5 * plan->max_accel * time * time;
        new_state->v = plan->max_accel * time;
        new_state->a = plan->max_accel;

    // Constant velocity
    } else if (time < plan->t_2) {
        new_state->s = plan->d_1 + plan->max_velocity * (time - plan->t_1);
        new_state->v = plan->max_velocity;
        new_state->a = 0;

    // Ramp down
    } else if (time < plan->time) {
        new_state->s = -0.5 * plan->max_accel * (time - plan->time) * (time - plan->time) + plan->distance;
        new_state->v = -plan->max_accel * (time - plan->time);
        new_state->a = -plan->max_accel;

    // Stop
    } else {
        new_state->s = plan->distance;
        new_state->v = 0;
        new_state->a = 0;
    }

    // Calculate the P and D errors to apply feed back
    new_state->error = new_state->s - prev_state->s;
    new_state->error_d = new_state->error - prev_state->error;
    new_state->feed_back = kp * new_state->error + kd * new_state->error_d;

    // Calculate the V and A errors to apply feed forward
    new_state->feed_forward = kv * new_state->v + ka * new_state->a;
}

void Trajectory::track(double time) {

    // Reset left
    State *old = prev_left_state;
    prev_left_state = curr_left_state;
    delete old;
    curr_left_state = new State;

    // Reset right
    old = prev_right_state;
    prev_right_state = curr_right_state;
    delete old;
    curr_right_state = new State;

    // Set time
    curr_left_state->time = time;
    curr_right_state->time = time;

    #ifdef TESTING
        // Randomize new position
        prev_left_state->s += (rand() % 100 - 50) / 100.0;
        prev_right_state->s += (rand() % 100 - 50) / 100.0;
    #elif
        // Set left and right position from encoder
        // @TODO use WPILib to get encoder positions
        /*
        prev_left_state->s = left_encoder_sensor.get();
        prev_right_state->s = right_encoder_sensor.get();
        */
    #endif

    // Calculate the gains to apply to the wheels
    calculate(&left_plan, prev_left_state, curr_left_state);
    calculate(&right_plan, prev_right_state, curr_right_state);
}

void Trajectory::simulate(double time_interval, double time_start, double time_end)
{

    // This simulation is a turning simulation. Can swap with plan_straight if desired
    plan_turn(10, -90, &left_plan, &right_plan);

#ifdef TESTING
    // Randomize the seed
    srand (time(NULL));
#endif
    // Iterate through a set of time intervals and run the tracking function
    // This for loop would be replaced by the execute function of a command
    // emulating 200Hz loop within periodic tasks
    for (int i = 0; i < (time_end - time_start) / time_interval + 1; i++) {
        track(time_start + i * time_interval);
#ifdef LOGGING
        logfile << std::to_string(curr_left_state->time) << "," <<
                std::to_string(curr_left_state->s) << "," <<
                std::to_string(curr_left_state->v) << "," <<
                std::to_string(curr_left_state->feed_forward) << "," <<
                std::to_string(curr_left_state->feed_back) << "," <<
                std::to_string(curr_left_state->feed_back + curr_left_state->feed_forward) << "," <<
                std::to_string(curr_left_state->error) << "," <<
                std::to_string(curr_left_state->error_d) << "," <<
                std::to_string(curr_right_state->s) << "," <<
                std::to_string(curr_right_state->v) << "," <<
                std::to_string(curr_right_state->feed_forward) << "," <<
                std::to_string(curr_right_state->feed_back) << "," <<
                std::to_string(curr_right_state->feed_back + curr_right_state->feed_forward) << "," <<
                std::to_string(curr_right_state->error) << "," <<
                std::to_string(curr_right_state->error_d) << "\n";
#endif
    }
    printf("Simulation complete\n");
}

void test() {
    int x  = 0;
}