#ifndef __SPACE__
#define __SPACE__

#include "main.h"

#define NUM_BYTE_BUF      23
#define UNIT_ELEMENT_BUF  32

int check_mask_full(bool *);
void print_buffer_status(void);
void our_malloc(int, void **, int *);
void our_free(int, int);  //todo
int test_type_location(bool *, int, int);
void set_type_bit(bool *, int, int);
void clear_type_bit(bool *, int, int);


// int test_dual_location(unsigned char mask, int mask_length);
// void set_dual_bit(unsigned char *mask, int location);
// void clear_dual_bit(unsigned char *mask, int location);

#endif