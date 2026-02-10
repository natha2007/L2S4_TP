#!/bin/bash
if ! [[ -d $1 ]]
then 
	echo "le paramètre doit être un fichier"
	exit 1
fi 

if [ $# -eq 0 ]
then
	rep=$PWD
else
	rep=$1
fi

#pas complet en haut

for nomfichier in *
do
	echo "ancien nom : $nomfichier"
	echo $nomfichier > tmptxt
	nouveaunom=`tr ' ' '_'<tmptxt`
	echo "--Nouveau nom : $nouveaunom--"
	if [ "$nomfichier" != "$nouveaunom" ]
	then 
		mv "$nomfichier" "$nouveaunom"
	fi
done


#symbole='[ ]*'
#for i in $rep
	#do
	#if [ $i =~ $symbole ]
	#then
		#mv $i | awk '$1'
	#fi
#done



