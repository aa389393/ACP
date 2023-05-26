#include "stack.h"

tStack *create_stack(void){
    tStack *stack = (tStack*)malloc(sizeof(tStack));
    stack->head = NULL;
    stack->count = 0;
    return stack;
}

void handle_push_operation(tStack *stack_ptr)
{
    tNode* new_node = (tNode*)malloc(sizeof(tNode));
    int score;
	  
    if(stack_ptr->count == N){
	    printf ("[Error]  handle_push_operation(): space full \n");
        return;
    }
    printf("  handle_push_operation(): enter score value: ");
    scanf("%d", &score);
    get_score_space(&new_node->data_ptr);
    new_node->data_ptr->score = score;
    if(stack_ptr->count > 0){
        new_node->next = stack_ptr->head;
    }
    stack_ptr->head = new_node;
    stack_ptr->count++;
    
}

void handle_pop_operation(tStack *stack_ptr){
    if(stack_ptr->count == 0){
	    printf ("[Error]  handle_pop_operation(): nothing in stack \n");
        return;
    }
	printf("  handle_pop_operation(): poped value: %d\n", stack_ptr->head->data_ptr->score);
    tNode *tmp = stack_ptr->head;
    stack_ptr->head = tmp->next;
    stack_ptr->count--;
    free(tmp);
	return_score_space(stack_ptr->count);
}

void print_stack_content(tStack *stack_ptr){
    tNode *new_stack = stack_ptr->head;
    printf("   print_stack_content(): stack items -> ");
    for(int i = 0; i < stack_ptr->count; i++){
        printf("%d(%d) -> ", new_stack->data_ptr->score, new_stack->data_ptr->loc);
        new_stack = new_stack->next; 
    }
    printf("\n\n");
}

