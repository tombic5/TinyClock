# TinyClock
Very lightweight software only library for scheduling jobs in hours, minutes, etc for Arduino.

Software Clock that reads millis() function and creates 24H clock with  values of hours, minutes, seconds and days. That makes easy to schedule daily/hourly etc. repeating tasks without all that math with millis(). Library is very small and optimized for tiny AVRs with limited Flash and RAM.

Main features:
* seconds, minutes, hours in 24 hours "clock" for time checking
* simple "formatted" output for hours and minutes in one integer (hhmm format)
* stopwatch and downcounting timer with seconds resolution for interval checking
* very lightweight - only 200-500Bytes flash + 14Bytes RAM for "clock"
* day counter (not resettable)
* clocks will survive millis() overflow
* needs no external RTC 
* compatible with classic AVR Arduino, [MicroCore](https://github.com/MCUdude/MicroCore) and [TinyCore](https://github.com/SpenceKonde/ATTinyCore) Boards

# How to install

Download as .zip file and follow [this instructions.](https://www.arduino.cc/en/guide/libraries#toc4) part "Importing a .zip Library"

