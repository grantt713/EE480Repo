#!/bin/bash
while :
do
	echo 1 > /sys/class/leds/led0/brightness
	echo 0 > /sys/class/leds/led1/brightness
sleep 1
	echo 0 > /sys/class/leds/led0/brightness
	echo 1 > /sys/class/leds/led1/brightness
sleep 1

done
