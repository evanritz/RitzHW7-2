// cutup implementation
// derek_LED.cpp
//
// Added blink function
// pass num of blinks 
//
// Written by Evan

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// Added for sleep function
#include <unistd.h>

#include "derek_LED.h"

using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

LED::LED(int number){
   this->number = number;
   // much easier with C++11 using to_string(number)
   ostringstream s;    // using a stream to contruct the path
   s << LED_PATH << number;   //append LED number to LED_PATH
   path = string(s.str());    //convert back from stream to string
}

void LED::writeLED(string filename, string value){
   ofstream fs;
   fs.open((path + filename).c_str());
   fs << value;
   fs.close();
}

void LED::removeTrigger(){
   writeLED("/trigger", "none");
}

void LED::turnOn(){
   cout << "Turning LED" << number << " on." << endl;
   removeTrigger();
   writeLED("/brightness", "1");
}

void LED::turnOff(){
   cout << "Turning LED" << number << " off." << endl;
   removeTrigger();
   writeLED("/brightness", "0");
}

void LED::flash(string delayms = "50"){
   cout << "Making LED" << number << " flash." << endl;
   writeLED("/trigger", "timer");
   writeLED("/delay_on", delayms);
   writeLED("/delay_off", delayms);
}

void LED::outputState(){
   ifstream fs;
   fs.open( (path + "/trigger").c_str());
   string line;
   while(getline(fs,line)) cout << line << endl;
   fs.close();
}

// Added blink function
void LED::blink(int num){
    for (int i = 0; i < num; i++){
        writeLED("/brightness", "1");
        sleep(1);
        writeLED("/brightness", "0");
        sleep(1);
    } 
}

LED::~LED(){
   cout << "destroying the LED with path: " << path << endl;
}


