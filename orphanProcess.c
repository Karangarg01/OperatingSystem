#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  pid_t p;
  p = fork();
  if(p==0){
    sleep(2);
    printf("I am child having pid %d\n",getpid());
    printf("My parent id is %d\n",getppid());
  }
  else{
    printf("I am parent having pid %d\n",getpid());
    printf("My child id is %d\n",p);
  }
  return 0;
}
