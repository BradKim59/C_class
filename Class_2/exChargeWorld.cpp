#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1; //달러환율 
	const float RATE_YEN = 984.4; //엔화환율 
	const float RATE_EURO = 1342.64; //유로환율 
	const float RATE_RMB = 193.54; //중국환율 
	const float RATE_GBP = 1605.03; //영국환율
	float RATE = 0;//환율 대입할 변수 
	int inputWon = 50000; //원금 
	int returnWon1000; 
	int returnWon500; 
	int returnWon100; 
	int returnWon50; 
	int returnWon10; 
	printf("환전을 원하는 원화 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	 
	for (int i=0; i<5; i++) {
		switch (i) {
			//달러 
			case 0 : {
			RATE = RATE_USD;
			int returnWon = 0;
			int outputFinal = 0; //정슈형 형변환하기 
			float output = 0; //달러 환전액 실수형
			output = inputWon / RATE; //환전계산 
			outputFinal = output; //환전액 정수형 형변환 
			returnWon = output*100;  // 40.54 *100
			returnWon = returnWon%100; // 4055%100 = 54
			returnWon = returnWon*RATE /100; // 54*환율/100 = 665
			returnWon = returnWon/10*10; // 1원자리 절삭
			printf("달러환전 원금 %d원 ->%d달러환전\n", inputWon, outputFinal);
			printf("거스름돈 : %d원\n", returnWon);
			
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
			break;
			}
			
			//엔화 
			case 1 : {
			RATE = RATE_YEN; //엔화는 100엔 기준으로 환율이  환산된다. 
			int returnWon = 0;
			int outputFinal = 0; //정수형 형변환하기 
			float output = 0; //환전액 실수형
			//100엔기준으로 나눠서 내려간 자릿수 다시 100 곱해서 올려줌 
			output = (inputWon / RATE)*100; //환전계산 
			outputFinal = output; //5079
			returnWon = output*100; //5079.23 을 자릿수 살림 507923
			returnWon = returnWon%100; // 23
			//원화 변경 시, 1엔기준이 아니라, 100엔 기준으로 곱해서 계산해야 한다. 
			returnWon = returnWon*RATE /100; //23*984.4/100 = 226.412 
			returnWon = returnWon/10*10; // 1원자리 절삭 220
			printf("엔화환전 원금 %d원 ->%d엔화환전\n", inputWon, outputFinal);
			printf("거스름돈 : %d원\n", returnWon);
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
			break;
			}
			
			//유로 
			case 2 : {
			RATE = RATE_EURO;
			int returnWon = 0;
			int outputFinal = 0; 
			float output = 0; 
			output = inputWon / RATE;
			outputFinal = output; 
			returnWon = output*100;  
			returnWon = returnWon%100; 
			returnWon = returnWon*RATE /100; 
			returnWon = returnWon/10*10;
			printf("유로환전 원금 %d원 ->%d유로환전\n", inputWon, outputFinal);
			printf("거스름돈 : %d원\n", returnWon);
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
			break;
			}
			
			//중화  
			case 3 : {
			RATE = RATE_RMB;
			int returnWon = 0;
			int outputFinal = 0;
			float output = 0; 
			output = inputWon / RATE;
			outputFinal = output; 
			returnWon = output*100;  
			returnWon = returnWon%100; 
			returnWon = returnWon*RATE /100; 
			returnWon = returnWon/10*10; 
			printf("중화환전 원금 %d원 ->%d CNY환전\n", inputWon, outputFinal);
			printf("거스름돈 : %d원\n", returnWon);
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
			break;
			}
			
			//영국 
			case 4 : {
			RATE = RATE_GBP;
			int returnWon = 0;
			int outputFinal = 0; 
			float output = 0;
			output = inputWon / RATE; 
			outputFinal = output; 
			returnWon = output*100;  
			returnWon = returnWon%100; 
			returnWon = returnWon*RATE /100; 
			returnWon = returnWon/10*10; 
			printf("파운드환전 원금 %d원 ->%d GBP환전\n", inputWon, outputFinal);
			printf("거스름돈 : %d원\n", returnWon);
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
			break;
			}			
		}		
	}
	return 0;
}
