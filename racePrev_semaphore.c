#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int shared = 5;
sem_t s;

void* inc(void* arg){
  int local = 0;
  int id = *((int*)arg);
  sem_wait(&s);
  for(int i=0;i<1000000;i++){
       local = shared;
       local++;
       shared = local;

  }
  printf("Shared value for process %d is %d\n",id,shared);
  sem_post(&s);
  pthread_exit(NULL);
}
int main(){
  pthread_t t[2];
  sem_init(&s,0,1);
  int id[2];
  for(int i=0;i<2;i++){
    id[i] = i;
    pthread_create(&t[i],NULL,inc,(void*)&id[i]);
  }
  
  for(int i=0;i<2;i++){
    pthread_join(t[i],NULL);
}
    sem_destroy(&s);
  return 0;
}
