#include <stdio.h>
#include <stdlib.h>

struct Vecteur{
	int * tab;
	int taille;
};
typedef struct Vecteur Vecteur;

void initialiser_vecteur(Vecteur * v){
	v->tab = NULL;
	v->taille = 0;
}

void ajouter_vecteur(Vecteur * v, int elt){
	v->tab = realloc(v->tab, (v->taille+1) * sizeof(int));
	v->tab[v->taille] = elt;
	v->taille = v->taille+1;
}

void liberer_vecteur(Vecteur * v){
	free(v->tab);
	v->tab = NULL;
	v->taille = 0;
}

void afficher_vecteur(Vecteur v){
	for (int i = 0 ; i < v.taille ; i++){
		printf("%d ; ", v.tab[i]);
	}
	printf("\n");
}

void supprimer_dernier_vecteur(Vecteur *v){
	if (v->taille > 1){
		v->tab = realloc(v->tab, (v->taille -1) * sizeof(int));
		v->taille = v->taille - 1;
	}
	if (v->taille == 1){
		liberer_vecteur(v);
	}
}

void ajouter_position_vecteur(Vecteur * v, int pos, int elt){
	if (pos >= 0 && pos <= v->taille){
		v->tab = realloc(v->tab, (v->taille+1)*sizeof(int));
		v->taille = v->taille + 1;
	}
	for (int i = v->taille -1; i > pos ; i--){
		v->tab[i] = v->tab[i-1];
	}
	v->tab[pos] = elt;
	
}
void supprimer_occurrences_vecteur(Vecteur *v, int elt) {
    int j = 0;
    for (int i = 0; i < v->taille; i++) {
        if (v->tab[i] != elt) {
            v->tab[j] = v->tab[i];
            j++;
        }
    }
    v->taille = j;
    v->tab = realloc(v->tab, v->taille * sizeof(int));
}

int main(){
	Vecteur v;
	initialiser_vecteur(&v);
	
	ajouter_vecteur(&v, 0);
	ajouter_vecteur(&v, 1);
	ajouter_vecteur(&v, 2);
	ajouter_vecteur(&v, 3);
	supprimer_dernier_vecteur(&v);
	afficher_vecteur(v);
	ajouter_vecteur(&v, 4);
	afficher_vecteur(v);
	ajouter_position_vecteur(&v, 3, 3);
	afficher_vecteur(v);
	ajouter_vecteur(&v, 4);
	ajouter_vecteur(&v, 4);
	ajouter_vecteur(&v, 4);
	ajouter_vecteur(&v, 4);
	afficher_vecteur(v);
	supprimer_occurrences_vecteur(&v, 4);
	
	
	afficher_vecteur(v);
	return 0;
}
