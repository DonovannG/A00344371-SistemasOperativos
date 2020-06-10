#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s{
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

typedef char boolean;

int main(){
    int destination;
    Student *myStudent1;
    myStudent1 = malloc(sizeof(Student));
    myStudent1->id=20;
    myStudent1->semester=2;
    sprintf(myStudent1->firstName, "%s", "Miguel");
    destination = creat("class.bin",0600);
    write(destination, myStudent1, sizeof(Student));
    close(destination);
    free(myStudent1);
    return 0;


}