#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TOTAL 200

// convert binary to decimal callback function
int conv_b2d (char x, int len){
    int tmp = x - 48;
    return (tmp * pow(2, len));
}
// convert hex to decimal callback function
int conv_h2d (char x, int len){
    int tmp;
    if(x >= '0' && x <= '9'){
        tmp = x - 48;
    }
    else if(x >= 'a' && x <= 'f'){
        tmp = x - 97 + 10;
    }
    else if(x >= 'A' && x <= 'F'){
        tmp = x - 65 + 10;
    }
    return (tmp * pow(16, len));
}

void Conv2Dec(char *buf, int length, int (*comp)(char , int)){
    int i;
    int result = 0;

    for (i = 0; i < length; i++){
        result += comp(buf[i + 1], (length - i - 1));
    }
    printf(" Result = %d\n", result);
}

int main (void){
    int flag;
    char *buf = (char *)malloc(sizeof(char) * TOTAL);
    int (*func[])(char, int) = {conv_b2d, conv_h2d};

    while (1){        
        printf("  Please enter a string: ");
        scanf("%s", buf);
        int len = strlen(buf);
        flag = (buf[0] == 'h') ? 1 : 0;
        Conv2Dec(buf, len - 1, func[flag]);
    }
}
