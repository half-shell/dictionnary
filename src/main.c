/*
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>

#include "dict.h"
#include "menu.h"

/*
 * Functions*/

int main(int argc, char *argv[]){

    char fileName[256];
    printf("Path du dictionnaire? \n");
    scanf("%s", fileName);
    FILE *dictionnary = fopen(fileName, "rw");

    if(dictionnary){
        int choice = 1;
        main_loop(&choice, dictionnary);
    }

    fclose(dictionnary);

    return 0;
}
