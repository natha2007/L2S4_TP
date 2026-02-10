#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define N 10
#define NS_ATTENTE 200000000

struct timespec attente = {0, NS_ATTENTE};

int main() {

  //Exercice 1

  int pid = fork(); //ou pid_t pid = fork();
  if (pid == -1){
    exit(-1);
  }
  if (pid == 0){
    printf("Dans le processus fils : \n");
    printf("PID du père: %d\n", getppid());
  } else {
    printf("Dans le processus père : \n");
    printf("PID du fils : %d\n", pid); 
  }

  for(int i=1;i<=N;i++) {
    nanosleep(&attente, 0);
    printf("%d/%d PID = %d\n", i, N, getpid());
    fflush(stdout);
  }

  //La valeur de retour de fork est soit égale à 0 (on est dans
  //le processus fils) ou égale à une autre valeur (la valeur 
  //est égale au pid du père, on est donc dans le process père)
  //getpid() = num pid courant
  //getppid() = num pid du processus père

  //Exercice 2



}
