#include <stdio.h>
#include <stdlib.h>

#define empty true

typedef struct num_storage{
    struct num_storage *prev;
    int number;
    struct num_storage *next;
} tNumStorage;

typedef struct num_stor_head{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
} tNumStorHead;


void sort_list(tNumStorHead *list, int input);
void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);
void delete_last(tNumStorHead *list);


int main (void){
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void initial_list(tNumStorHead *list){
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list){
    tNumStorage *node_ptr = list->head;
    printf("  list->counts: %d\n", list->counts);
    printf("  The sorted list: ");
    while (node_ptr != NULL)    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n\n");
}


void get_input(tNumStorHead *list){
    while(1){
        int input;
        printf("Input a number (-1 to exit, -2 to delete last): ");
        scanf("%d", &input);
        if(input == -1)
            break;
        if(input == -2){
            if(list->counts != 0){
                delete_last(list);
                print_list(list); 
            }
            else
                printf("There is nothing to delete\n\n");
        }
        else{
            sort_list(list, input);
            print_list(list); 
        }
           
    }  
}

void sort_list(tNumStorHead *list, int input){
    
    tNumStorage *current_node;      // current
    tNumStorage *prev_node;         // previous
    tNumStorage *new_node;          // new node


    new_node = (tNumStorage*)malloc(sizeof(tNumStorage)); 
    new_node->number = input;
    new_node->prev = NULL;
    new_node->next = NULL;

    // if head is empty, then create a new node
    if(list->counts == 0){
        list->head = new_node;
        list->tail = new_node;
    }

    
    else{
        current_node = list->head;

        // current_node->number > new_node->number 
        // new_node <=> list->head
        if(input < current_node->number){
            new_node->next = list->head;
            list->head->prev= new_node;
            list->head = new_node;
        }
        else{
            prev_node = current_node;
            // check current_node not null and current_node->number < new_node->number
            while(current_node && current_node->number <= input){
                prev_node = current_node;
                current_node = current_node->next;
            }
            // tail node data < new_node->number
            // prev_node <=> new_node 
            if(!current_node){
                prev_node->next = new_node;
                list->tail = new_node;
                new_node->prev = prev_node;
            }

            // prev_node <=> new_node <=> current_node 
            else{
                new_node->next = current_node;
                current_node->prev = new_node;
                prev_node->next = new_node;
                new_node->prev = prev_node;
            }
        }
    }
    
    list->counts++;
}
void delete_last(tNumStorHead *list){

    if(list->counts == 1){
        free(list->head);
        initial_list(list);
        return;
    }
    tNumStorage *tmp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(tmp);
    list->counts--;
}