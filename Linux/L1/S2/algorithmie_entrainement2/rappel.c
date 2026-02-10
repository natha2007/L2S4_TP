#include <stdio.h>

int* trierListe(int* liste, int taille){
	for (int i=0;i<taille;i++){
		liste[i] = liste[taille-1-i];
	}
	return liste;
}

int main(){
	int liste[] = {1,2,3,4,5};
	int n = sizeof(liste)/sizeof(liste[0]);
	int newList[5];
	newList = trierListe(liste, 5);
	printf("test\n");
	for (int i =0;i<n;i++){
		printf("%d\n", newList[i]);
	}
	return 0;
}
