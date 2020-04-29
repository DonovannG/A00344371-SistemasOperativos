/******** mish.c **********/
// gcc -o mish mish.c
#include <ctype.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

 

#define MAX_LINE 80

#define MAX_NUM_ARGS 10
size_t string_parser(char *input, char *word_array[]) {
size_t n = 0;
while (*input) {
while (isspace((unsigned char)*input))
++input;
if (*input) {
word_array[n++] = (char *)input;
while (*input && !isspace((unsigned char)*input))
++input;
*(input) = '\0';
++input;
}
}
word_array[n] = NULL;
return n;
}

 

int main(void) {

  char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */

  char line[MAX_LINE + 1];

  int should_run = 1;

 

  int i;

 

  while (should_run) {

    printf("mish> ");

    fgets(line,MAX_LINE,stdin);

    line[strcspn(line, "\n")] = '\0';

    // Separamos la línea en palabras separadas por espacio

    // y las guardamos en args

    i = string_parser(line,args); // i contiene el número de argumentos

    printf("%d, %s %s\n", i, args[1],line); // Es solo para pruebas borrar cuando esté listo
    
    /**
    (1) Crear un proceso hijo
    
    (2) El hijo debe ejecutar execvp para ejecutar al comando tecleado
    (3) Si el programa no existe debe imprimir programa no encontrado
    (4) El proceso padre debe esperar a que el hijo termine, checar funcion wait
    (5) Debe ejecutar comandos como ls -l /etc o ps -fea
    (6) Cuando se teclee exit deberá terminar
    **/
    int pid = fork();//se crea el proceso hijo
    if(pid==0){
        execvp(*args, args);//se ejecuta el comando tecleado con lo que se recibe en args
        if(execvp(*args, args)<0){//si no se recoce el comando se imprime el mensaje
            printf("Programa no encontrado");
        }
    }else{
        waitpid(pid);//se espera a que el proceso hijo termine
    }

    /*PSEUDOCODIGO
    Si implementamos el comando siguente se puede verificar si se ingreso ls
    despues de ahi ingresamos el codigo de la funcion, igual para ps
    
    if(strcmp(line, "ls\n")==0){
        Codigo
    }
     if(strcmp(line, "ps\n")==0){
        Codigo
    }

    */
    if(strcmp(line, "exit\n")==0){            //Revisa si el commando es exit y si es sale  del programa
        break;
    }
    fflush(stdout);
    fflush(stdin);
    line[0] = '\0';
  }
 
  return 0;
}
