#include <stdio.h>

int main() {
	//2. �� ���� ���ڸ� �Է� �޾� ū ���� ����ϴ� ���α׷� �ۼ�
	int num1;
	int num2;
	printf("���� A �Է� : ");
	scanf("%d", &num1);
	printf("���� B �Է� : ");
	scanf("%d", &num2);
	if (num1 > num2) {
		printf("ū ���ڴ� %d �Դϴ�.", num1);
	} else if (num1 < num2) {
		printf("ū ���ڴ� %d �Դϴ�.", num2);
	} else {
		printf("���ڰ� �����ϴ�.");		
	}
	return 0;
}

