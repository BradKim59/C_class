#include <stdio.h>

int main() {
	//상수는 전부 대문자로 선언, 공백은 언더바로 표현하는것이 룰이다. 
	const float RATE_USD = 1233.1; //1233.1을 구별하기 쉽게 하기 위헤 변수설정해서 상수를 사용한다. 
	int inputWon = 50000;
	float outputDollar = 0;
	outputDollar = inputWon / RATE_USD; 
	
	printf("%d원 -> %10.2f달러\n", inputWon, outputDollar);
	return 0;
}
