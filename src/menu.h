/*
 * Manages the main loop of the program.
 * Takes a code and a pointer to a dictionnary
 */
void main_loop(int *menu_code, FILE *dictionnary);

/*
 * Clears the screen and displays a title.
 * Takes the title as an argument
 */
void display_header(char *title);

/*
 * (Conveniency function)
 * Displays a separator with a bunch of '-'
 */
void print_separator();

/*
 * Prints out the items of the main menu
 */
void display_main_menu();
