#include "space.h"


unsigned char buffer[SMALL_ELEMENT_SIZE*NUM_SMALL_BYTE_BUF + LARGE_ELEMENT_SIZE*NUM_LARGE_BYTE_BUF];

unsigned char byte_small_buf_mask = 0;
unsigned char byte_large_buf_mask = 0;

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

    mask = 0x80;
    printf ("      byte_large_buf_mask: ");
    for (i = 0; i< NUM_SMALL_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_large_buf_mask & mask) >> (7-i));
        mask = mask >> 1;
    }

    printf ("\n\n");
}

void  our_malloc(int type, void **target, int *mem_location)
{
    int location;
    if (byte_small_buf_mask == MASK_FULL && byte_large_buf_mask == MASK_FULL){
        return;
    }

    // TYPE_SMALL
    else if (type == TYPE_SMALL)
    {
        // use small mask (use one space in small mask)
        if(byte_small_buf_mask != MASK_FULL){
            location = test_single_location(byte_small_buf_mask, NUM_SMALL_BYTE_BUF);
            set_single_bit(&byte_small_buf_mask, location);
            *target = &buffer[location * SMALL_ELEMENT_SIZE];
        }
        // use large mask (use one space in large mask)
        // byte_small_buf_mask == SMALL_FULL
        else{
            location = test_single_location(byte_large_buf_mask, NUM_LARGE_BYTE_BUF);
            set_single_bit(&byte_large_buf_mask, location);
            *target = &buffer[LARGE_START + (location * LARGE_ELEMENT_SIZE)];
            location += 8;
        } 
        *mem_location = location;   
    }
    // TYPE_LARGE
    else
    {
        // use large mask (use one space in large mask)
        if(byte_large_buf_mask != MASK_FULL){
            location = test_single_location(byte_large_buf_mask, NUM_LARGE_BYTE_BUF);
            set_single_bit(&byte_large_buf_mask, location);
            *target = &buffer[LARGE_START + (location * LARGE_ELEMENT_SIZE)];
            location += 8;
            
        }
        // use small mask (use two space in small mask)
        // byte_large_buf_mask == SMALL_FULL
        else{
            location = test_dual_location(byte_small_buf_mask, NUM_SMALL_BYTE_BUF);
            // have two sequencial memory space in small mask
            if (location >= 0)
            {
                set_dual_bit(&byte_small_buf_mask, location);
                *target = &buffer[location * SMALL_ELEMENT_SIZE];
            }
            else
            {
                return;
            }
        }    
        *mem_location = location;
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
        if(mem_location < 8){
            clear_single_bit(&byte_small_buf_mask, mem_location);
        }
        else
            clear_single_bit(&byte_large_buf_mask, mem_location - 8);
    }
    else if (type == TYPE_LARGE)
    {
        if(mem_location > 7){
            clear_single_bit(&byte_large_buf_mask, mem_location - 8);
        }
        else
            clear_dual_bit(&byte_small_buf_mask, mem_location);
    }
}
