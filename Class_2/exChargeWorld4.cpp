#include <stdio.h>

	const float RATE_USD = 1233.1; //달러환율 
	const float RATE_YEN = 984.4; //엔화환율 
	const float RATE_EURO = 1342.64; //유로환율 
	const float RATE_RMB = 193.54; //중국환율 
	const float RATE_GBP = 1605.03; //영국환율
	float RATE = 0;//환율 대입할 변수 
	int inputWon = 50000; //원금 
	int returnWon = 0;
	int outputFinal = 0; //정슈형 형변환하기 
	float output = 0; //달러 환전액 실수형
	int returnWon1000; 
	int returnWon500; 
	int returnWon100; 
	int returnWon50; 
	int returnWon10; 
	int selectCon;

void Cal (float RATE, char nation []){
	output = inputWon / RATE; //환전계산 
	outputFinal = output; //환전액 정수형 형변환 
	returnWon = output*100;  // 40.54 *100
	returnWon = returnWon%100; // 4055%100 = 54
	returnWon = returnWon*RATE /100; // 54*환율/100 = 665
	returnWon = returnWon/10*10; // 1원자리 절삭
	printf("%s환전 원금 %d원 ->%d%s환전\n",nation, inputWon, outputFinal, nation);
	printf("거스름돈 : %d원\n", returnWon);
}

void Cal100 (float RATE, char nation []){
	//100엔기준으로 나눠서 내려간 자릿수 다시 100 곱해서 올려줌 
	output = (inputWon / RATE)*100; //환전계산 
	outputFinal = output; //5079
	returnWon = output*100; //5079.23 을 자릿수 살림 507923
	returnWon = returnWon%100; // 23
	//원화 변경 시, 1엔기준이 아니라, 100엔 기준으로 곱해서 계산해야 한다. 
	returnWon = returnWon*RATE /100; //23*984.4/100 = 226.412 
	returnWon = returnWon/10*10; // 1원자리 절삭 220
	printf("%s환전 원금 %d원 ->%d%s환전\n",nation, inputWon, outputFinal, nation);
	printf("거스름돈 : %d원\n", returnWon);
}


void Change (int returnWon){
	returnWon1000 = returnWon/1000;
	returnWon = returnWon - returnWon1000 * 1000;
	returnWon500 = returnWon/500;
	returnWon = returnWon - returnWon500 * 500;
	returnWon100 = returnWon/100;
	returnWon = returnWon - returnWon100 * 100;
	returnWon50 = returnWon/50;
	returnWon = returnWon - returnWon50 * 50;
	returnWon10 = returnWon/10;
	printf("1000원 %d개, 500원%d개, 100원%d개, 50원%d개, 50원%d개 \n", returnWon1000, returnWon500, returnWon100, returnWon50, returnWon10);
}

int main() {
	printf("환전을 원하는 원화 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	do {
		printf("환전을 원하는 외화를 선택 하세요(1:USD, 2:YEN, 3:EURO, 4:RMB, 5:GBP) : ");
		scanf("%d", &selectCon); 
		} while (selectCon<1 || selectCon>5);
			//달러 
			if (selectCon == 1) {
			RATE = RATE_USD;
			char nation[] = "달러";
			Cal(RATE, nation);
			}
			
			//엔화 
			else if (selectCon == 2) {
			RATE = RATE_YEN; //엔화는 100엔 기준으로 환율이  환산된다. 
			char nation[] = "엔화";
			Cal100(RATE, nation);
			}
			
			//유로 
			else if (selectCon == 3) {
			RATE = RATE_EURO;
			char nation[] = "유로";
			Cal(RATE,nation);
			}
			
			//중화  
			else if (selectCon == 4) {
			RATE = RATE_RMB;
			char nation[] = "중화";
			Cal(RATE, nation);
			}
			
			//영국 
			else if (selectCon == 5) {
			RATE = RATE_GBP;
			char nation[] = "영국";
			Cal(RATE, nation);
			}
		
		Change(returnWon);
		return 0;	
	}
	
