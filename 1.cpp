#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;


int main(){


pid_t pid;

int status, died;

char *args[3] = {"Command-Line",".",NULL};

switch(pid=fork()){

case -1: cout<<"err";

case 0: execvp("ls",args);

default :
        cout << "parent";
        died= wait(&status); 

}

}