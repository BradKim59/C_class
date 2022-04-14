#include <stdio.h>
	//데이터 선언부 
	const float RATE_USD = 1233.1; //달러환율 
	const float RATE_YEN = 9.844; //엔화환율 
	const float RATE_EURO = 1342.64; //유로환율 
	const float RATE_RMB = 193.54; //중국환율 
	const float RATE_GBP = 1605.03; //영국환율
	float RATE = 0;//환율 대입할 변수 
	int returnWon = 0;
	int outputFinal = 0; //정슈형 형변환하기 
	float output = 0; //달러 환전액 실수형
	int inputWon = 50000; //원금 
	int returnWon1000; 
	int returnWon500; 
	int returnWon100; 
	int returnWon50; 
	int returnWon10; 
	int selectCon;
	char *curren;
	
int SelectN (int SelectCon) {
	switch (SelectCon) {
	//달러 
	case 1 : 
	RATE = RATE_USD;
	break;
	
	//엔화 
	case 2 : 
	RATE = RATE_YEN; //엔화는 100엔 기준으로 환율이  환산된다. 
	break;
	
	//유로 
	case 3 : 
	RATE = RATE_EURO;
	break;
	
	//중화  
	case 4 : 
	RATE = RATE_RMB;
	break;
	
	//영국 
	case 5 : 
	RATE = RATE_GBP;
	break;
	}
	output = inputWon / RATE; //환전계산 
	outputFinal = output; //환전액 정수형 형변환 
	return outputFinal;
}

void SelectC (int SelectCon) {
	switch (selectCon) {
	case 1 :
		printf("달러\n");
		break;
	case 2 :
		printf("엔화\n");
		break;
	case 3 :
		printf("유로\n");
		break;
	case 4 :
		printf("위안\n");
		break;
	case 5 :
		printf("파운드\n");
		break;
	} 
}
int changeCal (int SelectCon) {
	if (selectCon == 1 || selectCon == 3 || selectCon == 4 || selectCon == 5) {
		returnWon = ((int)(output*100)%100)*RATE/100; 
		returnWon = returnWon/10*10;
	} else if (selectCon == 2) {	
		returnWon = ((int)(output*100)%100)*RATE; 
		returnWon = returnWon/10*10;
	}
}

void changeQ(int returnWon) {
	returnWon1000 = returnWon/1000;
	returnWon500 = returnWon%1000/500;
	returnWon100 = returnWon%1000%500/100;
	returnWon50 = returnWon%1000%500%100/50;
	returnWon10 = returnWon%1000%500%100%50/10;
	printf("1000원 %d개, 500원%d개, 100원%d개, 50원%d개, 10원%d개 \n", returnWon1000, returnWon500, returnWon100, returnWon50, returnWon10);
} 

void outputCurrency(int selectCon, int outputFinal) {
	int returnD1000 = outputFinal/1000;
	int returnD500 = outputFinal%1000/500;
	int returnD100 = outputFinal%1000%500/100;
	int returnD50 = outputFinal%1000%500%100/50;
	int returnD20 = outputFinal%1000%500%100%50/20;
	int returnD10 = outputFinal%1000%500%100%50%20/10;
	int return20D10 = outputFinal%1000%500%100%50/10; //20단위 없을 때 
	int returnD5 = outputFinal%1000%500%100%50%20%10/5;
	int return20D5 = outputFinal%1000%500%100%50%10/5; //20단위 없을 때 
	int returnD2 = outputFinal%1000%500%100%50%20%10%5/2;
	int returnD1 = outputFinal%1000%500%100%50%20%10%5%2;
	int return2D1 = outputFinal%1000%500%100%50%20%10%5; //2 단위 없을 때 
	int return202D1 = outputFinal%1000%500%100%50%10%5; //2, 20 단위 없을 때 
	if (selectCon == 1 || selectCon == 3) {//달러, 유로 
	printf("100%s %d개, 50%s %d개, 20%s %d개, 10%s %d개, 5%s %d개, 2%s %d개, 1%s %d개  \n"
	, curren, returnD100, curren, returnD50, curren, returnD20, curren, returnD10, curren, returnD5, curren, returnD2, curren, returnD1);
	} else if (selectCon == 2) {//엔화 
	printf("1000%s %d개, 500%s %d개, 100%s %d개, 50%s %d개, 10%s %d개, 5%s %d개,1%s %d개 \n"
	, curren, returnD1000, curren, returnD500, curren, returnD100, curren, returnD50, curren, return20D10, curren, return20D5, curren, return202D1);
	} else if (selectCon == 4) {//위안 
	printf("100%s %d개, 50%s %d개, 20%s %d개, 10%s %d개, 5%s %d개, 1%s %d개 \n"
	, curren, returnD100, curren, returnD50, curren, returnD20, curren, returnD10, curren, returnD5, curren, return2D1);
	} else if (selectCon == 5) {//파운드 
	printf("50%s %d개, 20%s %d개, 10%s %d개, 5%s %d개, 1%s %d개 \n"
	, curren, returnD50, curren, returnD20, curren, returnD10, curren, returnD5, curren, return2D1);
	}
}
char currency (int selectCon) {
	switch(selectCon) {
		case 1 :
			curren = "달러";
			break;
		case 2 :
			curren = "엔";
			break;
		case 3 :
			curren = "유로";
			break;
		case 4 :
			curren = "위안";
			break;
		case 5 :
			curren = "파운드";
			break;
	}
	return *curren; 
}


int main() {
	//데이터 입력부 
	printf("환전을 원하는 원화 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	do {
		printf("환전을 원하는 외화를 선택 하세요(1:USD, 2:YEN, 3:EURO, 4:RMB, 5:GBP) : ");
		scanf("%d", &selectCon); 
	} while (selectCon<1 || selectCon>5);
	
	SelectN(selectCon);//국가 변 환율 선택 
	printf("환전 원금 %d원 ->%d ", inputWon, outputFinal);
	SelectC(selectCon);//국가별 통화이름 출력 

	currency (selectCon);//통화 단위정하는 함수 
	outputCurrency(selectCon, outputFinal);//통화 지폐분류 함수 
	
	changeCal(selectCon);//국가 별 잔돈계산 
	printf("거스름돈 : %d원\n", returnWon);
	changeQ(returnWon);//거스름돈 지폐단위 

	return 0;
}
		
