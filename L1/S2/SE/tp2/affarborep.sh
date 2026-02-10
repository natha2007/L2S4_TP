#!/bin/bash

if [ $# -eq 1 ]
then
	cd $1
fi



while [ `pwd` != "/" ]
do
	pwd 
	echo " "
	ls
	cd ..
	echo " "
done
