#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage
{
    int number;
    struct num_storage *next, *prev;
} tNumStorage;

typedef struct num_stor_head
{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
} tNumStorHead;

void delete_last(tNumStorHead *list);
void sort_list(tNumStorHead *list, int input);
void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);

int main(void)
{
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void get_input(tNumStorHead *list)
{
    int value;
    while (1)
    {
        printf("Input a number: ");
        scanf("%d", &value);
        if (value == -1)
            break;
        else if (value == -2)
            delete_last(list);
        else
            sort_list(list, value);
    }
}

void sort_list(tNumStorHead *list, int input)
{
    tNumStorage *new_storage = (tNumStorage *)malloc(sizeof(tNumStorage));
    new_storage->number = input;

    if (list->head == NULL)
    {
        new_storage->next = list->head;
        list->head = new_storage;
        list->tail = new_storage;
        list->head->prev = NULL;
    }
    else
    {
        tNumStorage *tmp_ptr = list->head;
        int i;
        while (tmp_ptr != NULL)
        {
            if (input <= tmp_ptr->number)
            {
                new_storage->next = tmp_ptr;
                new_storage->prev = tmp_ptr->prev;
                list->head = new_storage;
                break;
            }
            else if (input > tmp_ptr->number && tmp_ptr == list->tail)
            {
                new_storage->next = NULL;
                new_storage->prev = tmp_ptr;
                tmp_ptr->next = new_storage;
                list->tail = new_storage;
                break;
            }
            else if (input >= tmp_ptr->number && input < tmp_ptr->next->number)
            {
                tNumStorage *tmp = tmp_ptr->next;
                new_storage->next = tmp;
                tmp->prev = new_storage;
                tmp_ptr->next = new_storage;
                new_storage->prev = tmp_ptr;
                break;
            }
            else
            {
                tmp_ptr = tmp_ptr->next;
            }
        }
    }
    list->counts++;
    print_list(list);
}

void delete_last(tNumStorHead *list)
{
    if (list->head == NULL)
        printf("    there is nothing to delete\n\n");
    else if (list->tail == list->head)
    {
        list->head = NULL;
        list->tail = NULL;
        list->counts -= 1;
        print_list(list);
    }
    else
    {
        tNumStorage *node_ptr = list->tail->prev;
        tNumStorage *deleted = list->tail;
        node_ptr->next = NULL;
        list->tail = node_ptr;
        free(deleted);
        list->counts -= 1;
        print_list(list);
    }
}

void initial_list(tNumStorHead *list)
{
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list)
{
    tNumStorage *node_ptr = list->head;
    printf("  list->counts: %d\n", list->counts);
    printf("  The sorted list: ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n\n");
}
