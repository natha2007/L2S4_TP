#!/bin/bash  
for ligne in `cat /etc/group`
	do
		ngrp=`echo $ligne | cut -f 1 -d :`
		echo "$ngrp" 
done

# la 1ere ligne indique où se trouve le programme bash puisque c'est le langage qu'on
# utilise pour notre shell, sha bang -> Cette ligne permet de s'assurer que le script est
# bien exécuté avec le bon shell.

# la deuxieme ligne est une boucle for qui va parcourir l'affichage (cat) de 
# /etc/group (un chemin dans l'arborescence des fichiers) "ligne" est une variable qui 
# va prendre successivement les valeurs du cat

# la 3eme ligne on initialise une variable ngrp à laquelle on affecte le résultat d'une commande :
# la commande permet d'afficher la variable ligne, qui va changer à  
# chaque itération de la boucle (echo $ligne) puis la commande cut va supprimer de 
# l'affichage du champ 1 (-f 1) délimités (-d) par le délimiteur de champ ":", 
# En gros dans chaque ligne, on supprime ce qu'il y a à partir du premier caractère ":" 

#la 4eme ligne affiche donc la variable ngrp (pour chaque itération de la boucle),
# cette variable contient la commande expliquée juste avant
