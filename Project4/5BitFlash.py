import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

BIT1 = 24 # These are variables redefining IO pins being used
BIT2 = 25
BIT3 = 12
BIT4 = 20
BIT5 = 21

GPIO.setup(BIT1, GPIO.OUT, initial=GPIO.LOW) # initializing all LEDs as OFF
GPIO.setup(BIT2, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(BIT3, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(BIT4, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(BIT5, GPIO.OUT, initial=GPIO.LOW)

GPIO.output(BIT1, GPIO.HIGH) # turn all LEDs ON for 2 seconds
GPIO.output(BIT2, GPIO.HIGH)
GPIO.output(BIT3, GPIO.HIGH)
GPIO.output(BIT4, GPIO.HIGH)
GPIO.output(BIT5, GPIO.HIGH)
time.sleep(2)

GPIO.output(BIT1, GPIO.LOW) #turn all LEDs OFF for 2 seconds
GPIO.output(BIT2, GPIO.LOW)
GPIO.output(BIT3, GPIO.LOW)
GPIO.output(BIT4, GPIO.LOW)
GPIO.output(BIT5, GPIO.LOW)
time.sleep(2)

