#include <stdio.h>

int main() {
	int year;
	int month;
	int days = 0;
	int dayOfWeek; 
	const char *day [7] = {"일","월","화","수","목","금","토"};
	int monthNor [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int monthLun [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	
	//압력값 받는 반복문 
	while (true) {
		//년도와 월을 데이터로 받는다 
		printf("년도 입력 : ");
		scanf("%d", &year); 
		//년도가 날짜범위 밖인경우 
		if (year < 1900) {
			printf("종료합니다"); 
			break;
		}
		printf("월 입력 : ");
		scanf("%d", &month); 
		//월이 날짜범위 밖인경우 
		if (month <= 0 || month > 12) {
			printf("종료합니다"); 
			break;
		}
		
		//테이블 출력 
		printf("=================== %d년 %2d월 ===================\n", year, month);
		for (int i = 0; i < 7 /*sizeof(day)/sizeof(char)*/; i++ ) {
		printf("%s\t", day[i]); 	
		}
		printf("\n");
		// 년일수 계산하기 
		for (int yearBal = 1900; yearBal < year; yearBal++ ) {
			if (yearBal % 4 == 0 && yearBal % 100 != 0 || yearBal%400 == 0) {
				days = days + 366;
			} else {
				days = days + 365;			
			}
		}
//		printf("연일수%d\n", days);
		//월일수 계산하기 
		for (int monthBal = 1; monthBal<month; monthBal++) {
			if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
				days = days + monthLun[monthBal-1];
			} else {
				days = days + monthNor[monthBal-1];			
			}
		}
//		printf("연+월일수%d\n", days);
		
		//0부터 시작하는 요일숫자 구하기 
		dayOfWeek = days%7;
		printf("%d\n", dayOfWeek);
	
		//월 첫 날짜시작부분 찍기
		for (int startDate = 0; startDate <= dayOfWeek; startDate++){
			if (dayOfWeek == 6){//일요일부터 날짜가 시작하는 경우 
				break;
			} else {
			printf("\t");
			}
		} 
		//윤달일 경우 계산하기
		if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
		for (int date = 1; date <= monthLun[month-1]; date+= 7) {
			for (int addDate = 0; addDate < 7; addDate++) {
				if (date + addDate > monthLun[month-1]) {
					break;
					}
					printf("%d\t", date+addDate);
					if ((dayOfWeek+1 + date + addDate) %7 == 0){
					printf("\n");
					}
				}
			}
		//평달일 경우 계산하기 
		} else {
			for (int date = 1; date <= monthNor[month-1]; date+= 7) {
				for (int addDate = 0; addDate < 7; addDate++) {
					if (date + addDate > monthNor[month-1]) {
						break;
					}
					printf("%d\t", date+addDate);
					if ((dayOfWeek+1 + date + addDate) %7 == 0){
					printf("\n");
					}
				}
			}
		}
		//기존달력 칸 띄우기 
		printf("\n\n\n");
	} 
	return 0;
}

 
