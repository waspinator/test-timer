#include "Blink.h"


Blink first_blink (13, 500);
Blink second_blink (12, 1000);

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");
  first_blink.begin();
  second_blink.begin();
} 

void loop()
{
    first_blink.updateTimer();
    second_blink.updateTimer();
}
