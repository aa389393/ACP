#include "space.h"


unsigned char buffer[SMALL_ELEMENT_SIZE*NUM_SMALL_BYTE_BUF];

unsigned char byte_small_buf_mask = 0;


void print_buffer_status (void)
{
    int i;
    unsigned char mask = 0x80;
  
    printf ("      byte_small_buf_mask: ");
    for (i = 0; i< NUM_SMALL_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_small_buf_mask & mask) >> (7-i));
        mask = mask >> 1;
    }

    printf ("\n");
}

void  our_malloc(int type, void **target, int *mem_location)
{
    int location;
    if (byte_small_buf_mask == SMALL_FULL){
        return;
    }
    else if (type == TYPE_SMALL)
    {
        location = test_single_location(byte_small_buf_mask, NUM_SMALL_BYTE_BUF);
        set_single_bit(&byte_small_buf_mask, location);
        *target = &buffer[location * SMALL_ELEMENT_SIZE];
        *mem_location = location;
    }
    else
    {

        location = test_dual_location(byte_small_buf_mask, NUM_SMALL_BYTE_BUF);
        if (location >= 0)
        {
            set_dual_bit(&byte_small_buf_mask, location);
            *target = &buffer[location * SMALL_ELEMENT_SIZE];
            *mem_location = location;
        }
        else
        {
            return;
        }
    }    
}

int test_single_location(unsigned char mask, int mask_length){
    unsigned char temp = 0x01;
    for(int i = 0; i < mask_length; ++i){
        if(!(mask & temp)){
            return i;
        }
        temp <<= 1;
    }

}

void set_single_bit(unsigned char *mask, int location){
    unsigned char set = 0x01;
    for(int i = 0; i < location; ++i){
        set <<= 1;
    }
    *mask |= set;
}

int test_dual_location(unsigned char mask, int mask_length){
    unsigned char temp = 0x03;
    for(int i = 0; i < mask_length-1; ++i){
        if(!(mask & temp)){
            return i;
        }
        temp <<= 1;
    }
    return -1;
}

void set_dual_bit(unsigned char *mask, int location){
    unsigned char set = 0x03;
    for(int i = 0; i < location; ++i){
        set <<= 1;
    }
    *mask |= set;

}

void clear_single_bit(unsigned char *mask, int location){
    unsigned char clear = 0x01;
    for(int i = 0; i < location; ++i){
        clear <<= 1;
    }
    *mask &= (~clear); 
}

void clear_dual_bit(unsigned char *mask, int location){
    unsigned char clear = 0x03;
    for(int i = 0; i < location; ++i){
        clear <<= 1;
    }
    *mask &= (~clear); 
}

void  our_free(int type, int mem_location)
{
    if (type == TYPE_SMALL)
    {
        clear_single_bit(&byte_small_buf_mask, mem_location);
    }
    else if (type == TYPE_LARGE)
    {
        clear_dual_bit(&byte_small_buf_mask, mem_location);
    }
}
