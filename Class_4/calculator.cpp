#include <stdio.h>

int main() {
	int data1, data2;
	char operation;
	int result = 1;
	while(true) {
	printf("������ �Է��ϼ��� : ");
	scanf("%d%c%d", &data1, &operation, &data2);
		if (operation == '+') {
			result = data1 + data2;
		} else if (operation == '-') {
			result = data1 - data2;		
		} else if (operation == '*') {
			result = data1 * data2;
		}else if (operation == '/') {
			result = data1 / data2;
		}else if (operation == '^') {
			for (int recur = 0; recur < data2; recur++){
				result = result * data1; //������ ������ result *= data1
			}
		}
	printf("%d %c %d = %d �Դϴ�\n", data1, operation, data2, result);
	result = 1;	
	}
return 0; 
}
