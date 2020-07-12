# Import libraries
import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

# Set GPIO23 as an output, and set servo1 as pin 11 as PWM
GPIO.setup(23,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(17,GPIO.OUT)
servo1 = GPIO.PWM(17,0.3) # Note pwm of 0.3Hz at GPIO17
Button1 = 16
Button2 = 22
GPIO.setup(Button1, GPIO.IN) # Pushbutton 1 as input
GPIO.setup(Button2, GPIO.IN) # Pushbutton 2 as input

global Standby
global Seconds

Standby = True
    
def Start(ev=None):
    
    servo1.start(0)
    duty = 1
    servo1.ChangeDutyCycle(duty)

    for minutes in range(0,6):
        print("Minutes Passed: %s" %minutes)
        for Seconds in range(0,59):
            GPIO.add_event_detect(Button2, GPIO.RISING, callback=Stop, bouncetime=300)
            time.sleep(1)
        GPIO.output(23, GPIO.HIGH)
        time.sleep(0.05)
        GPIO.output(23, GPIO.LOW)
        time.sleep(0.05)
        
    print("minute 6")

    servo1.stop()
    GPIO.cleanup()
    Standby=False
    print ("Exiting Program")    

def Stop(ev=None):
    print("Resetting Clock + LEDs")
    Reset = 60-Seconds
    for i in range(0,Seconds):
        time.sleep(1)
    servo1.stop()
    GPIO.cleanup()
    Standby=False
    print("Exiting Program")
    

GPIO.add_event_detect(Button1, GPIO.RISING, callback=Start, bouncetime=300)
    
print("If in Standby, Press Button 1 to Begin")
while(Standby==True):
    time.sleep(1)
