#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage{
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
    printf(" list->tail: %d\n", list->tail->number);
}


void get_input(tNumStorHead *list){
    while(1){
        int input;
        printf("Input a number: ");
        scanf("%d", &input);
        if(input == -1)
            break;
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
    new_node->next = NULL;

    // if head is empty, then create a new node
    if(list->counts == 0){
        list->head = new_node;
        list->tail = new_node;
    }

    
    else{
        current_node = list->head;

        // current_node->number > new_node->number 
        if(input < current_node->number){
            new_node->next = list->head;
            list->tail = list->head;
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
            if(!current_node){
                prev_node->next = new_node;
                list->tail = new_node;
            }
            else{
                new_node->next = current_node;
                prev_node->next = new_node;
                list->tail = current_node;
            }
        }
    }
    
    list->counts++;
}
