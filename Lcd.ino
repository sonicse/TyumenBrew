#include "Lcd.h"

#include "TempRestHolder.h"

namespace {
  unsigned long kDayMillis = 86400000;
  unsigned long kHourMillis = 3600000;
  unsigned long kMinuteMillis = 60000;
  unsigned long kSecondMillis = 1000;
}

Lcd::Lcd(unsigned char pin1, unsigned char pin2, unsigned char pin3, unsigned char pin4, unsigned char pin5, unsigned char pin6)
:lcd_(pin1, pin2, pin3, pin4, pin5, pin6)
,holder_(NULL)
{
};

void Lcd::SetDevices(TempRestHolder *holder)
{
  holder_ = holder;
}

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

void Lcd::PrintTest(float temperature, boolean pump_state, unsigned long pump_time, boolean heater_big_state, boolean heater_small_state)
{
  // Temperature
  PrintLineSpace(0);
  lcd_.setCursor(0,0);
  lcd_.print(F("Temp: "));
  PrintTemperature(temperature);
  
  if (holder_ && holder_->GetState())
  {
    PrintSpace(1);
    lcd_.print('(');
    lcd_.print(holder_->GetTemperature());
    lcd_.print(')');
  }
  
  // Pump
  PrintLineSpace(1);
  lcd_.setCursor(0,1);
  lcd_.print(F("Pump: "));
  lcd_.print((pump_state) ? F("On") : F("Off"));
  lcd_.setCursor(15,1);
  PrintTimeMs(pump_time);
  
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

unsigned long Lcd::GetDays(unsigned long time) const
{
  return time / kDayMillis;
}

unsigned long Lcd::GetHours(unsigned long time) const
{
  return (time % kDayMillis) / kHourMillis;
}

unsigned long Lcd::GetMinutes(unsigned long time) const
{
  return ((time % kDayMillis) % kHourMillis) / kMinuteMillis;
}

unsigned long Lcd::GetSeconds(unsigned long time) const
{
  return (((time % kDayMillis) % kHourMillis) % kMinuteMillis) / kSecondMillis;
}

void Lcd::PrintTimeHms(unsigned long time)
{
  unsigned long hours = GetHours(time);
  unsigned long minutes = GetMinutes(time);
  unsigned long seconds = GetSeconds(time);
  
  if (hours < 10) lcd_.print('0');
  lcd_.print(hours);
  lcd_.print(':');
  if (minutes < 10) lcd_.print('0');
  lcd_.print(minutes);
  lcd_.print(':');
  if (seconds < 10) lcd_.print('0');
  lcd_.print(seconds);
}

void Lcd::PrintTimeMs(unsigned long time)
{
  unsigned long minutes = GetMinutes(time);
  unsigned long seconds = GetSeconds(time);
  
  if (minutes < 10) lcd_.print('0');
  lcd_.print(minutes);
  lcd_.print(':');
  if (seconds < 10) lcd_.print('0');
  lcd_.print(seconds);
}
