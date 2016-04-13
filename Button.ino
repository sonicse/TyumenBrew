#include "Button.h"

void Button::Setup()
{
    pinMode (pin_, INPUT);
}

bool Button::IsPressed(int time)
{
    if (digitalRead(pin_) == HIGH)
    {
        delay (time);
        
        if (digitalRead(pin_) == HIGH)
        {
            while(digitalRead(pin_) == HIGH) {}
            
            Serial.println("Button Pressed");
            
            return true;
        }
    }
    
    return false;
}
