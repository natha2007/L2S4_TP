#!/bin/bash
let "t=0"
while [ $t -le 50 ]
do
let "t=t+1"
date +"%T" 
sleep 2
done
