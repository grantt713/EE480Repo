#!/bin/sh
INPUT_STRING=HELLO
input_string=hello
while [ "$input_string" != "bye" ]
do
	echo "Please type something in (bye to quit)"
	read input_string
	echo "You typed: $input_string"
done
