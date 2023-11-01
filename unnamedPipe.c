#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
  char buff[100];
  char str[] = "Hello World\n";
  pid_t pid;
  int p[2];
  pipe(p);
  pid = fork();
  if(pid==0){
    close(p[1]);
    read(p[0],buff,11);
    printf("%s",buff);
  }
  
  else{
    close(p[0]);
    write(p[1],str,strlen(str));
     
  }
}
