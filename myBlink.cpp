/** Simple On-board LED flashing program - written by Derek Molloy
*    simple OOP  struture for the Exploring BeagleBone book
*
*    This program uses all four LEDS and can be executed in three ways:
*         makeLEDs on
*         makeLEDs off
*         makeLEDs flash  (flash at time delay intervals)
*         makeLEDs status (get the trigger status)
*
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include "derek_LED.h"

int main(int argc, char* argv[]){
   if(argc!=2){
	cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash, status or blink followed by an LED number and number of blinks" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   int LEDnum = atoi(argv[2]); 
   int BLINKnum = atoi(argv[3]);
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
   for(int i=0; i<=3; i++){
      if(cmd=="on")leds[i].turnOn();
      else if(cmd=="off")leds[i].turnOff();
      else if(cmd=="flash")leds[i].flash("100"); //default is "50"
      else if(cmd=="status")leds[i].outputState();
      else{ cout << "Invalid command!" << endl; }
   }
   if(cmd=="blink"){
	   leds[LEDnum].blink(BLINKnum);
   }
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}

