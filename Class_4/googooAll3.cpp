#include <stdio.h>
 
int main(void)
{  
    for (int start = 1; start < 4; start++){
        for (int loop = 1; loop < 10; loop++){
            for (int dan = 3 * start - 2; dan < 3 * start + 1; dan++){
                printf("%d * %d = %d\t", dan, loop, dan*loop);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}



