/*
 * TinyClock - software Clock that reads millis() function and create clock with 
 * human readable values of hours, minutes, seconds and days from the start. That 
 * simplifies to handle daily/hourly etc. repeating tasks without all that math with 
 * millis(). Library is very tiny and optimized for small AVRs with limited Flash 
 * and RAM.
 */

#ifndef TinyClock_h
#define TinyClock_h

#include "Arduino.h"

#define TICKS_PER_SECOND 1000
/* millis() timing in tiny13 (used with MicroCore) uses internal rc oscillator for WDT,
 * that can't be calibrated. So timing can be calibrated through TICKS_PER_SECOND.
 * millis() timing in tiny AVR's (used with TinyCore) may use internal rc oscillator. 
 * That can be calibrated, but you can also calibrate timing with TICKS_PER_SECOND:
 * - if your timings are long (oscillator is slow), lower number for TICKS
 * - if your timings are short (oscillator is faster), increase number for TICKS 
 */

class TinyClock
{
  public:
    TinyClock();
    void set(byte hours, byte minutes, byte seconds);
    byte secs();
    byte minutes();
    byte hours();
    unsigned int days();
    unsigned int hhmm();
    void power_idle();
    void power_down();
    void sync();
   
  private:
    byte _secs;
    byte _minutes;
    byte _hours;
    unsigned int _days;
    unsigned long _lastupdate;

};

class StopWatch
{
public:
    StopWatch();
    unsigned long secs();
    void sync();
    void reset();
private:
    unsigned long _seconds;
    unsigned long _starttime;
};

class Timer
{
public:
    Timer(unsigned long seconds);
    unsigned long secs();
    void sync();
private:
    unsigned long _seconds;
    unsigned long _starttime;
};

#endif
