#include <stdio.h>

int main() {
	//5. �Է��� �⵵�� �� ���� ������ ���� ����ϱ�
	
	int month [12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int monthNor [12] = {31,28,31,30,31,31,30,31,30,31,30,31};
	int monthLun [12] = {31,29,31,30,31,31,30,31,30,31,30,31};
	
	int year;
	printf("���ϴ� �⵵�� �Է��ϼ��� : ");
	scanf("%d", &year);
	printf("%d���� ������ �����ϴ�.\n", year);

	if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
		for (int i = 0; i < 12; i++) {
			printf("%d�� : %d��\n", month[i], monthLun[i]);		
		}
	} else {
		for (int i = 0; i < 12; i++) {
			printf("%d�� : %d��\n", month[i], monthNor[i]);		
		}
	} 
	return 0;
}

