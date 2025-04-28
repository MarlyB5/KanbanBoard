#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void edit_board(Board *board){
    int option = 0;
    printf("Options:\n");
    printf("1. Edit the name of a list\n");
    printf("2. Add a new list\n");
    printf("3. Delete a list");
    printf("4. Return to main menu\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option){
        case 1: edit_list_name(board);
        break;
        case 2: add_list(board);
        break;
        case 3: delete_list(board);
        break;
        case 4: break;
        default: printf("Invalid option");
        break;
    }
}

void edit_list_name(Board *board){
    list* cur_list = board->list;
    list* list_to_edit = NULL;
    int found = 0;
    char new_name[MAX_CHARACTERS];
    char list_name[MAX_CHARACTERS];

    printf("Enter the name of the list to edit: ");
    scanf("%s", list_name);

    printf("Enter new name: ");
    scanf("%s", new_name);

    while (cur_list != NULL){
        if (strcmp(list_name, cur_list->name) == 0){
            strcpy(cur_list->name, new_name);
            found = 1;
        }
        cur_list = cur_list->next;
    }

    if(!found){
        printf("List not found");
    }
}

void add_list(Board *board){
    char new_name[MAX_CHARACTERS];

    printf("Enter name of new list:");
    scanf("%s", new_name);

    list* new_list = malloc(sizeof(list));

    if (new_list == NULL){
        printf("Memory error");
        return;
    }

    strcpy(new_list->name, new_name);
    new_list->items = NULL;
    new_list->next = board->list;
    new_list->prev = NULL;

    if(board->list != NULL){
        board->list->prev = new_list;
    }
    
    board->list = new_list;
}

void delete_list(Board *board){
    char list_name[MAX_CHARACTERS];
    list* cur_list = board->list;

    printf("Enter the name of list you wish to edit:");
    scanf("%s", list_name);
    
    while(cur_list != NULL && strcmp(cur_list->name, list_name) != 0){
        cur_list = cur_list->next;        
    }

    if (cur_list == NULL){
        printf("List not found");
        return;
    }

    if (cur_list->prev != NULL){
        cur_list->prev->next = cur_list->next;
    }
    else{
        board->list = cur_list->next;
    }

    if (cur_list-> next != NULL){
        cur_list->next->prev = cur_list->prev;
    }

    item* cur_item = NULL;

    while (cur_list->items != NULL){
        cur_item = cur_list->items;
        cur_list->items = cur_list->items->next;
        free(cur_item);
    }

    free(cur_list);
}

void edit_list(Board *board){
    list* cur_list = board->list;
    char list_name[MAX_CHARACTERS];
    list* list_to_edit = NULL;

    printf("Enter the name of the list to edit: ");
    scanf("%s", list_name);

    while (cur_list != NULL){
        if (strcmp(list_name, cur_list->name) == 0){
            list_to_edit = cur_list;
            break;
        }
        cur_list = cur_list->next;
                        
    }

    if (list_to_edit == NULL){
        printf("List not found");
        return;
    }

    int option = 0;
    printf("Options:\n");
    printf("1. Edit an item\n");
    printf("2. Add an item\n");
    printf("3. Delete an item");
    printf("4. Return to main menu\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option){
        case 1: edit_item(&list_to_edit->items);
        break;
        case 2: add_item(&list_to_edit->items);
        break;
        case 3: delete_item(&list_to_edit->items);
        break;
        case 4: break;
        default: printf("Invalid option");
        break;
    }
}

void edit_item(item** first_item){
    char item_to_edit[MAX_CHARACTERS];
    char new_item[MAX_CHARACTERS];

    printf("Enter the name of item to edit");
    scanf("%s", item_to_edit);

    printf("Enter new name:");
    scanf("%s", new_item);

    item* cur_item = *first_item;

    while(cur_item != NULL){
        if (strcmp(cur_item->name, item_to_edit) == 0){
            strcpy(cur_item->name, new_item);
            return;
        }
        cur_item = cur_item->next;
    }
}

void add_item(item** first_item){
    char item_name[MAX_CHARACTERS];

    printf("Enter item name:");
    scanf("%s", item_name);

    item* new_item = malloc(sizeof(item));
    
    if (new_item == NULL){
        printf("Memory error");
        return;
    }

    strcpy(new_item->name, item_name);

    new_item->next = *first_item;
    *first_item = new_item;
}

void delete_item(item** first_item){
    char item_name[MAX_CHARACTERS];

    printf("Enter name of item to delete:");
    scanf("%s", item_name);

    item* cur_item = *first_item;
    item* prev_item = NULL;

    while (cur_item != NULL && strcmp(cur_item->name, item_name)){
        prev_item = cur_item;
        cur_item = cur_item->next;
    }

    if (cur_item == NULL){
        printf("Item not found");
        return;
    }

    if (prev_item != NULL){
        prev_item->next = cur_item->next;
    }
    else{
        *first_item = cur_item->next;
    }

    free(cur_item);
}

void display(Board *board){
    list* cur_list = board->list;

    while (cur_list != NULL){
        printf("%s:\n", cur_list->name);
        item* cur_item = cur_list->items;
        while (cur_item != NULL){
            printf("%s\n", cur_item->name);
            cur_item = cur_item->next;
        }
        cur_list = cur_list->next;
    }
}