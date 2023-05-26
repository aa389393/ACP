#include <stdio.h>
int func(int x);
void foo(void);
int main(){
    // int a[] = {1, 2, 3, 4,5};
    // int *p = a;
    // *(p++) += 10;
    // *(++p) += 10;

    // for(int i= 0; i <5; i++){
    //     printf("%d ", a[i]);
    // }
    foo();
}
int func(int x){
    int count = 0;
    while(x){
        count++;
        x = x&(x-1);
    }
    return count;
}

void foo(void){
    unsigned int a = 6;
    int b = -20;
    printf("%d ", a + b);
}