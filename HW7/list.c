#include "list.h"

void initial_list(tNumStorHead *list){
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list){
    tNumStorage *node_ptr;

    printf("\n");
    printf("counts: %d\n", list->counts);
    node_ptr = list->head;
    printf(" From head --> ");
    while(node_ptr != NULL){
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    node_ptr = list->tail;
    printf("\n From tail --> ");
    while(node_ptr != NULL){
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->prev;
    }
    printf("\n");
}

void insert(tNumStorHead *list, int value, int index, int loc){


    tNumStorage *current_node;      // current
    tNumStorage *prev_node;         // previous
    tNumStorage *new_node;          // new node


    new_node = (tNumStorage*)malloc(sizeof(tNumStorage)); 
    new_node->number = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if(list->counts == 0){
        list->head = new_node;
        list->tail = new_node;
    }
    else{
        if(list->counts < index){
            return;
        }
        // Add to first node
        if(index == 1){
            if(loc == 1){
                new_node->next = list->head;
                list->head->prev = new_node;
                list->head = new_node;
            }
            else{
                // head->next not NULL
                if(list->head->next){
                    new_node->next = list->head->next;
                    list->head->next->prev = new_node;
                    list->head->next = new_node;
                    new_node->prev = list->head;
                }
                else{
                    list->head->next = new_node;
                    new_node->prev = list->head;
                    list->tail = new_node;
                }
            }
        }
        // Add to last node
        else if(index == list->counts && index != 1){
            // Before
            if(loc == 1){
                list->tail->prev->next = new_node;
                new_node->prev = list->tail->prev;
                new_node->next = list->tail;
                list->tail->prev = new_node;
            }
            // After
            else{
                list->tail->next = new_node;
                new_node->prev = list->tail;
                new_node->next = NULL;
                list->tail = new_node;
            }
        }
        // Others condition
        else{
            current_node = list->head;
            for(int i = 1; i < index; i++)
                current_node = current_node->next;
            // Before
            if(loc == 1){
                current_node->prev->next = new_node;
                new_node->prev = current_node->prev;
                new_node->next = current_node;
                current_node->prev = new_node;
            }
            // After
            else{
                new_node->next = current_node->next;
                current_node->next->prev = new_node;
                current_node->next = new_node;
                new_node->prev = current_node;
            }
        }
    }

    list->counts++;
}

void delete(tNumStorHead *list, int index){
    if(list->counts < index){
        return;
    }

    tNumStorage *tmp;
    tNumStorage *current_node;
    current_node = list->head;
    
    // delete first node
    if(index == 1){
        if(list->counts == 1)
            initial_list(list);
        else{
            tmp = list->head;
            list->head = list->head->next;
            list->head->prev = NULL;
            free(tmp);
            list->counts--;
        }
    }
    // delete last node
    else if(index == list->counts && index != 1) {
        tmp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(tmp);
        list->counts--;
    }
    // Others condition
    else{
        for(int i = 1; i < index; i++)
            current_node = current_node->next;
        tmp = current_node;
        current_node->prev->next = current_node->next;
        current_node->next->prev = current_node->prev;
        free(tmp);
        list->counts--;
    }
}
