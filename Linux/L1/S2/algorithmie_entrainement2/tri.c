#include <stdio.h>
#include <stdlib.h>

void tri_bulle(int tab, int taille){
	int i, j;
	int tmp;
	
	for (int i=0; i<taille; i++){
		for(int j=0; j<taille; i++){
			if tab[i] > tab[j] {
				tmp = tab[i]
				tab[i] = tab[j]
				tab[j] = tmp
			}
		}
	}
}


int main(){
	int tab[10] = {1, 3, 0, 9, 7, 5, 8, 2, 4, 6};
	printf("%d\n", tab[0]);
	return 0;
}


