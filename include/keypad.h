#ifndef KEYPAD
#define KEYPAD

#include <Arduino.h>
#include <Keypad.h>

class KeyPad
{
public:
    KeyPad();
    char get_key();
    long get_target_rpm();
    void clean_target_rpm();

private:
    static const int ROW_NUM = 4;    // four rows
    static const int COLUMN_NUM = 4; // three columns
    const char keys_[ROW_NUM][COLUMN_NUM] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};
    byte pin_rows[ROW_NUM] = {A0, A1, A2, A3};
    byte pin_column[COLUMN_NUM] = {13, 12, 11, 10};
    Keypad *keypad_;
    String target_rpm_str;
    long target_rpm;
};

#endif // KEYPAD