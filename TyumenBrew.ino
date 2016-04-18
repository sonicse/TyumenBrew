
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <EEPROM.h>
#include <PID_v1.h>

#include "Config.h"
#include "Thermometer.h"
#include "Buzzer.h"
#include "Button.h"
#include "Lcd.h"
#include "Led.h"
#include "Pin.h"
//#include "Eep.h"
#include "TempRestHolder.h"
#include "PumpController.h"
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
PinLed gHeaterBig(heater_big_pin, &gLedRed);
Led gLedGreen(led2_pin);
PinLed gHeaterSmall(heater_small_pin, &gLedGreen);

Led gLedYellow(led3_pin);
PinLed gPump(pump_pin, &gLedYellow);

PumpController gPumpController(gPump, gHeaterBig, gHeaterSmall);

TempRestHolder gTempHolder(&gThermometer, &gHeaterBig);

Base* gDevices[] = {
  &gThermometer, &gLcd, &gBuzzer, &gButtonUp, &gButtonDown, &gButtonStart, &gButtonEnter, &gLedRed, &gHeaterBig, &gLedGreen, &gHeaterSmall, &gLedYellow, &gPumpController, &gTempHolder};
const unsigned char gDevicesCount = sizeof(gDevices)/sizeof(gDevices[0]);

void setup ()
{
  Serial.begin(9600);
  Serial.println("setup");

  for (unsigned char i = 0; i < gDevicesCount; ++i)
  {
    gDevices[i]->Setup();
  }

  gBuzzer.Test();
  gLcd.SetDevices(&gTempHolder);
}

void loop ()
{
  for (unsigned char i = 0; i < gDevicesCount; ++i)
  {
    gDevices[i]->Loop();
  }

  if (gButtonUp.IsPressed(100)) {
    gTempHolder.Toggle();
    gBuzzer.Click();
  }

  if (gTempHolder.GetState())
  {
    if (gButtonStart.IsPressed(100)) {
      gTempHolder.SetTemperature(gTempHolder.GetTemperature() - 1);
      gBuzzer.Click();
    }

    if (gButtonEnter.IsPressed(100)) {
      gTempHolder.SetTemperature(gTempHolder.GetTemperature() + 1);
      gBuzzer.Click();
    }
  }
  else
  {
    if (gButtonDown.IsPressed(100)) {
      gPumpController.Toggle();
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
  }

  gLcd.PrintTest(gThermometer.Temperature(), gPump.GetState(), gPumpController.GetTime(), gHeaterBig.GetState(), gHeaterSmall.GetState());
}

