#!/bin/sh
echo "What is your name?"
read USER_NAME
echo "Alright, creating you a file called ${USER_NAME}_file"
touch "${USER_NAME}_file"
