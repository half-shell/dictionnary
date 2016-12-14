/*
 * Assign a file pointer
 */
FILE *dictionary;

/*
 * Takes a pointer to a file in argument.
 * Returns the number of characters it contains.
 */
double count_chars(FILE *dictionary);

/*
 * Takes a pointer to a dictionary in argument.
 * Returns the number of words it contains.
 */
double count_words(FILE *dictionary);

/*
 * TODO
 * Adds the word provided in its place (alpĥabetically)in the dictionary.
 * Takes a pointer to a dictionary and a string as arguments.
 */
int add_entry(FILE *dictionary, char *word);

/*
 * TODO
 * Check weither or not the dictionary has the word.
 * Takes a dictionary name and a word as parameter.
 * Return 1 if the word is present and 0 otherwise.
 */
int check_entry(FILE *dictionary, char *word);

/*
 * Create a dictionary.
 * Takes the name of the new dicitonnary and the pointer to the old one as an argument.
 */
void create_dictionary(char *filename, FILE *dictionary);

/*
 * create and fills a temporary dictionary
 */
void insert_into_dictionary(FILE *dictionary, int position, char *word);
