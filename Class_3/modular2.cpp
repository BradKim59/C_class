#include <stdio.h>

int main() {
	//1. �Է��� ���� Ȧ������ ¦�������� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.
	int num;
	printf("�����Է� : ");
	scanf("%d", &num);
	if (num %2 == 0) {
		printf("¦�� �Դϴ�.");
	} else {
		printf("Ȧ�� �Դϴ�.");
	}
	return 0;
}

