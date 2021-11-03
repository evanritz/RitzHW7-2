// cutup interface 
// derek_LED.h
//
// Written by Evan

#ifndef DEREK_H
#define DEREK_H

#include <string>
using namespace std;

class LED{
   private:
      string path;
      int number;
      virtual void writeLED(string filename, string value);
      virtual void removeTrigger();
   public:
      LED(int number);
      virtual void turnOn();
      virtual void turnOff();
      virtual void flash(string delayms);
      virtual void outputState();
      virtual void blink(int num);
      virtual ~LED();
};

#endif
