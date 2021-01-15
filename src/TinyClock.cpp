#include "Arduino.h"
#include "TinyClock.h"
#include <avr/sleep.h>

TinyClock::TinyClock(void) {
  _lastupdate=millis();
  _secs=_minutes=_hours=_days=0;
}

byte TinyClock::secs(void){

    return _secs;
};

byte TinyClock::minutes(){

    return _minutes;
};

byte TinyClock::hours(){

    return _hours;
};

unsigned int TinyClock::hhmm(){

    return _hours*100+_minutes;
};

unsigned int TinyClock::days(){

    return _days;
};

void TinyClock::set(byte hours, byte minutes, byte seconds){
    _lastupdate=millis();
    _hours=hours;
    _minutes=minutes;
    _secs=seconds;
}
    
void TinyClock::power_idle(){

    set_sleep_mode (SLEEP_MODE_IDLE); 
    sleep_mode();
};

void TinyClock::power_down(){

    set_sleep_mode (SLEEP_MODE_PWR_DOWN); 
    sleep_enable();
    sleep_cpu();
};

void TinyClock::sync(){

    //optimized for tiny core - cycle through time is more effective then divide 
    while(millis() - _lastupdate >= TICKS_PER_SECOND){  //should survive overflow
        _lastupdate += TICKS_PER_SECOND;
        _secs++;

        if (_secs>=60) { 
          _minutes++;
          _secs-=60;
        }

        if (_minutes>=60) { 
          _hours++;
          _minutes-=60;
        }

    }
    if (_hours>=24) {
        _hours-=24;
        _days++;
    }

};

StopWatch::StopWatch(){
    _starttime=millis();
    _seconds=0;
};

unsigned long StopWatch::secs(){
    
    return _seconds;
};

void StopWatch::reset(){
    
    _starttime=millis();
    _seconds=0;
};

void StopWatch::sync(){
    
    while(millis()-_starttime > TICKS_PER_SECOND){  //should survive overflow
        _starttime+=TICKS_PER_SECOND;
        _seconds++;
    }
};
    
Timer::Timer(unsigned long seconds){
    _starttime=millis();
    _seconds=seconds;
}

unsigned long Timer::secs(){

    return _seconds;
};

void Timer::sync(){
    
    while( _seconds>0 && millis()-_starttime > TICKS_PER_SECOND){  //should survive overflow
        _starttime+=TICKS_PER_SECOND;
        _seconds++;
    }

};
