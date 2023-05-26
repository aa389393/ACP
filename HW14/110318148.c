#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4
typedef char my_int[MAX];

int my_add(my_int, my_int, my_int);
void my_number_print(my_int);
void pre_processing(my_int);
void initial(my_int);

int main(){
    my_int input1;
    my_int input2;
    my_int ans;
    int res;
    while(1){

        // initialize input
        initial(input1);
        initial(input2);
        
        
        printf("Please give a number less than %d: ", MAX);
        for(int i = 0; i < MAX; i++){
            scanf("%c", &input1[i]);
            if(input1[i] == '\n'){
                break;
            }
        }
        fflush(stdin);
        printf("Please give another number less than %d: ", MAX);
        for(int i = 0; i < MAX; i++){
            scanf("%c", &input2[i]);
            if(input2[i] == '\n'){
                break;
            }
        }
        fflush(stdin);
        pre_processing(input1);
        pre_processing(input2);
        res = my_add(ans, input1, input2);
        if(res != 0){
            my_number_print(ans);
        }
    }
}
void my_number_print(my_int ans){
    printf("ans = ");
    int idx;
    for(int i = 0; i < MAX; i++){
        if(ans[i] > 48){
            idx = i;
            break;
        }
        else    
            idx = MAX - 1;
    }

    for(int i = idx; i < MAX; i++){
        printf("%c", ans[i]);
    }
    printf("\n");
}
int my_add(my_int ans, my_int input1, my_int input2){
    int carry = 0;
    for(int i = MAX - 1; i >= 0; i--){
        ans[i] = carry + input1[i] + input2[i] - 48;
        carry = 0;
        if(ans[i] > 57){
            if(i == 0){
                printf("Overflow!\n");
                return 0;
            }
            carry = 1;
            ans[i] -= 10;
        } 
    }
    return 1;
    
}
void pre_processing(my_int input){
    my_int tmp;
    int count = 0;
    for(int i = 0; i < MAX; i++){
        if(input[i] == 10){
            input[i] = 48;
            count++;
        }
    }
    for(int i = 0; i < MAX; i++){
        tmp[i] = 48;
    }
    for(int i = 0; i < MAX; i++){
        tmp[i + count] = input[i];
    }
    for(int i = 0; i < MAX; i++){
        input[i] = tmp[i];
    }
}
void initial(my_int input){
    for(int i = 0; i < MAX; i++){
        input[i] = 10;
    }
}
