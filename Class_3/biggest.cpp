#include <stdio.h>

int main() {
	//3. 5���� ���ڸ� �Է� �޾� ���� ���� ����ϴ� ���α׷� �ۼ�
	int max = 0;
	int min = 0;
	int arrNum[5];
	char alph[] = {'A', 'B', 'C', 'D', 'E'};
	for (int i = 0; i<sizeof(alph)/sizeof(char); i++) {
		printf("���� %c �Է� : ", alph[i]);
		scanf("%d", &arrNum[i]);
		if (i == 0) {
			max = arrNum[0];
			min = arrNum[0];
		} else {
			if (max < arrNum[i]) {
			max = arrNum[i];
		}
			if (min > arrNum[i]) {
			min = arrNum[i];
		}
		}
	}
	printf("�ִ밪�� %d �Դϴ�.\n", max);
	printf("�ּҰ��� %d �Դϴ�.\n", min);

	return 0;
}

