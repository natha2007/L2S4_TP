#!/bin/bash
if [ $# -lt 2 ]
then
	echo "Vous devez saisir au moins 2 paramètres (un repertoire
	destination et un ou plusieurs répertoires sources)"
	exit 1
fi
nomrp=$1
shift
if [ -e $nomrp ]
then
	read -p "Le repertoire $nomrp existe déjà. Voulez vous le remplacer? O pour oui, N pour non : " reponse
	if [ $reponse = "O" ]
	then
		rm -rf $nomrp
	else
		echo "Abandon : le repertoire destination $nomrp existe déjà et ne doit pas être écrasé"
	exit 1
	fi
fi
mkdir $nomrp # on crée le répertoire $nomrp

while [ $1 ] # tant qu'il y a des paramètres 
do
	if [ -e $1 ] #si le fichier/répertoire $1 existe
	then
		if [ -d $1 ] #si $1 est un répertoire
		then
			nomfics=$1/*.txt # dans mon fic on a le nom du répertoire/*.txt
			cp $nomfics $nomrp # on copie les fichiers txt du répertoire $1 vers le répertoire $nomrp
		else
			echo "Le repertoire source $1 n'est pas un repertoire"
		fi
	else
		echo "Le repertoire source $1 n'existe pas"
	fi
	shift # décalage de paramètre
done
echo "Le repertoire de destination $nomrp contient les fichiers "`ls $nomrp`

# 1ere ligne : si la variable $# (nombre de paramètres associés au script) 
# est inférieure à 2 : afficher le message "vous devez saisir... sources"
# fi -> fin du if
# shift (décalage de paramètre) -> si contenu de la variable nomrp (1er paramètre) existe (-e) alors afficher un message
# et récupérer contenue de la saisie dans variable reponse, si la réponse est 0, alors :
# Efface le répertoire nomrp de manière récursive en ignorant les fichiers et paramètres inexistants
# sinon afficher le message "abandon..." et quitter le script
# ensuite on crée le répertoire (mkdir) $nomrp 



# NB : $0 -> .:script3.sh, $1 : premier paramètre,... $9 : 9eme paramètre, $10(existe pas -> si plus de 
#10 paramètres, les paramètres prennent successivement les variables $1,2,3...)
