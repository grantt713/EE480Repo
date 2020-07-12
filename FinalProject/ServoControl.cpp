#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;

#define PWM_SERVO     18      // this is PWM0, pin 12
#define BUTTON1   	27      // this is GPIO27, pin 13
#define BUTTON2   	22      // this is GPIO22, pin 13
#define RIGHT          74      // manually calibrated values
#define LEFT         76    // for the left, right and
#define CENTER        75      // center servo positions
bool HOME = false;         // sweep servo until button pressed

#define PWM_SERVO2     23 

void Start(void) {      // ISR on button press - not debounced
   cout << "Button 2 was pressed -- Stopping Servo." << endl;
		HOME=true;
}

int main() {                             // must be run as root
	int sec = 1000000;
   wiringPiSetupGpio();                  // use the GPIO numbering
  // pinMode(PWM_SERVO, PWM_OUTPUT);       // the PWM servo
  pinMode(PWM_SERVO2, OUTPUT);
   pinMode(BUTTON1, INPUT);          // the button input
   pinMode(BUTTON2, INPUT);          // the button input
   wiringPiISR(BUTTON2, INT_EDGE_RISING, &Start);
  // pwmSetMode(PWM_MODE_MS);              // use a fixed frequency
   //pwmSetRange(600);                    // 1000 steps
   //pwmSetClock(384);                     // gives 50Hz precisely

   cout << "Sweeping the servo until the button is pressed" << endl;
    while(HOME==false){
        for(int i=0; i<60; i++){
         digitalWrite(PWM_SERVO2, HIGH);
         usleep((1/120)*sec);
         digitalWrite(PWM_SERVO2, LOW);
	 }
	 usleep(3.15*sec);
    }
    digitalWrite(PWM_SERVO2, LOW);
 //  pwmWrite(PWM_SERVO, CENTER);
   
   cout << "Program has finished gracefully - servo centred" << endl;
   return 0;
}
