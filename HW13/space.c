#include "space.h"


unsigned char buffer[NUM_BYTE_BUF * UNIT_ELEMENT_BUF];

bool buf_mask[NUM_BYTE_BUF] = {0};


void print_buffer_status (void){
    printf ("      buf_mask: ");
    for(int i = NUM_BYTE_BUF - 1; i >= 0; i--){
        printf ("%d ", buf_mask[i]);
        if(i % 8 == 0)
            printf(",");
    }
    printf ("\n");
}

void  our_malloc(int size, void **target, int *mem_location){
    int location;
    if (check_mask_full(buf_mask)){
        return;
    }
    else{
        location = test_type_location(buf_mask, size, NUM_BYTE_BUF);

        if (location >= 0){
            set_type_bit(buf_mask, size, location);
            *target = &buffer[location * UNIT_ELEMENT_BUF];
            *mem_location = location;
        }
        else{
            return;
        }
    }    
}

int test_type_location(bool *mask, int size, int mask_length){
    int count = 0;
    for(int i = 0; i < mask_length; i++){
        if(mask[i] == 0){
            count = 0;
            for(int j = i; j < i + size && j < mask_length; j++){
                if(mask[j] == 0){
                    count++;
                }
                // printf("j = %d count = %d\n", j, count);
                if(!count){
                    i = i + j;
                    break;
                }
            }
            if(count == size)
                return i;
        }
    }
    return -1;
}

int check_mask_full(bool *mask){
    int count = 0;
    for(int i = 0; i < NUM_BYTE_BUF; ++i){
        count += mask[i];    
    }
    return (count == NUM_BYTE_BUF) ? 1 : 0;
}

void set_type_bit(bool *mask, int size, int location){
    for(int i = location; i < location + size; i++){
        mask[i] = 1;
    }
}
void clear_type_bit(bool *mask, int size, int location){
    for(int i = location; i < location + size; i++){
        mask[i] = 0;
    }
}

void  our_free(int type, int mem_location){
    clear_type_bit(buf_mask, type, mem_location);
}






