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
	printf("�ֹι�ȣ ���ڸ� �Է�:");
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
	printf("����(%d�� %d�� %d��)���� ���̴� %d��, �� ���̴� %d�� �Դϴ�.", 
	tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, koAge, manAge);
	return 0;
}
