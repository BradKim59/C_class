#include <stdio.h>

int main() {
	int num = 0;
	int dan;
	//1에서 100까지의 합은?
	printf("몇 단을 보시겠습니까? : ");
	scanf("%d", &dan);
	for (int loop = 1; loop < 10; loop++){
		num = dan*loop;
		printf("%d * %d = %d\n",dan ,loop, num);

	} 
}
