#ifndef __QUEUE__
#define __QUEUE__

typedef struct queue_node {
    int id;
    // int score;
    int location;
    int mem_size;
    struct queue_node *next;
    struct queue_node *prev;
}tQueueNode; 

typedef struct {
    tQueueNode *front;
    tQueueNode *rear;
    int count;
    int total_size;
}tQueue;


tQueue* createQueue(void);

int enqueue_node(tQueue *queue, int id, int mem_size);
int dequeue_node(tQueue *queue, tQueueNode *target);
tQueueNode *find_target_node(tQueue *queue, int id);
void print_queue(tQueue *queue);

#endif