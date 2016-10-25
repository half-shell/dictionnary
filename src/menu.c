/*
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "dict.h"

void main_loop(int *menu_code, FILE *dictionnary){
    switch(*menu_code){
        case 0:
            break;
        case 1:
            display_header("Main menu");
            display_main_menu();
            printf("\nWhat's your choice buddy? : ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 2:
            display_header("Welcome menu");
            printf("Welcome to the show!\n");
            printf("\nWhat's your choice buddy? : ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 3:
            display_header("Char/Word count");
            printf("Chars: %0.0lf\n", count_chars(dictionnary));
            printf("Words: %0.0lf\n", count_words(dictionnary));
            printf("Type '0' to go back to the main menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        default:
            printf("That's not a valid choice. Try again: ");
    } 
}

void display_header(char *title){
    system("clear");
    print_separator();
    printf("\t\t%s\n", title);
    print_separator();
}

void print_separator(){
    printf("--------------------------------------\n");
}

void display_main_menu(){
    printf("1. This menu.\n");
    printf("2. Welcome.\n");
    printf("3. Display char/words count.\n");
    printf("0. Exit.\n");
}
