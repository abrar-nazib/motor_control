#include <Arduino.h>
#include "motor.h"

double prev_error = 0;

Motor::Motor()
{
    pinMode(R_PWM_PIN, OUTPUT);
    pinMode(L_PWM_PIN, OUTPUT);
    pinMode(R_EN, OUTPUT);
    pinMode(L_EN, OUTPUT);

    digitalWrite(R_EN, HIGH);
    digitalWrite(L_EN, HIGH);
}

void Motor::stop()
{
    analogWrite(R_PWM_PIN, 0);
    analogWrite(L_PWM_PIN, 0);
}

void Motor::forward(long rpm)
{
    if (rpm > RPM_MAX)
    {
        rpm = RPM_MAX;
    }
    else if (rpm < RPM_MIN)
    {
        rpm = RPM_MIN;
    }

    analogWrite(R_PWM_PIN, rpm);
    analogWrite(L_PWM_PIN, 0);
}

void Motor::backward(long rpm)
{
    if (rpm > RPM_MAX)
    {
        rpm = RPM_MAX;
    }
    else if (rpm < RPM_MIN)
    {
        rpm = RPM_MIN;
    }

    analogWrite(R_PWM_PIN, 0);
    analogWrite(L_PWM_PIN, rpm);
}

int Motor::get_current_rpm()
{
    return CURRENT_RPM;
}

void Motor::set_current_rpm(long rpm)
{
    CURRENT_RPM = rpm;
}

void Motor::set_target_rpm(long rpm)
{
    RPM_TARGET = rpm;
    TARGET_PWM = map(rpm, RPM_MIN, RPM_MAX, PWM_MIN, PWM_MAX);
}

void Motor::run_pid()
{
    double Kp = 0.001;
    double Kd = 0.002;
    double error = RPM_TARGET - CURRENT_RPM;
    double d = error - prev_error;

    double PID_VAL = (error * Kp) + (d * Kd);
    prev_error = error;

    CURRENT_PWM += PID_VAL;
    // Modify current PWM
    if (CURRENT_PWM > PWM_MAX)
    {
        CURRENT_PWM = PWM_MAX;
    }
    else if (CURRENT_PWM < PWM_MIN)
    {
        CURRENT_PWM = PWM_MIN;
    }
    Serial.print("Target: ");
    Serial.print(RPM_TARGET);
    Serial.print(" Current: ");
    Serial.print(CURRENT_RPM);
    Serial.print(" PWM: ");
    Serial.print(CURRENT_PWM);
    Serial.print(" Error: ");
    Serial.println(error);
    // Modify current RPM
    // Serial.println(CURRENT_PWM);
    if (RPM_TARGET < 100)
        CURRENT_PWM = 0;
    forward(CURRENT_PWM);
}

// void set_current_pwm(long pwm){

// }