#include "queue.h"
#include "space.h"


tQueue* createQueue(void){    
    tQueue *queue;
    queue=(tQueue *) malloc (sizeof(tQueue));

    if (queue)
    {
        queue->front=NULL;
        queue->rear=NULL;  
        queue->count=0;
    }

    return queue;
}

int tqueue_enqueue(tQueue *queue, int id, int score, int type)
{
    tQueueNode *new_node = (tQueueNode *)malloc (sizeof(tQueueNode));
    void *newptr = NULL;
    int mem_location;
    
    our_malloc (type, (void *)&newptr, &mem_location);

    if(!newptr){
        printf("    \033[31mEnqueue Failed!!! \033[0m\n\n\n");
        return 0;
    }

    new_node->type = type;
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->content = newptr;

    if(type == TYPE_SMALL){
        ((tQueueSmall*)new_node->content)->id = id;
        ((tQueueSmall*)new_node->content)->location = mem_location;
    }
    else if(type == TYPE_LARGE){
        ((tQueueLarge*)new_node->content)->id = id;
        ((tQueueLarge*)new_node->content)->location = mem_location;
    }

    if(queue->count == 0){
        queue->front = new_node;
    }
    else{
        new_node->prev = queue->rear;
        queue->rear->next = new_node;
    }
    queue->rear = new_node;
    queue->count++;

    return 1;
    
}

int dequeue_type_node(tQueue *queue, tQueueNode *target, int data_type)
{
    int location = (target->type)? ((tQueueLarge*)target->content)->location : ((tQueueSmall*)target->content)->location;;
    int target_id = (target->type) ?((tQueueLarge*)target->content)->id : ((tQueueSmall*)target->content)->id;
    
    if(queue->count == 1){
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
        our_free(data_type, location);
        printf("target type: %d, location: %d, id: %d\n", data_type, location, target_id);
        return;
    }

    // target is head
    if(target->prev == NULL){
        queue->front = target->next;
        target->next->prev = NULL;
    }
    // target is tail
    else if(target->next == NULL){
        queue->rear = target->prev;
        target->prev->next = NULL;
    }
    else{
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }   
    queue->count--;
    our_free(data_type, location);
    printf("target type: %d, location: %d, id: %d\n", data_type, location, target_id);
    if(target->next){
        int next_location = (target->next->type)? ((tQueueLarge*)target->next->content)->location : ((tQueueSmall*)target->next->content)->location;
        int next_id = (target->next->type)? ((tQueueLarge*)target->next->content)->id : ((tQueueSmall*)target->next->content)->id;
        printf("target next type: %d, location: %d, id: %d\n", target->next->type, next_location, next_id);
    }
    
    return 1;    
}

tQueueNode *find_target_node(tQueue *queue, int id, int data_type)
{
    int target_id;
    tQueueNode *target = queue->front;
    for(int i = 0; i < queue->count; i++){
        target_id = (target->type) ? ((tQueueLarge*)target->content)->id : ((tQueueSmall*)target->content)->id;
        if(target_id == id && target->type == data_type)
            return target;
        target = target->next;
    }
    return NULL;
}


void print_queue (tQueue *queue)
{
    int id;
    int location;
    tQueueNode *head = queue->front;

    printf("      type small queue: ");    
    for (int i = 0; i < queue->count; i++)
    {
        id = (head->type) ? ((tQueueLarge*)head->content)->id : ((tQueueSmall*)head->content)->id;
        location = (head->type) ? ((tQueueLarge*)head->content)->location : ((tQueueSmall*)head->content)->location;
        printf ("%d(%d,%d) ", id, head->type, location);
        head = head->next;
    }
    printf("\n");
}