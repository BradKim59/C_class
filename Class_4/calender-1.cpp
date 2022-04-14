#include <stdio.h>

int main() {
	int year = 2000, month = 3, day = 1;
	int days = 0;
	int dayOfWeek;
	int leapYearCount = 0;
	
	//�� ���� ��������?? (�� �ܰ迡�� �� ���� �� �⺰ 1/1�� ��츦 ���� ����.)
	days = (year-1900)*365;
	for (int index = 1900; index < year; index++ ) {
		if (index % 4 == 0 && index % 100 != 0 || index%400 == 0) {//���� 
			leapYearCount++;
		}
	}
	days += leapYearCount; 
	
//	if (index % 4 == 0 && index % 100 != 0 || index%400 == 0) {//���� 
	
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
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//���� 
				days += 29;		
			}else{
				days += 28;
			}
		case 1 :
			days += 31;

	}

	dayOfWeek = days % 7;
	
	printf("%d", dayOfWeek);
	
	// �� ���鰹���� ����� ���� �� ���� ��~��(0-6) --> ��-��(0-6) 
	dayOfWeek++;// ��~�� �ذ�, ��~��(0~6) -> ��~�� (1~7) 
	if (dayOfweek == 7) {//��~�� (0~6) 
		dayOfWeek = 0;
	} 
	// Ÿ��Ʋ ��� 
	printf("%5s%5s%5s%5s%5s%5s%5s", "��", "��", "ȭ", "��", "��", "��", "��"); 
	// �������
	for (int index = 0; index < dayOfWeek; index++) {
		printf("%5c", ' ');
	} 
	// �޷����
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
