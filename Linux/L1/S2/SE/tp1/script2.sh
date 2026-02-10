#!/bin/bash
nfic=personnes.txt
read -p "Précisez le nombre de personnes à saisir : " nbp
if [ $nbp -gt 0 ]
then
	i=0
		while [ $i -lt $nbp ]
		do
			read -p "Nom de la personne : " nom
			read -p "Prénom de la personne : " prenom
			read -p "Adresse de la personne : " adresse
			read -p "Email de la personne : " email
			read -p "Telephone de la personne : " telephone
			echo "$nom $prenom;$adresse;$email;$telephone" >> $nfic #redirige l'affichage vers la variable nfic càd le fichier personnes.txt
			let "i=i+1" #obligatoire pour un calcul (let)
		done
else
	echo "Nombre de personnes à saisir incorrect"
	exit 1
fi

# de premier abord, le script demande à l'utilisateur de remplir des informations sur
# un nombre de personnes voulus et enregistre chaque info dans différentes lignes
# séparées selon les différentes personnes par des ";"

#1ere ligne : on affecte un nom de fichier (personnes.txt) à la variable nfic
#2eme ligne  récupère le contenu d'une saisie de l'utlisateur (read)
# en lui affichant un message (-p "Précisez le nombre...) et en enregistrant le résultat
# dans la variable nbp
#3eme ligne : on a une condition : si le contenu de ma variable ($nbp) est plus grand
# (-gt = greather than) que 0 : on initialise i à 0 (i=0)
# 5eme ligne : Tant que (while) la variable i ($i) est plus petite (-lt = lower than)
# que le contenu de la variable nbp (le nombre de personnes à saisir), 
# faire : récupérer le contenu d'une saisie en affichant le messsage "nom de la personne :" et en affectant 
# le résultat à la variable nom -> pareil pour prenom, adresse, email, telephone
# ensuite on affiche le contenu des variables nom, prenom... séparés par des ";" et on redirige
# l'affichage vers la variable nfic (personnes.txt)
# ensuite on incrémente i (let "i=i+1")
# ensuite si la condition du while n'est pas remplie on fait ce qu'il y a dans le else : on affiche
# le message "Nombre de personnes à saisir incorrect"
# Puis on quitte le script (exit 1)
