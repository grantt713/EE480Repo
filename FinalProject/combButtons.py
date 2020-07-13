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
global Terminate	# create variable to keep program running until end or terminated
Terminate=False


def Stop(ev=None):	# callback function to align servo and clear LEDs
	Terminate = True	# declare the program to be terminated
	print("Resetting Clock + LEDs")
	ResetC = 60-Seconds		# how long servo needs to run to get back to top
	for i in range(0,ResetC):	#allows servo to run fo this time
		time.sleep(1)
	servo1.stop()
	ResetL = 8-Minutes		# counts how many phases the 3 bits have left
	for t in range(0,ResetL):	# pulses flip flops to reset at 000
		GPIO.output(23, GPIO.HIGH)
		time.sleep(0.1)
		GPIO.output(23, GPIO.LOW)
		time.sleep(3)
	GPIO.cleanup()		# clear all GPIO pins to avoid change
    
    

# detect when the second button passes a signal, then run Stop callback
GPIO.add_event_detect(Button2, GPIO.RISING, callback=Stop, bouncetime=300)



print("Press Button 1 to begin. You have 60 seconds.")


# program begins when button 1 is pushed
Start = GPIO.wait_for_edge(Button1, GPIO.RISING, timeout=60000)


if Start is None:	# gives message if button is never pushed
    print("Timeout Occurred")
else:	# when button 1 is pushed do this
    
	servo1.start(0)
	duty = 1
	servo1.ChangeDutyCycle(duty)

	print("Minutes Passed: 0")
	for Minutes in range(1,9):	# loop for 8 minutes
        
		for Seconds in range(0,59):	# wait for 60 seconds
			if(Terminate==False):	# only waits if button 2 not pushed
				time.sleep(1)
			else:
				break
		if(Terminate==False):	# if button 2 not pushed, send pulse to flip flops
			print("Minutes Passed: %s" %Minutes)
			GPIO.output(23, GPIO.HIGH)
			time.sleep(0.2)
			GPIO.output(23, GPIO.LOW)
		else:
			break
        
        
print ("Exiting Program")    

GPIO.cleanup() # clean up all LEDs if the program made it through with no issues
