#include "Buzzer.h"

void Buzzer::Buzz(unsigned char beep_count, int time)
{
    int tom = 1000;
    long tempo_value= 120000;
    long tempo_gasto = 0;
    
    while (tempo_gasto < tempo_value)
    {
        Pin::On();
        delayMicroseconds(tom / 2);
 
        Pin::Off();
        delayMicroseconds(tom/2);
 
        tempo_gasto += tom;
    }
    delayMicroseconds(1000); //pausa entre notas!
}

void Buzzer::Click()
{
    int time = 100;
    
    Pin::On();
    delay (time);
    Pin::Off();
    delay(100);
}

void Buzzer::Test()
{
    Serial.println("TestBuzzer");
    
    Buzz(2, 100);
}
