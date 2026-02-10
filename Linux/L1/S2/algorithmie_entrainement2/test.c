#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
typedef struct{
	int lg;
	int debut;
	int fin;
	element tab[MAX];
}File_tab;

int successeur(int i){
	if (i == MAX-1) return 0;
	else return i+1;
}

int file_vide(File_tab f){
	return (f.lg==0);
}

int file_saturee(File_tab f){
	return (f.lg==MAX);
}

void init_file(File_tab *f){
	f->lg = 0;
	f->debut = -1;
	f->fin = -1;
}

void ajouter(File_tab *f, element e){
    if (file_saturee(*f)) {
        printf("Impossible, la file est pleine \n");
    } else {
        if (file_vide(*f)) {  // Si la file est vide, on initialise debut et fin
            f->debut = 0;
            f->fin = 0;
        }
        f->tab[f->fin] = e;
        f->fin = successeur(f->fin);  // On avance fin
        f->lg++;
    }
}



void supprimer(File_tab *f, element *e){
    if (file_vide(*f)){
        printf("Impossible, la file est vide \n");
    } else {
        *e = f->tab[f->debut];  // Stocker l'élément supprimé

        if (f->lg == 1) {  // Si on supprime le dernier élément, on réinitialise la file
            f->debut = -1;
            f->fin = -1;
        } else {
            f->debut = successeur(f->debut);  // Avancer l'indice de début
        }

        f->lg--;
    }
}


void afficher_tableau(File_tab f){
	printf("|");
	for (int i=0; i<MAX; i++){
		printf("%d|", f.tab[i]);
	}
	printf("\n");
}

int main(){
	File_tab f;
	element x;
	
	afficher_tableau(f);
	
	init_file(&f);    // f.lg = 0, f.debut = -1, f.fin = -1
	afficher_tableau(f);
	
	ajouter(&f, 10);  // f.lg = 1, f.debut = 0, f.fin = 1
	afficher_tableau(f);
	
	ajouter(&f, 20);  // f.lg = 2, f.debut = 0, f.fin = 2
	afficher_tableau(f);
	
	supprimer(&f, &x);  // x = 10, f.lg = 1, f.debut = 1, f.fin = 2
	afficher_tableau(f);
	
	supprimer(&f, &x);  // x = 20, f.lg = 0, f.debut = 2, f.fin = 2
	afficher_tableau(f);

	supprimer(&f, &x);  // Affiche "Impossible la file est vide"
	afficher_tableau(f);
	
}
