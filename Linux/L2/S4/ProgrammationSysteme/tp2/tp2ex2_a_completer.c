 #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 10
#define NS_ATTENTE 5000000000

struct timespec attente = {0, NS_ATTENTE};

void compter(int n) {
  for (int i = 0;i<n;i++){
    nanosleep(&attente,0);
    printf("%d\n", i+1);
    fflush(stdout);
  }
}

int main(int argc, char *argv[]) {

  int pid = fork();

  if (argc != 3) {
    printf("Veuillez entrer 2 entiers positifs en arguments\n");
    exit(-1);
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  if (x<=0 || y<=0) {
    printf("Veuillez entrer 2 entiers positifs en arguments\n");
    exit(-1);
  }

  if (pid == -1){
    exit(-1);
  }
  
  if(pid == 0){
    compter(y);
    printf("processus fils terminé \n");
  } else{
    compter(x);
    printf("processus père terminé \n");
    wait(&pid);
    printf("Message question 2b\n");
  }
  

}
