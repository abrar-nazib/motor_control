#include <Arduino.h>
// #include <LiquidCrystal_I2C.h>
#include "motor.h"
#include "keypad.h"
#include "lcd.h"

// Display::Display(Motor m, KeyPad k, LiquidCrystal_I2C l) : motor(m), keypad(k), lcd(l)
// {

//     lcd.init();
//     lcd.backlight();
//     // Clear lcd display
//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print("RPM: ");
//     lcd.setCursor(0, 1);
//     lcd.print("Target: ");
// }

// void Display::set_target_rpm(int rpm)
// {
//     MTR_TARGET_RPM = rpm;
// }

// void Display::update()
// {
//     MTR_CURRENT_RPM = motor.get_current_rpm();
//     // MTR_INPUT_RPM = motor.get_input_rpm();
//     lcd.setCursor(5, 0);
//     lcd.print(MTR_CURRENT_RPM);
//     lcd.setCursor(8, 1);
//     lcd.print(MTR_TARGET_RPM);
// }

// void Display::show_error()
// {
//     lcd.setCursor(0, 0);
//     lcd.print("ERROR");
//     lcd.setCursor(0, 1);
//     lcd.print("RPM: ");
//     lcd.setCursor(5, 1);
//     lcd.print(MTR_CURRENT_RPM);
//
// }

void update_display(Motor motor, KeyPad keypad, LiquidCrystal_I2C lcd)
{
    // lcd.setCursor(0, 0);
    // lcd.print("CUR-RPM: ");
    lcd.setCursor(0, 1);
    lcd.print("TAR-RPM: ");
    lcd.setCursor(9, 0);
    lcd.print("         ");
    // lcd.setCursor(9, 0);
    // lcd.print(motor.get_current_rpm());
    lcd.setCursor(9, 1);
    lcd.print("         ");
    lcd.setCursor(9, 1);
    lcd.print(keypad.get_target_rpm());
}