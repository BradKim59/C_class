#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1; 
	int inputWon = 50000;
	float outputDollar = inputWon / RATE_USD; 

	//�Ǽ��� ������ ��ȯ�ؼ� �Ҽ��� ����. 
	int in_outputDollar = outputDollar;
	
	//������ ���� �Ǽ��� ȯ���� ���ؼ� �ܵ��� ���ϰ�, �޷��� ��ȭ�� ���� 
	int changeWon = (outputDollar - in_outputDollar) * RATE_USD;
	
	//��ȭ �ܵ� + ��ȭ ȯ����(ȯ���ݾ�*ȯ��) ���ؼ� ���ݸ´��� ��. 
	float dollarTotal = (in_outputDollar * RATE_USD);
	float total = (float)(changeWon) + (in_outputDollar * RATE_USD);
	printf("%d�� ->%5d�޷�,   �Ž�����%d��, �޷�����%f,   �հ�%f�� \n", inputWon, in_outputDollar, changeWon, dollarTotal, total);
	return 0;
}
