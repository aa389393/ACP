#include<stdio.h>
#include<stdlib.h>
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
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);
void insert(tNumStorHead *list, int value, int index, int loc);
void delete(tNumStorHead *list, int index);