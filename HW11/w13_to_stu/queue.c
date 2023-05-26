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
    int mem_location;

    our_malloc ( .......... );
    
    if (newptr == NULL)
    {
        printf("    Enqueue False!!! \n");
        return 0;
    }
    
    


















    
    return 1;
}

int dequeue_type_small(tQueue *queue, tQueueSmall *target, int data_type)
{
    




















    
    queue->type_small_count--;
    our_free(data_type, target->location);

    return 1;    
}

tQueueSmall *find_target_small_node(tQueue *queue, int id, int data_type)
{
    int i;
    tQueueSmall *target = queue->type_small_front;
    
    










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