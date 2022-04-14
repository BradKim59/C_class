#include <stdio.h>

int main() {
	//2. 두 개의 숫자를 입력 받아 큰 수를 출력하는 프로그램 작성
	int num1;
	int num2;
	printf("숫자 A 입력 : ");
	scanf("%d", &num1);
	printf("숫자 B 입력 : ");
	scanf("%d", &num2);
	if (num1 > num2) {
		printf("큰 숫자는 %d 입니다.", num1);
	} else if (num1 < num2) {
		printf("큰 숫자는 %d 입니다.", num2);
	} else {
		printf("숫자가 같습니다.");		
	}
	return 0;
}

