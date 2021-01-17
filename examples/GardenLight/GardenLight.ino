/* Very simple timer for garden ligts with tiny13 and MicroCore
 * Just connect small led light strip (max 40mA) to Pin2 (PB3) and GND. 
 * Battery (2xAA or 3xAA) "+" pole to pin 8 (Vcc) and 
 * "-" pole to pin 4 (GND)
 * Switch on after sunset. Timer will keep lights on for 
 * 5 hours and then turns off. Next day will turn on at 
 * the same time and so on.
 * 
 * Compatible with all Arduinos, but mainly targeted to small ATtiny
 * To save battery life, powersaving is turned on for AVR's
 * 
 */
 
#include <TinyClock.h>

#define MYLED 3

TinyClock clk=TinyClock();

void setup() {

  pinMode(MYLED, OUTPUT); 
}

void loop() {
  static byte once=1;
  
  if ( clk.hours()<5 ) {
    if (once) { //blink once at start
      digitalWrite(MYLED, HIGH);
      delay(1000);
      digitalWrite(MYLED, LOW);
      delay(1000);
      once=0;
    } else {
      digitalWrite(MYLED, HIGH);
    }
  } else {
    digitalWrite(MYLED, LOW);
    once=1;
  }
#if  defined(__AVR_ATtiny13__)
#warning "ATtiny 13 board selected, powersave turned on"
  clk.power_down(); //power down to preserve battery and wait millis update
#elif defined(ARDUINO_ARCH_AVR)
#warning "Atmel AVR board selected, idling powersave on"
  clk.power_idle(); //wait millis update
#endif  
  clk.sync();  

}
