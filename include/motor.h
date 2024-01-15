#ifndef MOTOR
#define MOTOR

#include <Arduino.h>

class Motor
{

public:
    Motor();
    void forward(long rpm);
    void backward(long rpm);
    void stop();
    int get_current_rpm();
    void set_current_rpm(long rpm);
    void set_target_rpm(long rpm);
    void run_pid();

private:
    const byte R_PWM_PIN = 5;
    const byte L_PWM_PIN = 6;
    const byte R_EN = 8;
    const byte L_EN = 9;
    const long RPM_MAX = 3000;
    const long RPM_MIN = 0;
    const long PWM_MAX = 255;
    const long PWM_MIN = 0;
    long CURRENT_PWM = 0;
    long TARGET_PWM = 0;
    long RPM_TARGET = 0;
    long CURRENT_RPM = 0;
};
#endif // MOTOR