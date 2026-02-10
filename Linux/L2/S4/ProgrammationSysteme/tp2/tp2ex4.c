#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int total = 0; 
/*variable globale, elle est dans un emplacement mémoire 
particulier, pas liée au main, ni à aucune fonction mais au 
programme
*/
int n;

struct sigaction act1;

void traiter_signal(int signum) {
    printf("\nTotal = %d\n", total);
    exit(0);
}

//jsp pourquoi c'est souligné en rouge mais ça marche

int main() {
    
    while(1){
        sigemptyset(&(act1.sa_mask));
        act1.sa_flags = 0;
        act1.sa_handler = traiter_signal;
        sigaction(SIGINT, &act1, NULL);

        printf("Choisissez un entier : ");
        scanf("%d", &n); //mon erreur : pas de \n ici car sinon le scanf attends une entrée suivante
        total += n;
    }

    return 0;
}
