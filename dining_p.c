#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t phil[5];
pthread_mutex_t chop[5];

void *fun(int n){

	entered
	pthread_mutex_lock(&chop[(n+1)/5]);
	pthread_mutex_lock(&chop[n]);


	pthread_mutex_unlock(&chop[n]);
	...............................
}

int main(){

int i,k;

void *msg;

for(i=0;i<5;i++){
pthread_mutex_init(&chop[i],NULL);
}

for(i=0;i<5;i++){
pthread_create(&phil[i],NULL,fun,(int*)i);
}

pthread_join(phil[i],&msg);//no & for join


pthread_mutex_destroy(&chopstick[i]);

}
