#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 200

int comp_inc (char x, char y)
{
    return (x > y) ? 1 : 0;
}
int comp_dec (char x, char y)
{
    return (x > y) ? 0 : 1;
}

void bubble_sort(char *buf, int length, int (*comp)(char, char))
{
    int i, j;
    char tmp;

    for (i = 0; i< (length - 1); i++)
    {
        for (j = i; j< length; j++)
        {
            if (comp(buf[i], buf[j]))
            {
                tmp = buf[i];
                buf[i] = buf[j];
                buf[j] = tmp;   
            }
        }
    }
}

void print_result (char *buf)
{
    int i;
    printf("    Result: %s \n", buf);
}

int main (void)
{
    int i, flag, length;
    char *buf = (char *)malloc(sizeof(char) * TOTAL);
    int (*func[])(char, char) = {comp_inc, comp_dec};

    while (1)
    {        
        //menu 
        
        printf("Please enter (0) increasing or (1) descesing sort: ");
        scanf("%d", &flag);
        if (flag < 0 || flag > 1)
        {
            printf("ERROR: no such option! \n\n");
            continue;
        }
        
        
        printf("  Please enter a string: ");
        scanf("%s%n", buf, &length);
        printf("length = %d\n", length);
        //here you can modify to function pointer array()
        bubble_sort(buf, length - 1, func[flag]);
        print_result(buf);
    }
}
