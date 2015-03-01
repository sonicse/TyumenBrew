
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <EEPROM.h>

//#include <vector>

#include "Config.h"
#include "Thermometer.h"
#include "Buzzer.h"
#include "Button.h"
#include "Lcd.h"
#include "Led.h"
#include "Heater.h"
#include "Pump.h"
//#include "Eep.h"
//#include "Pid.h"
#include "TempRestHolder.h"

////////////////////////////////////////////////
// Variables

Thermometer  gThermometer(thermometer_pin);
Lcd gLcd(lcd_pin1, lcd_pin2, lcd_pin3, lcd_pin4, lcd_pin5, lcd_pin6);
Buzzer gBuzzer(buzzer_pin);

Button gButtonUp(button_up_pin);
Button gButtonDown(button_down_pin);
Button gButtonStart(button_start_pin);
Button gButtonEnter(button_enter_pin);

Led gLedRed(led1_pin);
Heater gHeaterBig(heater_big_pin, &gLedRed);
Led gLedGreen(led2_pin);
Heater gHeaterSmall(heater_small_pin, &gLedGreen);

Led gLedYellow(led3_pin);
Pump gPump(pump_pin, &gLedYellow);

TempRestHolder gTempRestHolder(&gThermometer, &gHeaterBig);

Base* gDevices[] = {
  &gThermometer, &gLcd, &gBuzzer, &gButtonUp, &gButtonDown, &gButtonStart, &gButtonEnter, &gLedRed, &gHeaterBig, &gLedGreen, &gHeaterSmall, &gLedYellow, &gPump};
const unsigned char gDevicesCount = sizeof(gDevices);

void setup ()
{
  Serial.begin(9600);
  Serial.println("setup");

  for (unsigned char i = 0; i < gDevicesCount; ++i)
  {
    gDevices[i]->Setup();
  }

  gBuzzer.Test();
}

void loop ()
{
  for (unsigned char i = 0; i < gDevicesCount; ++i)
  {
    gDevices[i]->Loop();
  }

  if (gButtonUp.IsPressed(100)) {
    gBuzzer.Click();
  }

  if (gButtonDown.IsPressed(100)) {
    gPump.Toggle();
    gBuzzer.Click();
  }

  if (gButtonStart.IsPressed(100)) {
    gHeaterBig.Toggle();
    gBuzzer.Click();
  }

  if (gButtonEnter.IsPressed(100)) {
    gHeaterSmall.Toggle();
    gBuzzer.Click();
  }

  gLcd.PrintTest(gThermometer.Temperature(), gPump.GetState(), gHeaterBig.GetState(), gHeaterSmall.GetState());
}

