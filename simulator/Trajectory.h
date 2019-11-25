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
        double max_acceleration;
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

    void plan_straight(double, Trapezoid *);
    void plan_turn(double, int, Trapezoid *, Trapezoid *);

    void calculate(Trapezoid *, State *, State *);

    void simulate(double, double, double);
    void track(double);

private:
    void plan(Trapezoid *);

    double kv;
    double ka;
    double kp;
    double kd;

    Trapezoid left_plan, right_plan;
    State *prev_left_state, *prev_right_state, *curr_left_state, *curr_right_state;

    std::ofstream logfile;
};