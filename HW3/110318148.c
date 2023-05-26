#include <stdlib.h>
#include <stdio.h>

typedef struct num_list{
    int count;
    int *p_list;
} tNumList;


// print list function
void Print_list(tNumList *list){
    for(int i = 0; i < list->count; i++){
        printf("%d ", list->p_list[i]);
    }
    printf("\n");
}


// bubble sort function
void bubble_sort(tNumList *list){
    int tmp;
    for(int i = 0; i < list->count; i++) {
        for(int j = 0; j < (list->count - i - 1); j++) {
            if(list->p_list[j] > list->p_list[j + 1]){
                tmp = list->p_list[j];
                list->p_list[j] = list->p_list[j + 1];
                list->p_list[j + 1] = tmp;
            }
        }
    }
}

// merge function
void merge(tNumList *list1, tNumList *list2){
    int index1 = 0;
    int index2 = 0;

    while(index1 < list1->count && index2 < list2->count){       
        if(list1->p_list[index1] <= list2->p_list[index2]){      // compare list1->p_list and list2->p_list
            printf(" %d " , list1->p_list[index1] );
            index1++;
        }
        else{
            printf(" %d " , list2->p_list[index2]);
            index2++;
        }
    }
    if(index1 != list1->count){
        for(int i = index1; i < list1->count; i++)
            printf(" %d ", list1->p_list[i]); 
    }
    else{
        for(int i = index2; i < list2->count; i++)
            printf(" %d ", list2->p_list[i]); 
    }
}

int main(){
    
    
    tNumList *list1, *list2;                                    // create two tNumList objects

    list1 = (tNumList*)malloc(sizeof(tNumList));                // create list1 size
    list2 = (tNumList*)malloc(sizeof(tNumList));                // create list2 size

    // --------------- list1 -------------------------------
    printf("Please enter how many numbers in list1 : ");
    scanf("%d", &(list1->count));                               // input the p_list size
    list1->p_list = (int*)malloc(sizeof(int)*list1->count);     // allocate the p_list size
    printf("\nPlease input %d numbers : ", list1->count);
    for(int i = 0; i < list1->count; i++){
        scanf("%d", &(list1->p_list[i]));                       // input the value of p_list
    }
    // -----------------------------------------------------
    // --------------- list2 -------------------------------
    printf("\nPlease enter how many numbers in list2 : ");
    scanf("%d", &(list2->count));
    list2->p_list = (int*)malloc(sizeof(int)*list2->count);
    printf("\nPlease input %d numbers : ", list2->count);

    for(int i = 0; i < list2->count; i++){
        scanf("%d", &(list2->p_list[i]));
    }
    // -----------------------------------------------------

    bubble_sort(list1);
    printf("\nlist1 : ");
    Print_list(list1);
    bubble_sort(list2);
    printf("\nlist2 : ");
    Print_list(list2);
    printf("\nmerge : ");
    merge(list1, list2);
    
    return 0;
}