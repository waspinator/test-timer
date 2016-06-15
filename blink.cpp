#include "Arduino.h"
#include "blink.h"

Blink::Blink(int led_pin, int duration)
{
    _blink_timer = new Timer();
    _led_status = 0;
    _led_pin = led_pin;
    _duration = duration;

    pinMode(_led_pin, OUTPUT);
    digitalWrite(_led_pin, LOW);
}

int Blink::getStatus()
{
    return _led_status;
}

void Blink::start()
{
    _blink_event = _blink_timer->every(_duration, _blinkCallback, (void*)0);
}

void Blink::updateTimer()
{
    _blink_timer->update();
}

void Blink::_blinkCallback(void *context)
{
    if (_led_status == 0) {
        digitalWrite(_led_pin, HIGH);
        _led_status = 1;
    } else if (_led_status == 1) {
        digitalWrite(_led_pin, LOW);
        _led_status = 0;
    }
}
