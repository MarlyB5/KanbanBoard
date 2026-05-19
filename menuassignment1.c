#include <stdio.h> 
// prints out menu and returns the user choice to the main program
int menu() {
//initialise user choice to 0 to avoid undefined behaviour
int user_choice = 0;
    printf ("_________________\n");
    printf ("   ⋆｡°✩MENU⋆｡°✩\n"); 
    printf ("_________________\n");

    printf ("1. Display board  ☆\n");
    printf ("2. Load board from a file ☆\n"); 
    printf ("3. Edit list ☆\n"); 
    printf ("4. Edit board ☆\n");
    printf ("5. Save board to a file ☆\n"); 
    printf ("6. Quit ☆\n\n"); 

    printf ("Enter your choice (1 - 6)\n");
    //take in user choice
    scanf ("%d" , &user_choice); 
    // return userchoice
    return user_choice; 
}

int main () {
    menu (); 
}
