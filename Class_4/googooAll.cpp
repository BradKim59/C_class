#include <stdio.h>

int main() {
	int num = 0;
	printf("====±¸±¸´Ü====\n");
	for (int dan = 2; dan <10; dan++){
		for (int loop = 1; loop < 10; loop++){
			num = dan*loop;
			printf("%d * %d = %d\n",dan ,loop, num);
			if (loop == 9){
				printf("\n");
			} 
		}
	} 
}
