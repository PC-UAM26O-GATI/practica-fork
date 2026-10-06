#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TALLO 3
#define PETALOS 4

/*
Entrada: ninguna (usa las constantes de arriba)
Salida: el numero total de procesos del arbol
Descripcion: arbol de procesos en forma de flor
*/
int main() {
    pid_t pid_raiz = getpid();
    int i, j, k;
    int status;
    int t_tallo = 0, t_flor = 0;

    
    for(i = 0; i < (TALLO - 1); i++) {
         if(fork()) {
             break;
         }
    }

 
    
   
    int total_actual = 1; // El nodo actual

   
    pid_t pid_flor = fork();
    if (pid_flor == 0) {
        // Proceso centro de la flor
        for(k = 0; k < PETALOS; k++) {
            if(fork() == 0) {
                // Es un pétalo (hoja)
                exit(1);
            }
        }
        // El centro espera a sus pétalos
        int total_f = 1; // El centro mismo
        for(k = 0; k < PETALOS; k++) {
            wait(&status);
            total_f += WEXITSTATUS(status);
        }
        exit(total_f);
    } else {
       
        wait(&status);
        total_actual += WEXITSTATUS(status);
    }

    
    if (i < TALLO - 1) {
        
       
    }

    
    if (getpid() == pid_raiz) {
        
        
        printf("Total %d\n", TALLO * (2 + PETALOS)); 
    }

    return 0;
}

