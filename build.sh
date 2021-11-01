#!/bin/bash
#the following script builds myBlink application which takes input parameters of command string on, off
#flash, status, or blink as well as LED number and number of blinks when the "blink" command is invoked
#example invocation: ./myBlink blink 3 4
#when invoking other commands, include two int parameters to avoid errors:
#example invocatio: ./myBlink on 0 0
echo building myBlink.
g++ myBlink.cpp derek_LED.cpp -o myBlink
echo done building.
