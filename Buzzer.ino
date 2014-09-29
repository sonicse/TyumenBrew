#include "Buzzer.h"

void Buzzer::Setup()
{
    pinMode(pin_, OUTPUT);
}

void Buzzer::Buzz(unsigned char beep_count, int time)
{
    int tom = 1000;
    long tempo_value= 120000;
    long tempo_gasto = 0;
    
    while (tempo_gasto < tempo_value)
    {
        digitalWrite(pin_, HIGH);
        delayMicroseconds(tom / 2);
 
        digitalWrite(pin_, LOW);
        delayMicroseconds(tom/2);
 
        tempo_gasto += tom;
    }
    delayMicroseconds(1000); //pausa entre notas!
}

void Buzzer::Click()
{
    int time = 100;
    
    digitalWrite(pin_, HIGH);
    delay (time);
    digitalWrite(pin_, LOW);
    delay(100);
}

void Buzzer::Test()
{
    Serial.println("TestBuzzer");
    
    Buzz(2, 100);
}
