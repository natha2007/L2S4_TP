#include <stdio.h>

void somme_produit(int a, int b, int * somme, int * produit){
	*produit = a * b;
	*somme = a + b;
}


int main(){
	int somme1 = 0;
	int produit1 = 0;
	somme_produit(5,5,&somme1,&produit1);
	printf("somme : %d, produit : %d \n", somme1, produit1);
	
	return 0;
}
