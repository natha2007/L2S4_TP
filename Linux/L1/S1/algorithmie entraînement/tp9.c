#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Matrice {
	int ** tab;
	int nb_lignes;
	int nb_cols;
};
typedef struct Matrice Matrice;

void initialiser_matrice(Matrice * m){
	m->tab = NULL;
	m->nb_lignes = 0;
	m->nb_cols = 0;
}

void allouer_matrice(Matrice * m, int nbl, int nbc){
	m->tab = malloc(nbl * sizeof(int *));
	for (int i = 0 ; i < nbl ; i++){
		m->tab[i] = malloc(nbc * sizeof(int));
	}
	m->nb_lignes = nbl;
	m->nb_cols = nbc;
}

void liberer_matrice(Matrice * m){
	if (m->tab != NULL){
		for (int i=0 ; i < m->nb_lignes ; i++){
			free(m->tab[i]);
		}
		free(m->tab);
		initialiser_matrice(m);
	}
}

void remplir_aleatoire_matrice(Matrice m){
	for (int i = 0; i < m.nb_lignes ; i++){
		for (int j = 0; j < m.nb_cols ; j++){
			m.tab[i][j] = rand()%101;
		}
	}
}

void afficher_matrice(Matrice m){
	for (int i = 0; i < m.nb_lignes ; i++){
		for (int j = 0; j < m.nb_cols ; j++){
			printf("%d ; ", m.tab[i][j]);
		}
		printf("\n");
	}
	
}

void ajouter_matrice(Matrice m1, Matrice m2, Matrice m3){
	for (int i = 0; i < m1.nb_lignes ; i++){
		for (int j = 0; j < m1.nb_cols ; j++){
			m3.tab[i][j] = m2.tab[i][j] + m1.tab[i][j];
		}
	}
}

void ajouter_matrice_v2(Matrice m1, Matrice m2){
	Matrice m3;
	initialiser_matrice(&m3);
	allouer_matrice(&m3, m2.nb_lignes, m2.nb_cols);
	for (int i = 0; i < m1.nb_lignes ; i++){
		for (int j = 0; j < m1.nb_cols ; j++){
			m3.tab[i][j] = m2.tab[i][j] + m1.tab[i][j];
		}
	}
}

	


int main(){
	srand(time(NULL));
	
	Matrice m;
	Matrice m2, m3;
	initialiser_matrice(&m);
	initialiser_matrice(&m2);
	initialiser_matrice(&m3);
	allouer_matrice(&m, 3, 4);
	allouer_matrice(&m2, 3, 4);
	allouer_matrice(&m3, 3, 4);
	remplir_aleatoire_matrice(m);
	remplir_aleatoire_matrice(m2);
	printf("matrice m\n");
	afficher_matrice(m);
	printf("matrice m2\n");
	afficher_matrice(m2);
	ajouter_matrice(m,m2,m3);
	printf("matrice m3\n");
	afficher_matrice(m3);
	
	/* aide pointeur naoufel */
	int a = 20;
	int * n = &a;
	printf("%d %p %p %p\n", *n, n, &n, &a);
	/* fin */
	
	
	liberer_matrice(&m);
	return 0;
}
