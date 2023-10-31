#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int shared = 5;
pthread_mutex_t m;


void* inc(void* arg){
  int local = 0;
  int id = *((int*)arg);
 pthread_mutex_lock(&m);

  for(int i=0;i<1000000;i++){
       local = shared;
       local++;
       shared = local;

  }
  printf("Shared value for process %d is %d\n",id,shared);
  pthread_mutex_unlock(&m);
  pthread_exit(NULL);
}
int main(){
  pthread_t t[2];
  pthread_mutex_init(&m,NULL);
  int id[2];
  for(int i=0;i<2;i++){
    id[i] = i;
    pthread_create(&t[i],NULL,inc,(void*)&id[i]);
  }
  
  for(int i=0;i<2;i++){
    pthread_join(t[i],NULL);
}
  pthread_mutex_destroy(&m);
  return 0;
}
