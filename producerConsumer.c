#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#define n 5

sem_t s;
sem_t full;
sem_t empty;
int buff[1000];
int count = 0;
void *prodfunc()
{
    if (count >= 5)
    {
        printf("Overflow\n");
    }
    sem_wait(&empty);
    sem_wait(&s);
    int item;
    printf("Producer is doing task\n");
    for (int i = 0; i < n; i++)
    {
        item = rand() % 100;

        buff[i] = item;
        count++;
        printf("Produced item %d\n", item);
    }
    sem_post(&s);
    sem_post(&full);
    pthread_exit(NULL);
}

void *consFunc()
{
    if (count < 0)
    {
        printf("Underflow\n");
    }
    sem_wait(&full);
    sem_wait(&s);
    printf("Consumer is doing task\n");
    int item;
    for (int i = 0; i < n; i++)
    {

        item = buff[i];
        count--;
        printf("Consumer consumed item %d\n", item);
    }
    sem_post(&s);
    sem_post(&empty);

    pthread_exit(NULL);
}
int main()
{
    pthread_t prod, cons;
    sem_init(&s, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, n);

    pthread_create(&prod, NULL, prodfunc, NULL);
    pthread_create(&cons, NULL, consFunc, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&s);
    sem_destroy(&full);
    sem_destroy(&empty);
    return 0;
}
