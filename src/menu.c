/*
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "dict.h"

void main_loop(int *menu_code, FILE *dictionnary){
    char word[50];
    int i = 0;

    switch(*menu_code){
        case 0:
            break;
        case 1:
            display_header("Menu principal");
            display_main_menu();
            printf("\nQuel est votre choix ?: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 2:
            display_header("Rechercher un mot");
            printf("Trouver un mot avec la meme orthographe dans le dictionnaire\n");
            printf("\nQuel est le mot à chercher?: ");
            scanf("%s", word);
            if (check_entry(dictionnary, word)){
                printf("\nle mot existe dans le dictionnaire.\n");
            } else{
                printf("\nle mot n'est pas dans le dictionnaire.\n");
            }
            printf("\nEntrez 1 pour revenir au menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 3:
            display_header("Propriétés");
            printf("Nombre de charactères: %0.0lf\n", count_chars(dictionnary));
            printf("Nombre de mots: %0.0lf\n", count_words(dictionnary));
            printf("\nEntrez 1 pour revenir au menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 4:
            display_header("Autre dictionnaire");
            printf("\nRentrez le chemin d'un nouveau dictionnaire: ");
            scanf("%s", &word);
            create_dictionary(word, dictionnary);
            printf("\nEntrez 1 pour revenir au menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        case 5:
            display_header("Ajout d'un mot");
            printf("\nEntrez le mot que vous souhaitez ajouter:\n");
            scanf("%s", &word);
            if(add_entry(dictionnary, word)){
                printf("Mot ajouté!\n");
            } else {
                printf("Le mot existe déjà dans le dictionnaire.\n");
            }
            printf("\nEntrez 1 pour revenir au menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
            break;
        default:
            printf("Ce choix n'est pas valide.\n");
            printf("\nEntrez 1 pour revenir au menu: ");
            scanf("%i", menu_code);
            main_loop(menu_code, dictionnary);
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
    printf("1. Menu principal\n");
    printf("2. Rechercher un mot\n");
    printf("3. Propriétés du dictionnaire\n");
    printf("4. Créer/changer de dictionnaire\n");
    printf("5. Ajouter un mot au dictionnaire\n");
    printf("0. Exit.\n");
}
