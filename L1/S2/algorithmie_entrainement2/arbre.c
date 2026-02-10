#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{
	int valeur;
	struct maillon *gauche;
	struct maillon *droite;
} maillon;

maillon* creationMaillon(int valeur){
	maillon * nouveau = (maillon *) malloc (sizeof(maillon));
	nouveau->valeur = valeur;
	nouveau->gauche = NULL;
	nouveau->droite = NULL;
	return nouveau;
}

maillon * ajout(maillon * racine, int valeur){
	if (racine == NULL) return creationMaillon(valeur);
	if(valeur < racine->valeur){
		racine->gauche = ajout(racine->gauche, valeur);
	}
	if (valeur > racine->valeur){
		racine->droite = ajout(racine->droite, valeur);
	}
	return racine;
}

int estVide(maillon * racine){
	return (racine==NULL);
}

int taille(maillon * racine){
	if (racine == NULL) return 0;
	return 1 + taille(racine->gauche)+taille(racine->droite);
}

void parcoursPreOrdre(maillon * racine){
	if (racine != NULL){
		printf("%d", racine->valeur);
		parcoursPreOrdre(racine->gauche);
		parcoursPreOrdre(racine->droite);
	}
}

void parcoursOrdre(maillon * racine){
	if (racine != NULL){
		parcoursOrdre(racine->gauche);
		printf("%d", racine->valeur);
		parcoursOrdre(racine->droite);
	}
}

void parcoursPostOrdre(maillon * racine){
	if (racine != NULL){
		parcoursPostOrdre(racine->gauche);
		parcoursPostOrdre(racine->droite);
		printf("%d", racine->valeur);
	}
}

int main(){
	maillon* racine = NULL;
	int vide = estVide(racine);
	printf("Maillon vide ou pas vide : %d\n", vide);
	// Insertion de valeurs dans l’arbre
	racine = ajout(racine, 6);
	racine = ajout(racine, 4);
	racine = ajout(racine, 8);
	racine = ajout(racine, 3);
	racine = ajout(racine, 5);
	racine = ajout(racine, 7);
	racine = ajout(racine, 9);
	
	int t = taille(racine);
	printf("La taille de l'arbre est : %d\n", t);
	
	printf("Parcours Pre Ordre : ");
	parcoursPreOrdre(racine);
	printf("\n");
	
	printf("Parcours Ordre : ");
	parcoursOrdre(racine);
	printf("\n");
	
	printf("Parcours Post Ordre : ");
	parcoursPostOrdre(racine);
	printf("\n");
	
	
	return 0;
}
