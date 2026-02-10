#!/bin/bash
if [ $# -eq 1 ]
then
	commande=$1
	fic=*.txt
	for i in 'ls /home/nmercier'
		do
		$commande $fic
	done
else
	echo "Vous devez passer 1 paramètre"
	exit 1
fi
