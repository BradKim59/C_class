#include <stdio.h>

int main() {
	//����� ���� �빮�ڷ� ����, ������ ����ٷ� ǥ���ϴ°��� ���̴�. 
	const float RATE_USD = 1233.1; //1233.1�� �����ϱ� ���� �ϱ� ���� ���������ؼ� ����� ����Ѵ�. 
	int inputWon = 50000;
	float outputDollar = 0;
	outputDollar = inputWon / RATE_USD; 
	
	printf("%d�� -> %10.2f�޷�\n", inputWon, outputDollar);
	return 0;
}
