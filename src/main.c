/*
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>

#include "dict.h"
#include "menu.h"

/*
 * Functions
 */
int main(int argc, char *argv[]){
    int choice = 1;
    if(argv[1]){
        FILE *dictionnary = fopen(argv[1], "rw");
        if(dictionnary){
            main_loop(&choice, dictionnary);
        } 
        fclose(dictionnary);
    }
}
