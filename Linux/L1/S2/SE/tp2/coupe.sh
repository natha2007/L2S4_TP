#!/bin/bash
if ! [[ $# -eq 3 ]]
then
	echo "il faut 3 paramères"
	exit 1
fi

num='^[0-9]+$'
if ! [[ $2 =~ $num ]]
then
	echo "2eme paramètre doit être un entier"
	exit 2
fi

if ! [[ $3 =~ $num ]]
then
	echo "3eme paramètre doit être un entier"
	exit 3
fi

if [ $3 -lt $2 ]
then
	echo "le 2eme nombre doit être supérieur ou égal au 1er"
	exit 4
fi
fic="$1"
if ! [[ -e $fic ]]
then
	echo "le fichier $fic passé en paramètre n'existe pas"
	exit 5
fi

if ! [[ -f $fic ]]
then
	echo "Le fichier $fic passé en paramètre n'est pas un fichier"
	exit 6
fi

nblignes=`wc -l $fic | cut -d ' ' -f 1`
if [ $nblignes -ge $3 ]
then
	head -$3 $fic | tail +$2 
else
	echo "Le 2eme nombre ne doit pas être plus grand que le nombre de lignes du fichier"
	exit 7
fi
