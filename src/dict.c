#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

double count_chars(FILE *dictionnary){
    double charCount = 0;
    char c;

    while(c = getc(dictionnary) != EOF){
        charCount++;
    }
    return charCount;
}

double count_words(FILE *dictionnary){
    double wordCount = 0;
    char c;

    while(c = getc(dictionnary) != EOF){
        if((c) == '\n'){
            wordCount++;
        }
    }
    return wordCount;
}

void add_entry(FILE *dictionnary, char *word){

}
