#include <stdio.h>

int main() {
	int num = 0;
	int count;
	//1���� 100������ ����?
	printf("1���� n������ ����?\n");
	printf("N�� �Է��ϼ��� : ");
	scanf("%d", &count);
	for (int loop = 1; loop <=count; loop++){
		num = num+loop;
	} 
	printf("1���� %d������ ���� %d �Դϴ�.",count ,num);
}
