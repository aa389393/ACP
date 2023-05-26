#include "space.h"

tTypeScore score_buf[N]; //preallocated memory space

void get_score_space(tTypeScore **pp_score){
    int idx;
    for(int i = 0; i < N; i++){
        *pp_score = &score_buf[i];
        if(((*pp_score)->used) == 0){
            (*pp_score)->used = 1;
            (*pp_score)->loc = i;
            idx = i;   
	        printf("     get_score_space(): giving space numbered %d\n", idx);
            return;
        }      
    }

}

void return_score_space (int loc){
    score_buf[loc].used = 0;
    score_buf[loc].score = 0;
    printf("     return_score_space(): return space numbered %d\n", loc);
}
