#include <stdio.h>

int main() {
	int num = 0;
	//1에서 100까지의 합은?
	printf("1에서 100까지의 합은?");
	for (int count = 1; count <=100; count++){
		num = num+count;
	} 
	printf("1에서 100까지의 합은 %d 입니다.", num);
}
