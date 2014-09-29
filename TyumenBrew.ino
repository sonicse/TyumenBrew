#include <LiquidCrystal.h>
#include <OneWire.h>
#include <EEPROM.h>

#include "Config.h"
#include "Thermometer.h"
#include "Buzzer.h"
#include "Button.h"
#include "Lcd.h"
#include "Eep.h"
//#include "Pid.h"

////////////////////////////////////////////////
// Variables

Thermometer  gThermometer(thermometer_pin);
Lcd gLcd(lcd_pin1, lcd_pin2, lcd_pin3, lcd_pin4, lcd_pin5, lcd_pin6);
Buzzer gBuzzer(buzzer_pin);

Button gButtonUp(button_up_pin);
Button gButtonDown(button_down_pin);
Button gButtonStart(button_start_pin);
Button gButtonEnter(button_enter_pin);

void setup ()
{
    Serial.begin(9600);
    Serial.println("setup");
    
    gThermometer.Setup();
    gLcd.Setup();
    gBuzzer.Setup();
    
    gButtonUp.Setup();
    gButtonDown.Setup();
    gButtonStart.Setup();
    gButtonEnter.Setup();
    
    gBuzzer.Test();
}

void loop ()
{
    if (gButtonUp.IsPressed(100)) {gBuzzer.Click();}
    if (gButtonDown.IsPressed(100)) {gBuzzer.Click();}
    if (gButtonStart.IsPressed(100)) {gBuzzer.Click();}
    if (gButtonEnter.IsPressed(100)) {gBuzzer.Click();}
    
    gLcd.PrintMenuDefault(0.0);
}
