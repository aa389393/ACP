#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage
{
    int number;
    struct num_storage *next;
    struct num_storage *prev;
} tNumStorage;

typedef struct num_stor_head
{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
} tNumStorHead;


void insert_node(tNumStorHead *list, int input,int insert_index,int before_or_after);
void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);
void delete_node(tNumStorHead *list,int delete_index);

int main (void)
{
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void get_input(tNumStorHead *list)
{
    int intputValue;
    int choice;
    int insert_index=0;
    int delete_index=0;
    int before_or_after=1;
    do{
        printf("1. Add a nuumber or 2. Delete a number:");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Add a number:");
            scanf("%d",&intputValue);
            if(list->counts>0)
            {
                printf(" Specify a target location:");
                scanf("%d",&insert_index);
                if(insert_index > list->counts){
                    printf("  No such choose !\n");
                }
                else{
                    printf(" 1. Before or 2. After the location %d:",insert_index);
                    scanf("%d",&before_or_after);
                    insert_node(list,intputValue,insert_index,before_or_after);
                }
            }
            else{
                insert_node(list,intputValue,insert_index,before_or_after);
            }
            // insert_node(list,intputValue,insert_index,before_or_after);
            printf("\n");
        }
        else if (choice==2) 
        {   
            printf(" Specify a target location:");
            scanf("%d",&delete_index);
            if(delete_index > list->counts){
                printf(" No such choose !\n");
                get_input(list);
            }
            else{
                delete_node(list,delete_index);
            }
        }
        else
        {
            printf("No such choose !\n");
        }
    }while(choice!=-1);
    printf("Exit!\n");
}
void delete_node(tNumStorHead *list,int delete_index)
{
    tNumStorage *delete_node;
    int search_index=1;
    delete_node=list->head;
    //search delete node until search_index=delete_index
    while(delete_node!=NULL && (search_index!=delete_index))
    {
        delete_node=delete_node->next;
        search_index++;
        //printf("\nsearch_index: %d",search_index);
    }
    printf("delete %d from list\n",delete_node->number);
    //if delete_node is not fisrt node
    if(delete_node->prev!=NULL)
    {
        delete_node->prev->next=delete_node->next;
        //if delete_node is not last node
        if(delete_node->next!=NULL)
        {
            delete_node->next->prev=delete_node->prev;
        }
        else{
            list->tail=delete_node->prev;
        }
        list->counts--;
        free(delete_node);
    }
    //if delete_node is  fisrt node
    else{
        list->head=delete_node->next;
        if(delete_node->next!=NULL)
        {
            delete_node->next->prev=NULL;
        }
        else{
            //delete_node next is null, delete_node is last node
            list->tail=delete_node->prev;
        }

        
        list->counts--;
        free(delete_node);
    }
    
    print_list(list);
}
void insert_node(tNumStorHead *list, int input,int insert_index,int before_or_after)
{
    tNumStorage *node=(tNumStorage*)malloc(sizeof(tNumStorage));
    node->next=NULL;
    node->prev=NULL;
    node->number=input;
    tNumStorage *current;
    tNumStorage *previous;
    //printf("%d",list->counts);
    current=list->head;
    previous=NULL;
    int search_index=1;
    printf("input=%d,insert_index=%d,before_or_after=%d",input,insert_index,before_or_after);
    //if no node is existed in the list
    if(list->head == NULL)
    {
        //node is first node
        list->head=node;
        list->tail=node;
    }
    //if insert node before first node
    else if(insert_index==1 && before_or_after==1)
    {
        node->next=current;
        node->prev=NULL;
        list->head=node;
        current->prev=node;
    }
    //if insert node before insert_index node
    else if(before_or_after==1)
    {
        //search node until search_index is equal to insert_index
        while(current!=NULL && (search_index!=insert_index))
        {
            previous=current;
            current=current->next;
            search_index++;
            //printf("\nsearch_index: %d",search_index);
        }
        //printf("\ncurrent index: %d",current->number);
        //insert node in the first node
        //then insert node after previous node (search_index-1)
        if(previous!=NULL)
        {
            printf("\ninsert %d before %d",node->number,previous->number);
            node->next=previous->next;
            node->prev=previous;
            //if previous node is not last node
            if(previous->next !=NULL)
            {
                previous->next->prev=node;
            }
            previous->next=node;
        }
        else{
            printf("\nnothing to do!");
        }
    }
    else if(before_or_after==2){
        //search location
        //printf("\ncurrent->number: %d",current->number); 
        //initialize search_index=1
        search_index=1;
        //search node until search_index=insert_index
        //The index previous node is equal to insert_index
        while(current!=NULL && (search_index<=insert_index))
        {
            previous=current;
            current=current->next;
            search_index++;
            //printf("\nsearch_index: %d",search_index);
        }
        //insert location after previous node (insert_index)
        //if while condition is that search_index<insert_index, you should carefully use current node because you might meet the situtation where current node is null and then need a extra process
        //if while condition is that search_index<=insert_index, you should use previous node
        if(previous!=NULL)
        {
            printf("\ninsert %d after %d",node->number,previous->number);
            node->next=previous->next;
            node->prev=previous;
            if(previous->next !=NULL)
            {
                previous->next->prev=node;
            }
            previous->next=node;
            //if the end node...
            if(node->next == NULL)
            {
                list->tail=node;
            }
        }
        else{
            //if previous is null, it means that you might insert the first node
            printf("\nnothing to do!");
        }
    }
    list->counts++;
    print_list(list);
}
void initial_list(tNumStorHead *list)
{
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list)
{
    tNumStorage *node_ptr;
    printf("\n");
    printf("count: %d \n",list->counts);
    node_ptr = list->head;
    printf(" From head --> ");
    while(node_ptr != NULL)
    {
        printf("%d ",node_ptr->number);
        node_ptr=node_ptr->next;
    }
    node_ptr=list->tail;
    printf("\n From tail --> ");
    while(node_ptr != NULL)
    {
        printf("%d ",node_ptr->number);
        node_ptr=node_ptr->prev;
    }
    printf("\n");
}

