#include <stdio.h>
 
int main(void) {
	//3���� �� �ǳʶٱ� 
    for (int dan = 1; dan < 10; dan++){
    	if (dan %3 !=0) {
        for (int loop = 1; loop < 10; loop++){
            printf("%d * %d = %d\n", dan, loop, dan*loop);    		
			}
        printf("\n");
	    }
	}
    return 0;
}




