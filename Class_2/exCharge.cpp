#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1; 
	int inputWon = 50000;
	float outputDollar = inputWon / RATE_USD; 

	//실수를 정수로 변환해서 소수점 버림. 
	int in_outputDollar = outputDollar;
	
	//정수를 빼고 실수에 환율을 곱해서 잔돈을 구하고, 달러를 원화로 변경 
	int changeWon = (outputDollar - in_outputDollar) * RATE_USD;
	
	//원화 잔돈 + 원화 환전액(환전금액*환율) 더해서 원금맞는지 비교. 
	float dollarTotal = (in_outputDollar * RATE_USD);
	float total = (float)(changeWon) + (in_outputDollar * RATE_USD);
	printf("%d원 ->%5d달러,   거스름돈%d원, 달러원금%f,   합계%f원 \n", inputWon, in_outputDollar, changeWon, dollarTotal, total);
	return 0;
}
