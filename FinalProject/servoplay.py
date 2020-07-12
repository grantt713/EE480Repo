# Import libraries
import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BCM)

# Set pin 11 as an output, and set servo1 as pin 11 as PWM
GPIO.setup(17,GPIO.OUT)
servo1 = GPIO.PWM(17,0.3) # Note 11 is pin, 50 = 50Hz pulse

#start PWM running, but with value of 0 (pulse off)
servo1.start(0)
print ("Waiting for 2 seconds")
time.sleep(2)

#Let's move the servo!
print ("Rotating 180 degrees in 10 steps")

# Define variable duty
duty = 1
servo1.ChangeDutyCycle(duty)

# Wait a couple of seconds
time.sleep(60)


#Clean things up at the end
servo1.stop()
GPIO.cleanup()
print ("Goodbye")
