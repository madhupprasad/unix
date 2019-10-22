#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

int main()
{
	char str[1024], *cp;
	int pipefd[2];
	pid_t pid;

	char *argv[3] = {"cl",".",NULL};

	int status,died;

	pipe(pipefd);

	switch(pid = fork()) {

   case 0 : // this is the code the child runs 
            close(1);      // close stdout
            // pipefd[1] is for writing to the pipe. We want the output
            // that used to go to the standard output (file descriptor 1)
            // to be written to the pipe. The following command does this,
            // creating a new file descripter 1 (the lowest available) 
            // that writes where pipefd[1] goes.
            dup (pipefd[1]); // points pipefd at file descriptor
            // the child isn't going to read from the pipe, so
            // pipefd[0] can be closed
            close (pipefd[0]);
            cout << "otha";

		write(pipefd[1],"hello bitch",5);


   default: // this is the code the parent runs 

            close(0); // close stdin
            // Set file descriptor 0 (stdin) to read from the pipe
            dup (pipefd[0]);
            // the parent isn't going to write to the pipe
            //close (pipefd[1]);
            // Now read from the pipe
            cin.getline(str, 1023);
            cout << "The date is " << str << endl;
            //died= wait(&status);
	
		read(pipefd[0],str,5);
		cout << str;
 }
return 0;
}