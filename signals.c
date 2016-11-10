#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

static void sighandler(int signo){
  if (signo == SIGINT){
  int fd = open("log",O_CREAT|O_APPEND|O_WRONLY,0644);
  write(fd,"exiting: SIGINT",20);
  close(fd);
  exit(0);
  }
  else if(signo == SIGUSR1){
    printf("My parent's PID is: %d \n",getppid());
  }
}
int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
while(1){
  printf("My PID is: %d\n",getpid());
  sleep(1);
}
}
