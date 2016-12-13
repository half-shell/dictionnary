#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

double count_chars(FILE *dictionary){
    double charCount = 0;
    char c;

    while(!feof(dictionary)){
        c = getc(dictionary);
        charCount++;
    }
    rewind(dictionary);

    return charCount;
}

double count_words(FILE *dictionary){
    double wordCount = 0;
    char c;

    while(!feof(dictionary)){
        c = getc(dictionary);
        if((c) == '\n'){
            wordCount++;
        }
    }
    rewind(dictionary);

    return wordCount;
}

void add_entry(FILE *dictionary, char *word){

    char c;
    int i = 0;
    fpos_t pos;
    char *compare;

    do{
        c = getc(dictionary);
        compare[i] = c;

        if(word[i] == '\0' || word[i] < compare[i] || feof(dictionary)){
            break;
        }

        if(word[i] > compare[i]){
            while(c != '\n'){
                c = getc(dictionary);
                i++;
            }
        }

        if(c == '\n'){
            for(; i > 0; --i){
                compare[i] = '\0';
            }
            i = -1;
        }
        ++i;
    } while(!feof(dictionary));
    fgetpos(dictionary, &pos);
}

int check_entry(FILE *dictionary, char *word){
    char c;
    int i = 0;
    fpos_t pos;
    char *compare;

    do{
        c = getc(dictionary);
        compare[i] = c;

        //Si le mot donnee et dans le dico sont pareils
        if(word[i] == '\0' && word[i-1] == compare[i-1]){
            return 1;
        }

        if(c == '\n'){
            for(; i > 0; --i){
                compare[i] = '\0';
            }
            i = -1;
        }
        ++i;
    } while(!feof(dictionary));
    return 0;
}

void create_dictionary(char *filename, FILE *dictionary){
    fclose(dictionary);
    dictionary = fopen(filename, "wr");
}
