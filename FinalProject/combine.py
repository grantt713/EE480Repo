# Import libraries
import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(FALSE)

# Set GPIO23 as an output, and set servo1 as pin 11 as PWM
GPIO.setup(23,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(17,GPIO.OUT)
servo1 = GPIO.PWM(17,0.3) # Note pwm of 0.3Hz at GPIO17

servo1.start(0)
duty = 1
servo1.ChangeDutyCycle(duty)

for minutes in range(0,6):
	print("minute %s" %minutes)
	for seconds in range(0,57):
		time.sleep(1)
	GPIO.output(23, GPIO.HIGH)
	time.sleep(0.05)
	GPIO.output(23, GPIO.LOW)
	time.sleep(0.05)
	
print("minute 6")

servo1.stop()
GPIO.cleanup()
print ("Goodbye")		
