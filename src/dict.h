/*
 * Takes a pointer to a file (dictionnary) in argument
 * Returns the number of characters it contains
 */
double count_chars(FILE *dictionnary);

/*
 * Takes a pointer to a dictionnary in argument
 * Returns the number of words it contains
 * TODO Make it work as it doesn't currently
 */
double count_words(FILE *dictionnary);

/*
 * TODO
 * Adds the word provided in its place (alpĥabetically)in the dictionnary.
 * Takes a pointer to a dictionnary and a string as arguments
 */
void add_entry(FILE *dictionnary, char *word);

/*
 * TODO
 * Create a dictionnary.
 * Takes the name of the file as an argument
 */
void create_dictionnary(char *filename);
