#!/bin/bash

if [ $# -gt 2  ]
then
	echo "il faut 2 paramètres maximum"
	exit 1
fi

if ! [[ -d $2 ]]
then 
	echo "Le repertoire passé en paramètre n'est pas un répertoire"
	exit 2
fi

if ! [[ -e $2 ]]
then
	echo "Le répertoire passé en paramètre n'existe pas"
	exit 3
fi

if [ $# -eq 1 ]
then
	rep=`pwd`
else
	rep="$2"
fi	

ext="$$1"
for i in 'ls $rep'
do
	if [ $i =~ $ext ]
	then
		mv $i "$i.bak"
	fi
done
