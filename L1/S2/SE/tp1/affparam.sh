#!/bin/bash
if [ $# -eq 0 ]
then
	echo "aucun"
	exit 1 #sortie du script avec une erreur à 1
fi


let="i=1"
while [ $1 ]
do
	echo "Valeur du paramètre numéro $i : $1"
	shift #decalage des paramètres, $1 a mtn le contenu de $2
	let="i=i+1" #la variable i augmente de 1
done 

