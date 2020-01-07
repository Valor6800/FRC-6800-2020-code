#pragma once

#include <fstream>

class Trajectory {
public:
    Trajectory();

    struct Trapezoid {
        double t_1;
        double t_2;
        double d_1;
        double d_2;
        double max_velocity;
        double max_accel;
        double distance;
        double time;
    };

    struct State {
        State() : s(0), v(0), a(0), error(0), error_d(0) {}
        double time;
        double s;
        double v;
        double a;
        double feed_forward;
        double feed_back;
        double error;
        double error_d;
    };

    Trapezoid create_trapezoid(double distance);

    void test();

    void plan_straight(double target_distance, Trapezoid *straight_plan);
    void plan_turn(double radius, int degree, Trapezoid *left_plan, Trapezoid *right_plan);

    void calculate(Trapezoid *plan, State *prev_state, State *new_state);

    void simulate(double time_interval, double time_start, double time_end);
    void track(double time);

    Trapezoid left_plan, right_plan, trapezoid;

    double kv;
    double ka;
    double kp;
    double kd;

    State *prev_left_state, *prev_right_state, *curr_left_state, *curr_right_state;

private:
    void plan(Trapezoid *plan);

    std::ofstream logfile;
};