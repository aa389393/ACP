#include "queue.h"
#include "space.h"


tQueue* createQueue(void){    
    tQueue *queue;
    queue=(tQueue *) malloc (sizeof(tQueue));
    if (queue){
        queue->front=NULL;
        queue->rear=NULL;  
        queue->count=0;
        queue->total_size = 0;
    }
    return queue;
}

int enqueue_node(tQueue *queue, int id, int mem_size){
    tQueueNode *newptr = NULL;
    int mem_location;
    our_malloc (mem_size, (void *)&newptr, &mem_location);
    if (newptr == NULL){
        printf("    Enqueue Failed!!!\n\n");
        return 0;
    }
    newptr->id = id;
    newptr->location = mem_location;
    newptr->mem_size = mem_size;
    newptr->next = NULL;
    newptr->prev = NULL;


    if(queue->count==0){
        queue->front = newptr;
    }
    else{
        newptr->prev = queue->rear;
        queue->rear->next = newptr; 
    }
    queue->rear = newptr;
    queue->count++;
    queue->total_size += mem_size;
   
    return 1;
}

int dequeue_node(tQueue *queue, tQueueNode *target){
    if(queue->count == 1){
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
        our_free(target->mem_size, target->location);
        queue->total_size -= target->mem_size;
        return 0;
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
    queue->total_size -= target->mem_size;
    our_free(target->mem_size, target->location);
    free(target);

    return 1;    
}

tQueueNode *find_target_node(tQueue *queue, int id){
    tQueueNode *target = queue->front;
    for(int i = 0; i < queue->count; i++){
        if(target->id == id)
            return target;
        target = target->next;
    }
    return NULL;
}


void print_queue (tQueue *queue){
    int i;
    tQueueNode *target = queue->front;

    printf("      type queue: ");    
    for (i = 0; i < queue->count; i++){
        printf ("%d(%d, %d) ", target->id, target->location, target->mem_size);
        target = target->next;
    }
    printf("\n");
}