#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int main(){
    char* file = "WarAndPeace.txt";
    char * delim = "\"\'.“”‘’?:;-,—*($%)! \t\n\x0A\r";
    
    printf("Done\n");
    char buffer[180];
    int length;
    int fd;

    /*Error if the file is empty*/
    if((fd = open(file,O_RDONLY))<0){
        perror("File not found");
        exit(1);
    }
    int i = 0;
    
    while((length = read(fd,buffer,200))>0){
        char* tok;
        char* rest = buffer;
        while((tok= strtok_r(rest,delim,&rest))){
            if(strlen(tok)>=6)
                printf("length:%ld, %s\n",strlen(tok),tok);
        }
    }
    return 0;
}