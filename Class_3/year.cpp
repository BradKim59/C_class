#include <stdio.h>

int main() {
	//4. �������� �ƴ����� �Ǵ��ϴ� ���α׷� �ۼ�
	int year;
	printf("���ϴ� �⵵�� �Է��ϼ��� : ");
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0) {
			printf("���� �Դϴ�.");
		} else if (year%400 == 0) {
			printf("���� �Դϴ�.");
		} else {
			printf("������ �ƴմϴ�.");		
		} 
	return 0;
}

