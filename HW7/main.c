#include "main.h"


int main (void){
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}



void get_input(tNumStorHead *list){
    int choice;
    while(1){
        printf("1. Add a number ot 2. Delete a number: ");
        scanf("%d", &choice);
        if(choice == 1){
            process_add(list);
        }
        else if(choice == 2){
            process_delete(list);
        }
        else{
            printf("  No such choose !\n");
            continue;
        }
        printf("\n");
    }  
}

void process_add(tNumStorHead *list){
    int number, location, choice;
    process_add_get_input(list->counts, &number, &location, &choice);
    insert(list, number, location, choice);
    print_list(list);
}

void process_delete(tNumStorHead *list){
    int location;
    process_delete_get_input(list->counts, &location);
    delete(list, location);
    print_list(list);
}

void process_add_get_input(int counts, int *number, int *location, int *choice){
    printf(" Add a number: ");
    scanf("%d", number);
    if(counts != 0){
        printf(" Specify a target location: ");
        scanf("%d", location);
        if(*location > counts){
            printf("No such choose !");
        }
        else{
            printf(" 1. Before or 2. After the location %d :", *location);
            scanf("%d", choice);  
        }
    }
    
}

void process_delete_get_input(int counts, int *location){
    printf("Specify a target location: ");
    scanf("%d", location);
    if(*location > counts){
        printf("  No such choose !\n");
    }
}

