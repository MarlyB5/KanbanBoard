// Defined constants
#define MAX_CHARACTERS 100

//Structs

//For items in a list
typedef struct item{
    char name[MAX_CHARACTERS];
    struct item* next;
}item;

//For lists in a board
typedef struct list{
    char name[MAX_CHARACTERS];
    item* items;
    struct list* next;
    struct list* prev;
}list;

//For a whole board
typedef struct Board {
    list *list;
 } Board;

 


//Function prototypes
//Functions to edit lists on a board
void edit_board(Board *board);
void edit_list_name(Board *board);
void add_list(Board *board);
void delete_list(Board *board);

//Functions to edit items on a list
void edit_list(Board *board);
void edit_item(item** first_item);
void add_item(item** first_item);
void delete_item(item** first_item);

//Function to display board
void display(Board *board);

//Functions to handle files
void saveBoardFile(Board *board, char *fileName);
void quitProgram ();
void parseLine(char *line, list **currentList, list **board);
void loadBoardWithModularParsing(Board *board);
