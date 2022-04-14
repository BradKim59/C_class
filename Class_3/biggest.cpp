#include <stdio.h>

int main() {
	//3. 5개의 숫자를 입력 받아 최저 값을 출력하는 프로그램 작성
	int max = 0;
	int min = 0;
	int arrNum[5];
	char alph[] = {'A', 'B', 'C', 'D', 'E'};
	for (int i = 0; i<sizeof(alph)/sizeof(char); i++) {
		printf("숫자 %c 입력 : ", alph[i]);
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
	printf("최대값은 %d 입니다.\n", max);
	printf("최소값은 %d 입니다.\n", min);

	return 0;
}

