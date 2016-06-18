/*
    An example test class which uses a Timer in a class
*/

#ifndef Blink_h
#define Blink_h

#include "Arduino.h"
#include <Timer.h> // https://github.com/JChristensen/Timer/tree/v2.1
    // Timer.h uses millis() instead of built in timers 

class Blink
{
public:
  Blink (int led_pin, int duration);
  void begin ();
  void updateTimer();
   
private:
  static void _callbackGlue(void *context);
  void _callback();

  Timer _blink_timer;
  int _led_pin;
  int _duration;
  int _led_status;
  int _blink_event;

};

#endif
