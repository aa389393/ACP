#ifndef __QUEUE__
#define __QUEUE__

typedef struct type_small {
    int id;
    int score;
    int location;
}tQueueSmall; 

typedef struct type_large {
    int id;
    int score[8];
    int location;
}tQueueLarge; 

typedef struct node_info{
    int type;
    void *content;
    struct node_info *next;
    struct node_info *prev;
}tQueueNode;

typedef struct {
    tQueueNode *front;
    tQueueNode *rear;
    int count;
}tQueue;

tQueue* createQueue(void);

int tqueue_enqueue(tQueue *queue, int, int, int);
int dequeue_type_node(tQueue *queue, tQueueNode *target, int data_type);
tQueueNode *find_target_node(tQueue *queue, int id, int data_type);

void print_queue(tQueue *queue);

#endif