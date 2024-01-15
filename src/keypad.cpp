#include <Arduino.h>
#include <Keypad.h>
#include "keypad.h"

long string_to_long(String str)
{
  long result = 0;
  for (unsigned int i = 0; i < str.length(); i++)
  {
    result = result * 10 + (str[i] - '0');
  }
  return result;
}

KeyPad::KeyPad()
{
  keypad_ = new Keypad(makeKeymap(keys_), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);
}

char KeyPad::get_key()
{
  char key = keypad_->getKey();
  if (key == 'C')
  {
    clean_target_rpm();
  }
  else if (key == 'D')
  {
    target_rpm_str = target_rpm_str.substring(0, target_rpm_str.length() - 1);
  }
  else if (key != NO_KEY)
  {
    target_rpm_str += key;
  }
  return key;
}

long KeyPad::get_target_rpm()
{
  return string_to_long(target_rpm_str);
}

void KeyPad::clean_target_rpm()
{
  target_rpm_str = "";
}
