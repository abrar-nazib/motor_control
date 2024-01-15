#ifndef LCD
#define LCD

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "motor.h"
#include "keypad.h"

void update_display(Motor motor, KeyPad keypad, LiquidCrystal_I2C lcd);

#endif // LCD