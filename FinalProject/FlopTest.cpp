#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;

#define LED_GPIO      23      // this is GPIO17, Pin 11



int main() {                             // must be run as root
   wiringPiSetupGpio();                  // use the GPIO numbering
   pinMode(LED_GPIO, OUTPUT);            // the LED
   digitalWrite (LED_GPIO, LOW);         // LED is off
   int sec = 1000000;				// make usleep simpler


   cout << "ON..." << endl;      
   digitalWrite (LED_GPIO, HIGH);         // LED is off
   usleep(0.05*sec);                          // sleep for 1 second

   digitalWrite (LED_GPIO, LOW);         // LED is off
   cout << "OFF..." << endl << endl;
   usleep(1*sec);                          // sleep for 1 second

   return 0;                             // program ends after 10s
}
