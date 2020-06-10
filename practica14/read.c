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


int main(){
    int src;
    Student *myStudent1;
    myStudent1 = malloc(sizeof(Student));

    src = open("class.bin", O_RDONLY);
    read(src, myStudent1, sizeof(Student));
    printf("My Student is: %d, %d, %s, %s",
    myStudent1->id,
    myStudent1->semester,
    myStudent1->firstName,
    myStudent1->lastName);
    sprintf(myStudent1->firstName, "%s>%d", "Perez", 2);
    lseek(src, -1*sizeof(Student), SEEK_CUR);
    write(src, myStudent1, sizeof(Student));
    close(src);
    free(myStudent1);
    return 0;


}