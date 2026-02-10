#!/bin/bash
if [ $# -eq 2 ]
then
	nomrep=$1
	droit=$2
	ls -l | grep $droit
else 
	echo "Vous devez passer 2 paramètres"
	exit 1
fi
