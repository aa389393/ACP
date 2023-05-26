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
        location = test_single_location( ............ );
        set_single_bit(.............);
        *target = .............. ;
        *mem_location = location;
    }
    else
    {

        location = test_dual_location(............. );
        if (location >= 0)
        {
            set_dual_bit( .......... );


        }
        else
        {
            return;
        }
    }    
}

int test_single_location(int mask, int mask_length)
{
 





}

void set_single_bit(unsigned char *mask, int location)
{

}

int test_dual_location(int mask, int mask_length)
{









}

void set_dual_bit(unsigned char *mask, int location)
{


}

void clear_single_bit(unsigned char *mask, int location)
{

}

void clear_dual_bit(unsigned char *mask, int location)
{


}

void  our_free(int type, int mem_location)
{
    if (type == TYPE_SMALL)
    {

    }
    else if (type == TYPE_LARGE)
    {

    }
}
