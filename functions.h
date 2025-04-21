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



//Functions
void edit_board(void);
void edit_list_name(void);
void add_list(void);
void delete_list(void);
void edit_list(void);
void edit_item(item** first_item);
void add_item(item** first_item);
void delete_item(item** first_item);
void display(void);
