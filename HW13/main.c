#include "main.h"
#include "queue.h"
#include "space.h"


int main (void){

    tQueue *queue;
    int operation;
    int mem_size;
    tQueueNode *node;
    int id, ret;
    queue = createQueue();

    while (1){
        printf("\nRemaining memory space %d\n", NUM_BYTE_BUF - queue->total_size);
        printf("\nWhich type you are going to operate? \n");
        printf("1. Add an item\n");
        printf("2. remove an item with a specific Id\n");
        scanf("%d", &operation);
        
        if (operation == 1){
            printf("  enter id:");
            scanf("%d", &id);
            printf("  specify data type (units) you want:");
            scanf("%d", &mem_size);
            ret = enqueue_node(queue, id, mem_size);
          
            if (ret == 0){
                printf("    Cannot enter to the queue  \n");
            }
            print_buffer_status();
        }
        else if (operation == 2){
            printf ("  enter an ID to remove ");
            scanf("%d", &id);
            node = NULL;
            node = find_target_node(queue, id);
            if (node == NULL){
                printf ("   cannot find the target node\n");
            }
            else{
                dequeue_node(queue, node);
            }
            print_buffer_status();

        }
        else{
            printf ("   no such operation\n");   
        }
        print_queue(queue);
    }

}
