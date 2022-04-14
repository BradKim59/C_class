#include <stdio.h>

int main() {
	int year = 2000, month = 3, day = 1;
	int days = 0;
	int dayOfWeek;
	int leapYearCount = 0;
	
	//몇 년이 지났는지?? (이 단계에서 월 전에 각 년별 1/1의 경우를 비교해 본다.)
	days = (year-1900)*365;
	for (int index = 1900; index < year; index++ ) {
		if (index % 4 == 0 && index % 100 != 0 || index%400 == 0) {//윤년 
			leapYearCount++;
		}
	}
	days += leapYearCount; 
	
//	if (index % 4 == 0 && index % 100 != 0 || index%400 == 0) {//윤년 
	
	switch(month) {
		case 12 :
			days += 31;
		case 11 :
			days += 30;
		case 10 :
			days += 31;
		case 9 :
			days += 30;
		case 8 :
			days += 31;
		case 7 :
			days += 31;
		case 6 :
			days += 30;
		case 5 :
			days += 31;
		case 4 :
			days += 30;
		case 3 :
			days += 31;
		case 2 :
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//윤년 
				days += 29;		
			}else{
				days += 28;
			}
		case 1 :
			days += 31;

	}

	dayOfWeek = days % 7;
	
	printf("%d", dayOfWeek);
	
	// 앞 공백갯수를 만들기 위한 값 변경 월~일(0-6) --> 일-토(0-6) 
	dayOfWeek++;// 월~토 해결, 월~일(0~6) -> 월~일 (1~7) 
	if (dayOfweek == 7) {//일~월 (0~6) 
		dayOfWeek = 0;
	} 
	// 타이틀 출력 
	printf("%5s%5s%5s%5s%5s%5s%5s", "일", "월", "화", "수", "목", "금", "토"); 
	// 공백출력
	for (int index = 0; index < dayOfWeek; index++) {
		printf("%5c", ' ');
	} 
	// 달력출력
	int returnCount = dayOfWeek+1;
	for (int index = 1; index <=31; index++) {
		printf("%5d", index);
		if (returnCount %7 == 0) {
			printf("\n");
		}
		returnCount++;
	}
	return 0; 
}
