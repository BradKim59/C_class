#include <stdio.h>

int main() {
	int num = 0;
	int count;
	//1에서 100까지의 합은?
	printf("1에서 n까지의 합은?\n");
	printf("N을 입력하세요 : ");
	scanf("%d", &count);
	for (int loop = 1; loop <=count; loop++){
		num = num+loop;
	} 
	printf("1에서 %d까지의 합은 %d 입니다.",count ,num);
}
