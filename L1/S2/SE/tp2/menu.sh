#!/bin/bash
while [ 1 = 1 ]
do
echo"Ecrivez A pour Afficher la liste de tous les utilisateurs connectés"
echo "Ecrivez B pour afficher la liste des processus en cours"
echo "Ecrivez C pour afficher  l'utilisateur son nom, son UID, son GID, son TTY"
echo "Ecrivez D pour Permettre à l'utilisateur d'accéder à un shell où il pourra exécuter des
commandes"
echo "Ecrivez E pour quitter le script"
read reponse

pattern='[A-E]{,1}'
if ! [[ $reponse =~ pattern ]]
then 
	echo "la reponse doit être A,B,C,D ou E (en majuscule)"
	exit 1
fi

case $reponse in
	"A")
	who
	;;
	"B")
	ps -aef
	;;
	"C")
	who | grep `whoami`
	;;
	"D")
	bash
	;;
	"E")
	exit 1
esac
done
