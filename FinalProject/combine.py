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
Button1 = 4
Button2 = 22
GPIO.setup(Button1, GPIO.IN) # Pushbutton 1 as input
GPIO.setup(Button2, GPIO.IN) # Pushbutton 2 as input

global Seconds
global Minutes
global Terminate
Terminate=False

def Stop(Terminate):
	Terminate = True
	print("Resetting Clock + LEDs")
	
	ResetC = 60-Seconds
	for i in range(0,ResetC):
		time.sleep(1)
		servo1.stop()
		
	ResetL = 8-Minutes
	for t in range(0,ResetL):
		GPIO.output(23, GPIO.HIGH)
		time.sleep(0.2)
		GPIO.output(23, GPIO.LOW)
		time.sleep(2)
	return Terminate


print("Press Button 1 to begin. You have 60 seconds.")

def Start(Terminate):
	GPIO.add_event_detect(Button2, GPIO.RISING, callback=Stop, bouncetime=300)
	servo1.start(0)
	duty = 1
	servo1.ChangeDutyCycle(duty)

	print("Minutes Passed: 0")
	for Minutes in range(1,9):
        
		for Seconds in range(0,59):
			if(Terminate==False):
				time.sleep(1)
				
		if(Terminate==False):
			print("Minutes Passed: %s" %Minutes)
			GPIO.output(23, GPIO.HIGH)
			time.sleep(0.2)
			GPIO.output(23, GPIO.LOW)
			time.sleep(2)
		else:
			break
			
			

GPIO.add_event_detect(Button1, GPIO.RISING, callback=Start, bouncetime=300)

for i in range(0,59):
	time.sleep(1)

print ("Exiting Program")    

GPIO.cleanup()
