#include<stdio.h>
#include<fcntl.h>

int main(){

    int fd;

    char buffer[80];

    char msg[] = "hola";

    fd = open("a.txt",O_RDWR);

    write(fd,msg,sizeof(msg));

    lseek(fd,0,0);

    read(fd,buffer,sizeof(msg));

    printf("%s",buffer);

}