#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal.h>

#include "Base.h"

class TempRestHolder;

class Lcd : public Base
{
public:
  Lcd(unsigned char pin1, unsigned char pin2, unsigned char pin3, unsigned char pin4, unsigned char pin5, unsigned char pin6);

  void SetDevices(TempRestHolder *holder);
  void Setup();
  void Loop(){};
  
  void PrintSpace(unsigned char count);
  void PrintLineSpace(unsigned char line);
  void PrintWelcomeTitle();
  void PrintTemperature(float temperature);
  void PrintVersion(unsigned char cursor_x, unsigned char cursor_y);
  void PrintMenuDefault(float temperature);
  void PrintMenuManual();
  void PrintOkExit();
  void PrintPromptForWater();
  
  void PrintTest(float temperature, boolean pump_state, unsigned long pump_time, boolean heater_big_state, boolean heater_small_state);

  unsigned long GetDays(unsigned long time) const;
  unsigned long GetHours(unsigned long time) const;
  unsigned long GetMinutes(unsigned long time) const;
  unsigned long GetSeconds(unsigned long time) const;

  void PrintTimeHms(unsigned long time);
  void PrintTimeMs(unsigned long time);
  
private:
    LiquidCrystal lcd_;

    TempRestHolder *holder_;
};

#endif //LCD_H
