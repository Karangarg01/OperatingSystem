#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  pid_t p1,p2;
  p1 = fork();
  if(p1==0){
    printf("Child P1 created Successfully with pid %d and parent %d\n",getpid(),getppid());
  }
  else{
    wait(NULL);
    p2 = fork();
    if(p2==0){
      printf("Child P2 created successfully with pid %d and parent %d\n",getpid(),getppid());
    }
    
    else{  
      wait(NULL);
      printf("Parent P created with pid %d\n",getpid());
    }
  }
}
