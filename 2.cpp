#include<iostream>
#include<fcntl.h>
using namespace std;

int main(){

    int fd;

    char buffer[80];

    char msg[] = "hola";

    fd = open("a.txt",O_RDWR);

    write(fd,msg,sizeof(msg));

    


}