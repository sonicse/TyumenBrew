#ifndef EEP_H
#define EEP_H

#include <EEPROM.h>

/*
// EEPROM usage:
// Thermometer - 9,10,15
// TempRestController - 0,1
*/

template <class T>
int EepWrite(int ee, const T& value)
{
   const byte* p = (const byte*)(const void*)&value;
   int i;
   for (i = 0; i < sizeof(value); i++)
       EEPROM.write(ee++, *p++);
   return i;
}

template <class T>
int EepRead(int ee, T& value)
{
   byte* p = (byte*)(void*)&value;
   int i;
   for (i = 0; i < sizeof(value); i++)
       *p++ = EEPROM.read(ee++);
   return i;
}

/*
void LoadPidSettings (PID &pid, unsigned int &window_size)
{
  double eepromKp = 0;
  double eepromKi = 0;
  double eepromKd = 0;

  read_set(eepromKp, 0);
  read_set(eepromKi, 2);
  read_set(eepromKd, 4);
  
  eepromKi = eepromKi/100;

  pid.SetTunings(eepromKp,eepromKi,eepromKd); // send the PID settings to the PID

  read_set(window_size, 6);
  
  pid.SetOutputLimits(0.0, 100.0);
  pid.SetSampleTime(3500);
}
*/

#endif //EEP_H
