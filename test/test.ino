#include "blink.h"

int my_led_pin = 13;
int milliseconds_on_off = 1000;

Blink my_blink(my_led_pin, milliseconds_on_off);

void setup()
{
    my_blink.start();
}

void loop()
{
    my_blink.updateTimer();
    Serial.println(my_blink.getStatus());
}
