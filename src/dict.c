#include <stdio.h>
#include <stdlib.h>

#include "dict.h"

double count_chars(FILE *dictionary){
    double charCount = 0;
    char c;

    while((c = fgetc(dictionary)) != EOF){
        charCount++;
    }
    rewind(dictionary);

    return charCount;
}

double count_words(FILE *dictionary){
    double wordCount = 0;
    char c;

    while((c = fgetc(dictionary)) != EOF){
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

    while((c = fgetc(dictionary)) != EOF){
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
    }
    rewind(dictionary);
}

int check_entry(FILE *dictionary, char *word){
    char c;
    int i = 0;
    fpos_t pos;
    char *compare;

    while((c = getc(dictionary)) != EOF){
        compare[i] = c;

        //Si le mot donnee et dans le dico sont pareils
        if(word[i] == '\0' && word[i-1] == compare[i-1]){
            rewind(dictionary);
            return 1;
        }

        if(c == '\n'){
            for(; i > 0; --i){
                compare[i] = '\0';
            }
            i = -1;
        }
        ++i;
    }
    rewind(dictionary);
    return 0;
}

void create_dictionary(char *filename, FILE *dictionary){
    fclose(dictionary);
    dictionary = fopen(filename, "wr");
}

void insert_into_dictionary(FILE *dictionary, int position, char *word){
    FILE *tmpDico;

    if(dictionary = fopen("./dictionnaire/dico", "r")){

        if(tmpDico = fopen("./dictionnaire/dico.swp", "w")) {

            int i;
            int pos = 17;
            char c;
            char *word = "changer";

            for(i = 0; i <pos; ++i){
                c = fgetc(dictionary);
                fputc(c, tmpDico);
            }
            
            fputs(word, tmpDico);
            fputc('\n', tmpDico);

            while((c = fgetc(dictionary)) != EOF){
                fputc(c, tmpDico);
            }

            dictionary = tmpDico;

            remove("./dictionnaire/dico");

            rename("./dictionnaire/dico.swp", "./dictionnaire/dico");

        }
        fclose(dictionary);
    }
}
