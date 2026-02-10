#include <stdio.h>
#include <stdlib.h>

#define LEN 54

//A écrire dans le petit cahier ?

//mot[i] = '\0' OU mot[i] = 0 pour vérifier que la chaine est finie
// gcc tp1.c -o prog && ./prog     :  ligne de commande pour lancer le programme s'il a pas d'erreur


// Exercice 1

//vérifie si une chaîne est un palindrome
int palindrome(char * chaine){
	int len = 0;
	while(chaine[len] != '\0')len++;
	
	int estPalindrome = 1;
	int i = 0;
	while (i<len/2 && estPalindrome){
		if (chaine[i] != chaine[len-1-i]) {
			estPalindrome = 0;
		}
		i++;
	}
	return estPalindrome;
}

void Exercice1(int argc, char*argv[]){
	printf("Exercice 1 :\n\n");
	if (argc < 2){
		printf("Vous devez saisir au moins un paramètre\n");
	} else {
		printf("Mot choisi : %s\n", argv[1]);
		printf("Est palindrome ? %d\n", palindrome(argv[1]));
	}
}

// Exercice 2
void Exercice2(int argc, char*argv[]){
	printf("\nExercice 2 :\n\n");
	if (argc < 2){
		printf("Vous devez saisir au moins un paramètre\n");
	} else {
		for (int i = 1; i < argc; i++){
			int len = 0;
			while(argv[i][len] != '\0')len++;
			printf("argument n %d = %s, longueur = %d\n", i, argv[i], len);
		}
	}
}

//Exercice 3 

typedef struct Matrice{
	int nb_lignes;
	int nb_col;
	int **m;
}Matrice;

Matrice alloue_matrice(int nb_lignes, int nb_col){
	Matrice mat;
	mat.nb_lignes = nb_lignes;
	mat.nb_col = nb_col;
	mat.m = malloc(nb_lignes * sizeof(int *));
	for (int i = 0;i<nb_lignes;i++){
		mat.m[i] = malloc(nb_col * sizeof(int));
		for (int j = 0; j< nb_col;j++){
			mat.m[i][j] = 0;
		}
	}
	return mat;
}

void afficherMatrice(Matrice m){
	for (int i = 0; i<m.nb_lignes;i++){
		printf("\n");
		for (int j = 0; j<m.nb_col; j++){
			printf("[%d]", m.m[i][j]);
		}
	}
	printf("\n");
}

Matrice multiplierMatrice(Matrice m1, Matrice m2){
	Matrice m3;
	
	if (m1.nb_lignes != m2.nb_lignes || m1.nb_col != m2.nb_col) {
		printf("Les dimensions doivent être similaires");
	} else {
		m3 = alloue_matrice(m1.nb_lignes, m2.nb_col);
		for (int i=0; i<m1.nb_lignes;i++) {
			for (int j=0;j<m2.nb_col;j++){
				for (int k = 0; k<m1.nb_col;k++){
					m3.m[i][j] += m1.m[i][k] * m2.m[k][j];
				}
			}
		}
	}
	return m3;
}

void libere_matrice(Matrice m){
	for(int i = 0; i< m.nb_lignes;i++){
		free(m.m[i]);
	}
	free(m.m);
}

//Exercice 4

int compter_bits(int len, unsigned char* msg){
	int somme = 0;
	unsigned int nbComparer = 0b00000001;
	for (int i=0; i<len; i++){
		int nbEntier = msg[i];
		for (int j=0;j<8;j++){
			if (((nbEntier>>7)&(nbComparer)) == 1){
				somme += 1;
			}
			nbEntier = nbEntier << 1;
		}
	}
	return somme;
}

//deuxième méthode (mieux)
int compter_bits2(int len, unsigned char* msg){
	int somme = 0;
	for (int i=0;i < len;i++){
		for (int j =0;j<8;j++){
			if (msg[i] & (1 << j)){
				somme += 1;
			}
		}
	}
	return somme;
}

void reveler_citation(int len, unsigned char* msg, unsigned char cle){
	for (int i=0;i<len;i++){
		printf("%c", msg[i] ^ cle);
		cle = ((cle << 1) | (cle>>7));
	}
	printf("\n");
}


int main(int argc, char *argv[]){
	// Exercice 1
	Exercice1(argc, argv);
	
	// Exercice 2
	Exercice2(argc, argv);

	
	//Exercice 3
	printf("\nExercice 3 : \n");
		//allouer matrice
		Matrice m1 = alloue_matrice(2,2);
		m1.m[0][0] = 3;
		m1.m[0][1] = 7;
		m1.m[1][0] = 2;
		m1.m[1][1] = 4;
		
		Matrice m2 = alloue_matrice(2,2);
		m2.m[0][0] = 1;
		m2.m[0][1] = 0;
		m2.m[1][0] = 4;
		m2.m[1][1] = 3;
		
		//multiplier matrice
		Matrice m3 = multiplierMatrice(m1,m2);
		
		//afficher matrice
		printf("\nVoici la matrice m1 : \n");
		afficherMatrice(m1);
		
		printf("\nVoici la matrice m2 : \n");
		afficherMatrice(m2);
		
		printf("\nVoici la matrice m3 : \n");
		afficherMatrice(m3);
		
		//liberer matrice 
		
		libere_matrice(m1);
		libere_matrice(m2);
		libere_matrice(m3);
		
		/*(test avec la commande ps -v : une fois que le programme affiche fin, lancer
		la commande ps -v dans un autre terminal, si la fonction liberer mémoire est bonne, ça doit 
		afficher une valeur environ égale à 1000 dans la colonne RSS de la ligne ./prog
		for(int i=0;i<2000000;i++) {
			Matrice m = alloue_matrice(10, 10);
			libere_matrice(m);
		}
		printf("fin\n");
		getchar();
		*/
		
	//Exercice 4
	printf("\nExercice 4 : \n");
		
		//Compter bits à 1
		unsigned char cle = 0b011001011;
		unsigned char msg[LEN] = { 233, 251, 74, 126, 207, 28, 145, 151, 174, 227, 3, 126, 223, 94, 151, 150, 191, 183, 94, 43, 155, 16, 158, 197, 165, 176, 86, 126, 221, 89, 147, 144, 168, 226, 65, 126, 213, 23, 149, 151, 174, 243, 70, 59, 210, 13, 210, 150, 174, 244, 93, 59, 200, 91 };	
		
		printf("\nNombre de bits à 1 : %d\n", compter_bits(LEN, msg));	
		
		//Révéler citation
		printf("\nMessage secret : ");	
		reveler_citation(LEN,msg,cle);
		printf("\n");	
		
	return 0;
}




