#include <stdio.h>
typedef unsigned int Int32;

Int32 input;    /* example:   Int32 input = 0x80009000*/
Int32 high;     /*max value = 31*/
Int32 low;      /*min value = 0*/

int CheckRangeLoop(Int32, Int32, Int32);
int CheckRangeNoLoop(Int32, Int32, Int32);

int main(){
    int CRL;
    int CRNL;
    int again;
    while(1){
        printf("Please Specify the input: ");
        scanf("%x", &input);
        printf("    Please Specify the high: ");
        scanf("%d", &high);
        printf("    Please Specify the low: ");
        scanf("%d", &low);
        if((high < 32) && (low > -1)){
            CRL = CheckRangeLoop(input, high, low);
            CRNL = CheckRangeNoLoop(input, high, low);
            printf("CheckRangeLoop result: %d\n", CRL);
            printf("CheckRangeNoLoop result: %d\n", CRNL);
            printf("Enter 1 to leep trying the next round: ");
            scanf("%d", &again);
            if(!again){
                break;
            }
        }
        else{
            break;
        }
    }
}

int CheckRangeLoop(Int32 input, Int32 high, Int32 low){
    while(high > low){
        if(((input >> low) & 0x01) == 1){
            return 1;
        }
        else{
            low += 1;
        }
    }
    return 0;
}

int CheckRangeNoLoop(Int32 input, Int32 high, Int32 low){
    input = input >> low;
    input = input << low;
    input = input << (31 - high);
    if(input > 0){
        return 1;
    }
    return 0;
}