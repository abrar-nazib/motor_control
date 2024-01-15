#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "motor.h"
#include "keypad.h"
#include "lcd.h"

Motor motor;
KeyPad keypad;
volatile unsigned long last_reading_time = millis();
volatile long count = 0;
long target_rpm = 0;
volatile unsigned long last_interrupt_time = micros();

volatile unsigned long last_display_time = millis();

LiquidCrystal_I2C lcd(0x27, 16, 2);

void update_encoder()
{
  // noInterrupts();
  unsigned long last_interrupt_delay = micros() - last_interrupt_time;
  // Serial.println(last_interrupt_delay);
  if (last_interrupt_delay > 1000)
    count++;

  last_interrupt_time = micros();
  // delayMicroseconds(1000);
  // interrupts();
}

void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Motor Control");
  lcd.setCursor(0, 1);
  lcd.print(" Group 5 (25-29)");
  delay(5000);
  lcd.clear();
  pinMode(2, INPUT);
  // attachInterrupt(digitalPinToInterrupt(2), update_encoder, FALLING);
}

void loop()
{

  if ((millis() - last_display_time) > 500)
  {
    update_display(motor, keypad, lcd);
    last_display_time = millis();
  }

  keypad.get_key();
  target_rpm = keypad.get_target_rpm();
  motor.set_target_rpm(target_rpm);
  motor.run_pid();

  if ((millis() - last_reading_time) > 1000)
  {
    long rps = count;
    long rpm = rps * 60;
    // Serial.println(rpm);
    motor.set_current_rpm(rpm);
    count = 0;
    last_reading_time = millis();
    // Serial.println(rpm);
  }
  if (!digitalRead(2))
    update_encoder();
  // Serial.println(digitalRead(2));
  // motor.forward(100);
  // Serial.println(rpm);
}