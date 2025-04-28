// Defined values
#define MAX_CHARACTERS 100

//Structs
typedef struct item{
    char name[MAX_CHARACTERS];
    struct item* next;
}item;

typedef struct list{
    char name[MAX_CHARACTERS];
    item* items;
    struct list* next;
    struct list* prev;
}list;

typedef struct Board {
    list *list;
 } Board;

 


//Functions
void edit_board(Board *board);
void edit_list_name(Board *board);
void add_list(Board *board);
void delete_list(Board *board);
void edit_list(Board *board);
void edit_item(item** first_item);
void add_item(item** first_item);
void delete_item(item** first_item);
void display(Board *board);
void saveBoardFile(Board *board, char *fileName);
void quitProgram ();
void parseLine(char *line, list **currentList, list **board);
void loadBoardWithModularParsing(Board *board);
