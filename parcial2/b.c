/********** C3.5 program files ***************/

// (1). --------- b.c file: gcc -o b b.c  ----------

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[])

{

printf("this is %d in %s\n", getpid(), argv[0]);

}

 

