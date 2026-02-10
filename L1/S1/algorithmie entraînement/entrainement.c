#include <stdio.h>
#define TAILLE 5

void afficher_tableau(int * tab, int taille){
	for (int i = 0 ; i<taille ; i++){
		printf("[%d]", tab[i]);
	}
	printf("\n");
	
}

void modifier_entier(int * val){
	*val = (*val)*2;
}

int main(){
	int a = 5;
	modifier_entier(&a);
	printf("%d\n", a);
	int tableau[TAILLE] = {0, 1, 2, 3, 4};
	afficher_tableau(tableau, TAILLE);
	return 0;
} 

