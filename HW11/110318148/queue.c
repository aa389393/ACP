#include "queue.h"
#include "space.h"


tQueue* createQueue(void){    
    tQueue *queue;
    queue=(tQueue *) malloc (sizeof(tQueue));

    if (queue)
    {
        queue->type_small_front=NULL;
        queue->type_small_rear=NULL;  
        queue->type_small_count=0;
    }

    return queue;
}

int enqueue_type_small(tQueue *queue, int id, int score, int data_type)
{
    tQueueSmall *newptr = NULL;
    tQueueSmall *current_node;
    tQueueSmall *prev_node;
    int mem_location;

    our_malloc (data_type, &newptr, &mem_location);
    
    if (newptr == NULL)
    {
        printf("    Enqueue False!!! \n");
        return 0;
    }
    newptr->id = id;
    newptr->location = mem_location;
    newptr->data_type = data_type;
    newptr->next = NULL;
    newptr->prev = NULL;


    if(queue->type_small_count==0){
        queue->type_small_front = newptr;
    }
    else{
        newptr->prev = queue->type_small_rear;
        queue->type_small_rear->next = newptr; 
    }
    queue->type_small_rear = newptr;
    queue->type_small_count++;
   
    return 1;
}

int dequeue_type_small(tQueue *queue, tQueueSmall *target, int data_type)
{
    if(queue->type_small_count == 1){
        queue->type_small_front = NULL;
        queue->type_small_rear = NULL;
        queue->type_small_count = 0;
        our_free(data_type, target->location);
        return;
    }

    // target is head
    if(target->prev == NULL){
        queue->type_small_front = target->next;
        target->next->prev = NULL;
    }
    // target is tail
    else if(target->next == NULL){
        queue->type_small_rear = target->prev;
        target->prev->next = NULL;
    }
    else{
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }   
    queue->type_small_count--;
    our_free(data_type, target->location);

    return 1;    
}

tQueueSmall *find_target_small_node(tQueue *queue, int id, int data_type)
{
    tQueueSmall *target = queue->type_small_front;
    for(int i = 0; i < queue->type_small_count; i++){
        if(target->id == id && target->data_type == data_type)
            return target;
        target = target->next;
    }
    return NULL;
}


void print_queue (tQueue *queue)
{
    int i;
    tQueueSmall *target = queue->type_small_front;

    printf("      type small queue: ");    
    for (i = 0; i < queue->type_small_count; i++)
    {
        printf ("%d ", target->id);
        target = target->next;
    }
    printf("\n");
}