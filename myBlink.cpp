// myBlink.cpp
//
// This program takes 3 argument to control LEDs
// arg1=command arg2=lednumber arg3=operations
// For on, off, and status arg3 value does not matter
//
// Edited by Evan

#include <iostream>
#include "derek_LED.h"

using namespace std;

int main(int argc, char* argv[]){
   if(argc != 4){
	cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash or status" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;

   string cmd(argv[1]);
    
   int led_num = atoi(argv[2]);
   int op_num = atoi(argv[3]);

   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };

   LED selected_led = leds[led_num];

    if(cmd=="on") {
        selected_led.turnOn();
    }
    else if(cmd=="off") {
        selected_led.turnOff();
    }
    else if(cmd=="flash") {
        selected_led.flash(argv[3]); //default is "50"
    }
    else if(cmd=="status")
    {
        selected_led.outputState();
    }
    else if(cmd=="blink")
    {
         cout << "Blinking LED" << led_num << " " << op_num << " times" << endl;
         selected_led.blink(op_num);
    }
    else{ cout << "Invalid command!" << endl; }

   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
