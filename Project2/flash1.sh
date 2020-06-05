#!/bin/bash
echo /sys/class/leds/led0/trigger

while :
do

echo 1 > /sys/class/leds/led0/brightness
sleep 1

echo 0 > /sys/class/leds/led0/brightness
sleep 1

done

