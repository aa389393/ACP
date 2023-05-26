#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000

int main(){
    char *c = (char*)malloc(SIZE * sizeof(char));
    char *i, *j;
    int count = 0;
    printf("Please enter a character sequence: ");
    scanf("%s",c);

    for(i = c ; *i; i++){
        for(j = i + 1; *j; j++){
            if(*i > *j)
                count++;
        }
    }
   
    free(c);
    printf("number of inversions: %d\n",count);
    return 0;
}