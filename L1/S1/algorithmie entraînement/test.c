#include <stdio.h>

void modifier_valeur(int n){
	n = n*2;
	printf("valeur dans la procédure sans pointeur : %d \n", n);
}

void modifier_par_pointeur(int * n){
	*n = (*n) * 2;
	printf("valeur dans la procédure par pointeur : %d \n", *n);
}

int main(){
	/* exercice 1.1 */
	
	int a = 20 ;
	modifier_valeur(a);
	printf("valeur après la procédure sans pointeur : %d \n", a);
	modifier_par_pointeur(&a);
	printf("valeur après la procédure avec pointeur : %d\n", a);
	modifier_par_pointeur(&a);
	printf("valeur après la procédure avec pointeur : %d\n", a);
	
	/* exercice 1.2 */
	
	int * ptr = &a;
	printf("Valeur du pointeur ptr : %p, adresse du pointeur ptr %p \n", ptr, &ptr);
	
	/* exercice 1.3 */
	
	printf("Valeur de l'entier pointé par le pointeur ptr : %d \n", *ptr);
	
	return 0;
}  
