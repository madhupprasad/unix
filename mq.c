#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>



int main(void)
{
        char mtext[200];        
        int msqid;
        key_t key;

        key=10;
        msqid = msgget(key, 0644 | IPC_CREAT);

        printf("Enter lines of text, ^C to quit:\n");

        while(fgets( mtext, sizeof  mtext, stdin) != NULL)
        {
                int len = strlen( mtext);

                if ( mtext[len-1] == '\n')
                         mtext[len-1] = '\0';

                msgsnd(msqid, mtext, len+1, 0);

        }
        msgctl(msqid, IPC_RMID, NULL);
        return 0;
}