#include <stdio.h> 
#define SAVEBOARD_HEADER

// STRUCTS -----------------
typedef struct Item {
    char name[100];
    struct Item *next;
} Item;

typedef struct List {
    char name[100];
    Item *items;
    struct List *next;
} List;

typedef struct Board {
    List *list;
} Board;

// SAVE BOARD -----------------------------
void saveBoardFile(Board *board, char *fileName) {
    printf("Saving board to file '%s'...\n", fileName); // let user know saving has started

    FILE *fp = fopen(fileName, "w"); // open a file for writing and have a pointer pointing to file 
    if (fp == NULL) { //while not at end of file 
        printf("ERROR! : unable to open file: %s\n", fileName); // error for opening a file 
        return; // end function early 
    }

    List *currentList = board->list; // begin at the beginning of the kanban list 
    while (currentList != NULL) {
        fprintf(fp, "%s\n", currentList->name); // print current list name (list headers)

        Item *currentItem = currentList->items; // set up pointer for first item on the list 
        while (currentItem != NULL) { // loop until end of item list 
            fprintf(fp, "\t%s\n", currentItem->name); // print item with tab indentation
            currentItem = currentItem->next; // move on to the next item in the list
        }

        currentList = currentList->next; // then move to next list on the board 
    }

    fclose(fp); // close file 
    printf("Board saved \n"); // let user know board has saved successfully 
}
