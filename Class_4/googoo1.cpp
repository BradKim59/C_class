#include <stdio.h>

int main() {
	int num = 0;
	int dan;
	//1���� 100������ ����?
	printf("�� ���� ���ðڽ��ϱ�? : ");
	scanf("%d", &dan);
	for (int loop = 1; loop < 10; loop++){
		num = dan*loop;
		printf("%d * %d = %d\n",dan ,loop, num);

	} 
}
