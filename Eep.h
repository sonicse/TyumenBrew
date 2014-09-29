#ifndef EEP_H
#define EEP_H

#include <EEPROM.h>

void r_set(unsigned char& data, int addr)
{
  data=EEPROM.read(addr);
}

void read_set(unsigned char& data, int addr)
{
  data=word(EEPROM.read(addr),EEPROM.read(addr+1));
}

void read_set(float& data, int addr)
{
  data=word(EEPROM.read(addr),EEPROM.read(addr+1));
}

void read_set(double& data, int addr)
{
  data=word(EEPROM.read(addr),EEPROM.read(addr+1));
}

void read_set(int& data, int addr)
{
  data=word(EEPROM.read(addr),EEPROM.read(addr+1));
}

void read_set(unsigned int& data, int addr)
{
  data=word(EEPROM.read(addr),EEPROM.read(addr+1));
}

void save_set (int addr, int data)
{
  EEPROM.write(addr,highByte(data));
  EEPROM.write((addr+1),lowByte(data));
}  

void save_set (int addr, byte data)
{
  EEPROM.write(addr,data);
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
