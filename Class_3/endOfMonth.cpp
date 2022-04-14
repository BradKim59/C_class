#include <stdio.h>

int main() {
	//5. 입력한 년도의 각 월의 마지막 날을 출력하기
	
	int month [12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int monthNor [12] = {31,28,31,30,31,31,30,31,30,31,30,31};
	int monthLun [12] = {31,29,31,30,31,31,30,31,30,31,30,31};
	
	int year;
	printf("원하는 년도를 입력하세요 : ");
	scanf("%d", &year);
	printf("%d년은 다음과 같습니다.\n", year);

	if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
		for (int i = 0; i < 12; i++) {
			printf("%d월 : %d일\n", month[i], monthLun[i]);		
		}
	} else {
		for (int i = 0; i < 12; i++) {
			printf("%d월 : %d일\n", month[i], monthNor[i]);		
		}
	} 
	return 0;
}

