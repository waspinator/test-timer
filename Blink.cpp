#include "Arduino.h"
#include "Blink.h"

Blink::Blink (int led_pin, int duration) 
{
  _led_status = 0;
  _led_pin = led_pin;
  _duration = duration;

  pinMode(_led_pin, OUTPUT);
  digitalWrite(_led_pin, LOW);
}

void Blink::begin ()
{
  _blink_event = _blink_timer.every(_duration, _callbackGlue, this);
}
  
void Blink::_callbackGlue(void *context)
{
  ((Blink *)context)->_callback();
}

void Blink::_callback()
{
    if (_led_status == 0) {
        digitalWrite(_led_pin, HIGH);
        _led_status = 1;
    } else if (_led_status == 1) {
        digitalWrite(_led_pin, LOW);
        _led_status = 0;
    }
}

void Blink::updateTimer()
{
    _blink_timer.update();
}
