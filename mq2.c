#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main(void)
{
        int msqid;
        key_t key;
        key=10;
        char mtext[200];


        msqid = msgget(key, 0644);

        printf("Ready to receive messages, captain.\n");

        for(;;)
        {
                msgrcv(msqid, mtext, sizeof mtext, 0, 0);
                printf("Received: \"%s\"\n", mtext);
        }
 
        return 0;
}