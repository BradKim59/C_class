#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1; //ȯ�� 
	int inputWon = 50000; //���� 
	int returnWon = 0;
	int outputDollarFinal = 0; //������ ����ȯ�ϱ� 
	float outputDollar = 0; //�޷� ȯ���� �Ǽ���
	
	outputDollar = inputWon / RATE_USD; //ȯ����� 
	printf("%f", outputDollar); 
	outputDollarFinal = outputDollar; //ȯ���� ������ ����ȯ 
	
	returnWon = outputDollar*100;  // 40.54 *100
	printf("%d�� �Ž����� \n", returnWon);
	returnWon = returnWon%100; // 4054%100 = 54
	printf("%d�� �Ž����� \n", returnWon);
	returnWon = returnWon*RATE_USD /100; // 54*ȯ��/100 = 665
	printf("%d�� �Ž����� \n", returnWon);
	returnWon = returnWon/10*10; // 1���ڸ� ���� 
	printf("%d�� �Ž����� \n", returnWon);

	printf("%d�� ->%d�޷�ȯ��\n", inputWon, outputDollarFinal);
	printf("%d�� �Ž����� \n", returnWon);
	return 0;
}
