/* Example for TinyClock library. */

#include <TinyClock.h> 

#if defined(ATTINY_CORE)
#define LED_BUILTIN 3
#endif

TinyClock clk=TinyClock();
byte jobdone=0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  clk.set(12,0,0); //assume we will start at 12:00
}

void blink(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

void loop() {

  //blink repeatedly from 12:01 to 13:01 every day:
  if ( clk.hhmm()>=1201 && clk.hhmm()<1301 ) blink();
  //run once at the beginning of every hour
  if ( clk.minutes()==0 ) {
    if ( !jobdone ) { 
      blink();
      blink();
      jobdone=1;
    }
  } else {
    jobdone=0;  //time has gone - reinitialize
  }

  clk.power_idle(); //wait for millis update and save some power
  
  clk.sync();  //clock updates here, call frequently, keep jobs small. 
  /* Update at least once per second if you have scheduled events with 
   * seconds granularity  or you can miss scheduled time. There is no 
   * multitasking in arduino, so another job can't start until running
   * one is not finished and loop() is run again.
   */
}
