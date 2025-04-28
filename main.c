// Written by: Marly Bah
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    //initialise user choice to 0 to avoid undefined behaviour
    int user_choice = 0;

    //create a board and initialize to NULL
    Board board = {.list = NULL}; 

    while(1){
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
       
       switch(user_choice){
        case 1: display(&board); break;
        case 2: loadBoardWithModularParsing(&board); break;
        case 3: edit_list(&board); break;
        case 4: edit_board(&board); break;
        case 5: {
            char file[100];
            printf("Enter file name to save: ");
            scanf("%s", &file);
            saveBoardFile(&board, file);
            break;
        }
        case 6: quitProgram(); break;
        default: printf("Invalid choice.\n");
       }
    }
          //ascii art
        printf("      ***      \n");
        printf("     *****     \n");
        printf("    *******    \n");
        printf("      ***      \n");
        printf("      ***      \n");
        printf("     ** **     \n");
        printf("    **   **    \n");
        printf("   **     **   \n");
        printf("  ***********  \n");
        printf(" **    *    ** \n");
        printf("      * *      \n");
        printf("     *   *     \n");
        printf("    *     *    \n");
        printf("   *       *   \n");

    }

    
void saveBoardFile(Board *board, char *fileName) {
    printf("Saving board to file '%s'...\n", fileName); // let user know saving has started
 
 
    FILE *fp = fopen(fileName, "w"); // open a file for writing and have a pointer pointing to file
    if (fp == NULL) { //while not at end of file
        printf("ERROR! : unable to open file: %s\n", fileName); // error for opening a file
        return; // end function early
    }
 
 
    list *currentList = board->list; // begin at the beginning of the kanban list
    while (currentList != NULL) {
        fprintf(fp, "%s\n", currentList->name); // print current list name (list headers)
 
 
        item *currentItem = currentList->items; // set up pointer for first item on the list
        while (currentItem != NULL) { // loop until end of item list
            fprintf(fp, "\t%s\n", currentItem->name); // print item with tab indentation
            currentItem = currentItem->next; // move on to the next item in the list
        }
 
 
        currentList = currentList->next; // then move to next list on the board
    }
 
 
    fclose(fp); // close file
    printf("Board saved \n"); // let user know board has saved successfully
 }
 
 void quitProgram (){
    printf ("Quitting program... ˙◠˙");
    exit (0); 
 }
 
 
void parseLine(char *line, list **currentList, list **board) {
    char *trimmed = trimLeadingWhitespace(line);
    size_t len = strlen(trimmed);
    if (len > 0 && trimmed[len - 1] == '\n') trimmed[len - 1] = '\0';

    if (strchr(trimmed, ':')) {
        *currentList = createList(trimmed);
        appendList(board, *currentList);
    } else if (*currentList) {
        item *cur_item = createItem(trimmed);
        item *temp = (*currentList)->items;
        if (!temp) {
            (*currentList)->items = cur_item;
        } else {
            while (temp->next) temp = temp->next;
            temp->next = cur_item;
        }
    }
}

void loadBoardWithModularParsing(Board *board) {
    char filename[100], line[MAX_CHARACTERS];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    list *currentList = NULL;
    while (fgets(line, MAX_CHARACTERS, fp)) {
        parseLine(line, &currentList, &(board->list));
    }

    fclose(fp);
    printf("Board loaded using modular parser.\n");
}
