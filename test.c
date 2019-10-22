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
    s = str;
    for(c = 'a' ; c <= 'z' ; c++){
    
        *s++ = c;

    }

                *s='\0';


    while(*str!='*'){
        sleep(1);
    }

    shmdt(str);

}