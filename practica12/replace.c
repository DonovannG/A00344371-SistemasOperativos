#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argn, char **argv){
    char *fileName = argv[3];
    char *searchW=argv[1];
    char *replaceW=argv[2];
    char word[100];
    char character;
    char espacio = 0;
    int i=0;
    unsigned int numChar=0, numLines=0, numWords=0;
    int fd = open(fileName, O_RDONLY);
    if(fd<0){
        printf("No se puede abrir\n");
        exit(1);
    }
    while(read(fd, &character, 1)){
        if((character == ' ' || character=='\n'||character==EOF)&& espacio==0){
            espacio =1;
            word[i] ='\0';
             i=0;
            printf("%s\n", word);
        }else if(character != ' '&& character!= '\n' && character!=EOF){
            espacio=0;
           word[i++]=character;
        }
        
    }
    close(fd);
    exit(0);
}