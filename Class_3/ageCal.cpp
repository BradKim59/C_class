#include <stdio.h>
#include <time.h>

int main() {
	time_t timer = time(NULL);
	struct tm tm = *localtime(&timer);
	
	int koAge;
	int manAge;
	int personCode;
	int year;
	int month;
	int date;
	
	printf("%d",tm.tm_year);
	printf("주민번호 앞자리 입력:");
	scanf("%d", &personCode);
	
	year = personCode/10000;
	month = personCode/100%100;
	date = personCode%100;
	if (year < 23) {
		year = year + 100;
	}
	koAge = tm.tm_year - year +1;

	manAge = tm.tm_year - year;
	if (year < tm.tm_year && month < tm.tm_mon+1) {
		manAge + 1;
	} else if (year < tm.tm_year && month < tm.tm_mon+1 && date < tm.tm_mday) {
		manAge + 1;
	} else if (year < tm.tm_year && month > tm.tm_mon+1){
		manAge - 1;
	} else if (year < tm.tm_year && month >= tm.tm_mon+1 && date > tm.tm_mday){
		manAge - 1;
	}
	printf("오늘(%d년 %d월 %d일)기준 나이는 %d세, 만 나이는 %d세 입니다.", 
	tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, koAge, manAge);
	return 0;
}
