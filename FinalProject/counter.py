# Import libraries
import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BCM)

# Set pin 11 as an output, and set servo1 as pin 11 as PWM
GPIO.setup(23,GPIO.OUT, initial=GPIO.LOW)

GPIO.output(23, GPIO.HIGH)
time.sleep(0.05)
GPIO.output(23, GPIO.LOW)
time.sleep(1)

print("Program Ended")

GPIO.cleanup()
