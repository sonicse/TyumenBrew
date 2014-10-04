#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal.h>

#include "Base.h"

class Lcd : public Base
{
public:
  Lcd(unsigned char pin1, unsigned char pin2, unsigned char pin3, unsigned char pin4, unsigned char pin5, unsigned char pin6) :lcd_(pin1, pin2, pin3, pin4, pin5, pin6) {};

  void Setup();

  void PrintSpace(unsigned char count);
  void PrintLineSpace(unsigned char line);
  void PrintWelcomeTitle();
  void PrintTemperature(float temperature);
  void PrintVersion(unsigned char cursor_x, unsigned char cursor_y);
  void PrintMenuDefault(float temperature);
  void PrintMenuManual();
  void PrintOkExit();
  void PrintPromptForWater();

private:
    LiquidCrystal lcd_;
};

#endif //LCD_H
