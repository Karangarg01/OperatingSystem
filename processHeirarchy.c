#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  pid_t p1,p2;
  p1 = fork();
  if(p1==0){   
    p2 = fork();
    if(p2==0){
      printf("Child P2 created successfully with pid %d\n",getpid());
      printf("Parent of P2 is %d\n",getppid());      
    }
    else{
    wait(NULL);
    printf("Child P1 created Successfully with pid %d\n",getpid());
    printf("Parent of P1 is %d\n",getppid());
    }
  }
  else{
    wait(NULL);
    printf("Parent P with %d created\n",getpid());
  }
 
}
