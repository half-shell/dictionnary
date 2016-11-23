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

}

void create_dictionary(char *filename, FILE *dictionary){
    fclose(dictionary);
    dictionary = fopen(filename, "w");
}
