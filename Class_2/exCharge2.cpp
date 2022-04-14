#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1; //환율 
	int inputWon = 50000; //원금 
	int returnWon = 0;
	int outputDollarFinal = 0; //정슈형 형변환하기 
	float outputDollar = 0; //달러 환전액 실수형
	
	outputDollar = inputWon / RATE_USD; //환전계산 
	printf("%f", outputDollar); 
	outputDollarFinal = outputDollar; //환전액 정수형 형변환 
	
	returnWon = outputDollar*100;  // 40.54 *100
	printf("%d원 거스름돈 \n", returnWon);
	returnWon = returnWon%100; // 4054%100 = 54
	printf("%d원 거스름돈 \n", returnWon);
	returnWon = returnWon*RATE_USD /100; // 54*환율/100 = 665
	printf("%d원 거스름돈 \n", returnWon);
	returnWon = returnWon/10*10; // 1원자리 절삭 
	printf("%d원 거스름돈 \n", returnWon);

	printf("%d원 ->%d달러환전\n", inputWon, outputDollarFinal);
	printf("%d원 거스름돈 \n", returnWon);
	return 0;
}
