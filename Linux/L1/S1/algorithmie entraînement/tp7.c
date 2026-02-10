#include <stdio.h>
#include <stdlib.h>
#define NB_JOURS 7

int minimum(int * tab, int taille){
	int min = tab[0];
	for (int i = 0 ; i < taille ; i++){
		if (tab[i] < min) {
			min = tab[i];
		}
	}
	return min;
}

void afficher_tableau(int * tab, int taille){
	printf("affichage tableau : ");
	for (int i = 0; i<taille ; i++){
		printf("%d ; ", tab[i]);
	}
	printf("\n");
}

int rechercher_premiere_occ(int * tab, int taille, int val){
	int occ = -1;
	int i = 0;
	while (occ == -1){
		if (tab[i] == val){
			occ = i;
		}
		i++;
	}
	return occ;
}

int est_trie(int * tab, int taille){
	int tri = 1;
	int i = 0;
	while (tri == 1 && i < taille-1){
		if (tab[i+1] < tab[i]){
			tri = 0;
		}
		i++;
	}
	return tri;
}

void inverser(int * tab, int taille){
	for (int i = 0; i<taille/2 ; i++){
		int tmp = tab[i];
		tab[i] = tab[taille-1-i];
		tab[taille-1-i] = tmp;
	}
	afficher_tableau(tab,taille);
}

void difference_temperature(int * tab1, int * tab2){
	for (int i = 0 ; i<NB_JOURS-1 ; i++){
		int difference = tab1[i+1] - tab1[i];
		tab2[i] = difference;
	}
}


int main(){
	/* exercice 1 */
	int tableau[5] = {0,1,2,3,4};
	int mini = minimum(tableau,5);
	printf("Le minimum du tableau est : %d \n", mini);
	
	/* exercice 2 */
	afficher_tableau(tableau,5);
	
	/* exercice 3 */
	#define val_a_rechercher 2
	int occ_de_moins_trois = rechercher_premiere_occ(tableau,5,val_a_rechercher);
	printf("La première occurence de la valeur %d dans le tableau est à l'indice %d\n", val_a_rechercher, occ_de_moins_trois);
	
	/* exercice 4 */
	int tri1 = est_trie(tableau, 5);
	printf("Le tri du tableau est égal à %d\n", tri1);
	
	/* exercice 5 */
	inverser(tableau,5);
	afficher_tableau(tableau,5); /*preuve que ça modifie bien le tableau hors de la procédure.*/
	
	/* exercice 6 */
	
	int temperature[NB_JOURS]={-1,8,9,20,5,4,2};
	int tab2[NB_JOURS-1] = {0};
	difference_temperature(temperature, tab2);
	afficher_tableau(tab2, NB_JOURS-1);
	
	
	
	return 0;
}
