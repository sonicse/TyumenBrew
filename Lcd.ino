#include "Lcd.h"

void Lcd::Setup()
{
    lcd_.begin(20,4);
}

void Lcd::PrintSpace(unsigned char count)
{
  for(unsigned char i=0; i < count; ++i)
  {
    lcd_.print(F(" "));
  }
}

void Lcd::PrintLineSpace(unsigned char line)
{
    lcd_.setCursor(0, line);
    PrintSpace(20);
}

void Lcd::PrintWelcomeTitle()
{  
    lcd_.setCursor(0,0);
    lcd_.print(F("TyumenBrew"));
}

void Lcd::PrintTemperature(float temperature)
{
  if (temperature < 10.0) {
      PrintSpace(1);
  }

  if (temperature >= 100.0) {
      lcd_.print(temperature, 1);
  }
  else {
      lcd_.print(temperature);
  }
  
  lcd_.write((unsigned char)0);
}

void Lcd::PrintVersion(unsigned char cursor_x, unsigned char cursor_y)
{
    lcd_.setCursor(cursor_x, cursor_y);
    PrintSpace(1);
  
    lcd_.print(F("v0.1"));
    lcd_.write(7);
}

void Lcd::PrintMenuDefault(float temperature)
{
    PrintWelcomeTitle();
    lcd_.setCursor(6,1);
    PrintTemperature(temperature);
    
    PrintLineSpace(2);
    
    lcd_.setCursor(1,3);
    lcd_ .print(F("---  MAN AUTO SETUP"));
    
    PrintVersion(12,0);
}

void Lcd::PrintMenuManual()
{
    lcd_.clear();
    lcd_.setCursor(0,0);
    lcd_.print(F("Manual Mode"));
    delay(750);
}

void Lcd::PrintOkExit()
{
  lcd_.setCursor(8,1);
  lcd_.print(F("Ok Exit"));
}

void Lcd::PrintPromptForWater()
{
  lcd_.setCursor(0,0);
  lcd_.print(F("Adding water?"));
  
  PrintOkExit();
  //Buzz(1,750);
}

void Lcd::PrintTest(float temperature, boolean pump_state, boolean heater_big_state, boolean heater_small_state)
{
  // Temperature
  PrintLineSpace(0);
  lcd_.setCursor(0,0);
  lcd_.print(F("Temperature: "));
  PrintTemperature(temperature);
  
  // Pump
  PrintLineSpace(1);
  lcd_.setCursor(0,1);
  lcd_.print(F("Pump: "));
  lcd_.print((pump_state) ? F("On") : F("Off"));
  
  // Heater Big
  PrintLineSpace(2);
  lcd_.setCursor(0,2);
  lcd_.print(F("Heater Big: "));
  lcd_.print((heater_big_state) ? F("On") : F("Off"));
  
  // Heater Small
  PrintLineSpace(3);
  lcd_.setCursor(0,3);
  lcd_.print(F("Heater Small: "));
  lcd_.print((heater_small_state) ? F("On") : F("Off"));
}
