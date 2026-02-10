#include <stdio.h>
#include <stdlib.h>

struct Objet{
	int ref;
	int stock;
};
typedef struct Objet Objet;

struct Entreprise{
	Objet * tab;
	int taille;
};
typedef struct Entreprise Entreprise;

enum Feu{
	int a = 5;
	int b;
	int c;
};
typedef enum Feu Feu;

Objet creer_objet(int ref, int stock){
	Objet o;
	o.ref = ref;
	o.stock = stock;
	return o;
}

void afficher_objet(Objet o){
	printf("Objet ref : %d ; stock : %d\n",o.ref,o.stock);
}

void initialiser_entreprise(Entreprise * e){
	e->tab = NULL;
	e->taille = 0;
}

Objet* rechercher_objet(Entreprise e, Objet o){
	Objet * ptr = NULL;
	int i = 0;
	while(i < e.taille && ptr == NULL){
		if (e.tab[i].ref == o.ref){
			ptr = &e.tab[i];
		}
		i++;
	}
	return ptr;
}

void ajouter_objet_fin(Objet o, Entreprise * e){
	e->taille = e->taille + 1;
	e->tab = realloc(e->tab, (e->taille )*sizeof(Objet));
	e->tab[e->taille-1] = o;
}

void ajouter_objet(Objet o, Entreprise * e){
	Objet * obj = rechercher_objet(*e, o);
	if (obj != NULL){
		obj->stock = obj->stock + o.stock;
	} else {
		ajouter_objet_fin(o, e);
	}
}

void afficher_entreprise(Entreprise e){
	
}

int main(){
	Feu f;
	Objet obj = creer_objet(5,5);
	afficher_objet(obj);
	printf("%d \n", f.b);
	return 0;
}
