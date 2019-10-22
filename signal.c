#include <stdio.h>

#include <sys/types.h>

#include <signal.h>

#include <stdlib.h>

#include <unistd.h>

 

void handler1();

void handler2();

 

void main()

{

        int pid;

 

        pid=fork();

        if (pid == 0)

        {

                printf("child\n");

                signal(SIGUSR1,handler1);

                kill(pid,SIGUSR2);

                for(;;);

        }

        else{

                sleep(3);

                printf("\nPARENT: sending SIGHUP\n\n");

                kill(pid,SIGUSR1);

                sleep(3);

                printf("\nPARENT: recv SIGINT\n\n");

                signal(SIGUSR2,handler2);

        }

}

 

void handler1(int signum)

{

        if(signum == SIGUSR1)
                printf("CHILD: I have received a SIGHUP\n");

}

 

void handler2(int signum)

{

        if(signum == SIGUSR2)
                printf("PARENT: I have received a SIGINT\n");

}

 

void sigquit()

{

        printf("My DADDY has Killed me!!!\n");

        exit(0);

}