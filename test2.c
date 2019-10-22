#include<unistd.h>
#include<stdio.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>

int main(){

    char *s,*str;

    key_t key = ftok("shmfile",65);

    int shmid = shmget(key,1024,0666|IPC_CREAT);

    str =(char*) shmat(shmid,NULL,0);

    char c;
    for(s = str; *s != '\0'; s++){
        putchar(*s);
    }
    putchar('\n');


    *str = '*';

    shmdt(str);

    shmctl(shmid,IPC_RMID,NULL);

}