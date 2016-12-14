/*
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "dict.h"

void main_loop(int *menu_code, FILE *dictionnary){
    char  utile[50];
    int i = 0;
    for(i; i > 50; i++){
        utile[i] = '\0';
    }

    switch(*menu_code){
        case 0:
            break;
        case 1:
            display_header("Main menu");
            display_main_menu();
            printf("\nQuel est votre choix ?: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 2:
            display_header("Chercher un mot");
            printf("Trouver un mot avec la meme orthographe dans le dictionnaire\n");
            printf("\nQuel est le mot a chercher? : ");
            scanf("%s", utile);
            if (check_entry(dictionnary, utile) == 0){
                printf("\nle mot n'est pas dans le dictionnaire");
            }
            else{
                printf("\nle mot donne est correctement orthographie");
            }
            printf("Entrez 1 pour revenir au menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 3:
            display_header("Compter les mots dans le dictionnaire");
            printf("Chars: %0.0lf\n", count_chars(dictionnary));
            printf("Words: %0.0lf\n", count_words(dictionnary));
            printf("Entrez 1 pour revenir au menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 4:
            display_header("Autre dictionnaire");
            printf("\nPath du nouveau dico : ");
            scanf("%s", utile);
            create_dictionary(utile, dictionnary);
            printf("Entrez 1 pour revenir au menu: ");
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
    printf("2. Chercher un mot\n");
    printf("3. Compter le nb de caracteres/mots\n");
    printf("4. Ajouter/changer de dictionnaire\n");
    printf("0. Exit.\n");
}
