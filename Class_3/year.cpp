#include <stdio.h>

int main() {
	//4. 윤년인지 아닌지를 판단하는 프로그램 작성
	int year;
	printf("원하는 년도를 입력하세요 : ");
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0) {
			printf("윤년 입니다.");
		} else if (year%400 == 0) {
			printf("윤년 입니다.");
		} else {
			printf("윤년이 아닙니다.");		
		} 
	return 0;
}

