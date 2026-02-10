#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    
    for (int i =0;i<10;i++){
        int premier_terme = 1+i*100;
        int dernier_terme = (i+1)*100;
        int somme_termes = ((dernier_terme-premier_terme+1)/2)*(premier_terme + dernier_terme);
        int pid = fork();

        if (pid == 0){
            printf("La somme de %d à %d est : %d\n",premier_terme, dernier_terme, somme_termes );
            printf("Processus père pid : %d\n", getppid());
            printf("Pid : %d\n", getpid());
            exit(0);
        }
    }
    
    for (int i = 0; i < 10; i++) {
        waitpid(-1, NULL, 0); // ou wait(null);
    }



    printf("Tous les calculs sont terminés.\n");
    return 0;
}