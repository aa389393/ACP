#include "main.h"
#include "queue.h"
#include "space.h"


int main (void)
{
    tQueue *queue;
    int operation;
    tQueueNode *target_type_node;
    int id, score=0, ret;
    queue = createQueue();

    while (1)
    {

        printf("\nWhich type you are going to operate? \n");
        printf("1. Add a type 1 item\n");
        printf("2. Add a type 2 item\n");
        printf("3. remove a type 1 item with a specific Id\n");
        printf("4. remove a type 2 item with a specific Id\n");
        
        scanf("%d", &operation);
        
        if (operation == 1 || operation == 2)
        {
            printf("  enter id:");
            scanf("%d", &id);

            ret = tqueue_enqueue(queue, id, score, operation - 1);
          
            if (ret == 0)
            {
                printf("    \033[31m Cannot enter to the queue \033[0m\n");
            }
            print_buffer_status();
        }
        else if (operation == 3 || operation == 4)
        {
            printf ("  enter an ID to remove \n");
            scanf("%d", &id);
            target_type_node = NULL;
            target_type_node = find_target_node(queue, id, operation - 3);
            if (target_type_node == NULL)
            {
                printf ("    cannot find the target node \n");
            }
            else
            {
                dequeue_type_node(queue, target_type_node, operation - 3);
            }
            print_buffer_status();

        }
        else
        {
            printf ("    no such operation \n");   
        }
        print_queue(queue);
    }

}
