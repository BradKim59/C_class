#include <stdio.h>

int main() {
	//1. 입력한 값이 홀수인지 짝수인지를 판별하는 프로그램을 작성하시오.
	int num;
	printf("숫자입력 : ");
	scanf("%d", &num);
	if (num %2 == 0) {
		printf("짝수 입니다.");
	} else {
		printf("홀수 입니다.");
	}
	return 0;
}

