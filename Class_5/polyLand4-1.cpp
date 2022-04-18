#include <stdio.h>
#include <time.h>

time_t timer = time(NULL);
struct tm tm = *localtime(&timer);
//입력 값 변수 선언 
int ticket, dayTicket, qty = 1, advantage, numDaDoong, conTicket;
long long personID;
//계산 시 변수 선언 
int year, month, date, gender, manAge, disAdvantage, generation, discountType;
int price, totalPrice, totalDiscountPrice, grandPrice, grandSum;
int num, disNum, indexOfArray = 0;
//배열 선언 
int monthNor [12] = {31,28,31,30,31,30,31,31,30,31,30,31};//평달 월말일 
int monthLun [12] = {31,29,31,30,31,30,31,31,30,31,30,31};//윤달 월말일 
int orderArr[10][10]; 
// 종류 별 상수 선언
const int TICKET_TYPE = 0, DAY_TYPE = 1, DISCOUNT_TYPE = 2, PERSON_TYPE = 3, NOMAL_TICKET_QTY = 4, 
DISC_TICKET_QTY = 5, NORMAL_PRICE_SUM = 6, DISC_PRICE_SUM = 7, NON_DISCOUNT_TYPE = 8, SUM_PRICE = 9; 
//종합 이용권 
const int INFANT_PRICE = 0,
	ADULT_ALL_DAY_PRICE = 62000, ADULT_ALL_AFTER4_PRICE = 50000,
	TEEN_ALL_DAY_PRICE = 54000, TEEN_ALL_AFTER4_PRICE = 43000,
	CHILD_ALL_DAY_PRICE = 47000, CHILD_ALL_AFTER4_PRICE = 36000,
	BABY_ALL_DAY_PRICE = 15000, BABY_ALL_AFTER4_PRICE = 15000;
//파크 이용권 
const int ADULT_PARK_DAY_PRICE = 59000, ADULT_PARK_AFTER4_PRICE = 47000,
	TEEN_PARK_DAY_PRICE = 52000, TEEN_PARK_AFTER4_PRICE = 41000,
	CHILD_PARK_DAY_PRICE = 46000, CHILD_PARK_AFTER4_PRICE = 35000,
	BABY_PARK_DAY_PRICE = 15000, BABY_PARK_AFTER4_PRICE = 15000;
const long long int YEAR_DIGIT = 100000000000,
				MONTH_DIGIT = 1000000000, 
				DAY_DIGIT = 10000000,
				GENDER_DIGIT = 1000000;

const int MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMALE_NEW = 4,
	 BEFORE_BIRTH = 2, AFTER_BIRTH = 1;
// 나이에 따른 범위
const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13,
	 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;

// 할인율
const float DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5,
		MULTICHILD_DISCOUNT_RATE = 0.7,	PREGNANT_DISCOUNT_RATE = 0.5, 
		MILITARY_DISCOUNT_RATE = 0.51;
// 최대 주문량
const int MAX_COUNT = 10, MIN_COUNT = 1;

int check_ticket_type() {
	price = 0;
	totalPrice = 0; //할인미적용 가격 
	totalDiscountPrice = 0;//할인 적용 가격 
	grandPrice = 0; //총 가격 
	num = 0; //할인미적용 티켓 수
	disNum = 0;//할인적용 티켓 수
	disAdvantage = 1;//할인우대 미 적용시
	printf("권종을 선택 하세요.\n1. 종합이용권\n2. 파크이용권\n->");
	do {
		scanf("%d", &ticket);
		switch (ticket) {
			case 1: case 2:
				printf("\n");
				break;
			default :
				printf("\n");
				printf("항목 1이나 2를 눌러주세요.\n1. 종합이용권\n2. 파크이용권\n->");
		}		
	} while (ticket!=1 && ticket!=2); 
	return ticket;
}

int check_day_type() {
	printf("이용시간을 선택 하세요.\n1. 1일권 \n2. AFTER4(16시 이후) \n->");
	do{
		scanf("%d", &dayTicket);
		switch (dayTicket) {
			case 1: case 2:
				printf("\n");
				break;
			default :
				printf("\n");
				printf("항목 1이나 2를 눌러주세요.\n1. 1일권 \n2. AFTER4(16시 이후) \n->");
				break;
		}
	}while (dayTicket!=1 && dayTicket!=2);
	return dayTicket;
}

void check_person_ID() {
	do{
		printf("주민번호를 입력하세요\n->");
		scanf("%lld", &personID);
		printf("\n");
		//만나이 및 성별 확인 
		year = personID/YEAR_DIGIT;
		month = personID/MONTH_DIGIT%100;
		date = personID/DAY_DIGIT%100;
		gender = personID/GENDER_DIGIT%10;
		
		//주민번호 오류 캐치
		if (year > tm.tm_year-100 && year < 40 ) {
			printf("출생년도 확인 해 주세요.\n");
		}
		if (month < 1 || month > 12) {
			printf("출생월 다시 확인 해 주세요.\n");
		}
		if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
			if (date < 1 || date > monthLun[month-1]) {
				printf("출생일 다시 확인 해 주세요.\n");
			}
		} else {
			if (date < 1 || date > monthNor[month-1]) {
				printf("출생일 다시 확인 해 주세요.\n");
			}
		}
		if (gender  < 1 || gender > 4) {
			printf("성별코드 다시 확인 해 주세요.\n");
		}
		if (personID < 1000000000 || personID > 10000000000000) {
			printf("주민등록번호는 13자리 입니다.\n");
		} 
	} while ((month < 1 || month > 12) || (date < 1 || date > monthLun[month-1]) 
			|| (date < 1 || date > monthNor[month-1]) || (gender  <1 || gender > 4) 
			|| (personID < 1000000000 || personID > 10000000000000) || (year > tm.tm_year-100 && year < 40 ));
}

int check_ticket_QTY() {
	printf("몇개를 주문하시겠습니까? (최대 10개)\n->");
	do{
		scanf("%d", &qty);
		printf("\n");
		if (qty > MAX_COUNT || qty < MIN_COUNT) {
			printf("다시 주문해 주세요 (1개이상, 최대 10개)\n->");
		}
	} while(qty > MAX_COUNT || qty < MIN_COUNT);
	return qty;
}

int check_benefit() {
	printf("우대사항을 선택하세요\n1. 없음\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이 행복카드\n->");
	do {
		scanf("%d", &advantage);
		switch (advantage) {
		case 1: case 2: case 3: case 4: case 5: case 6:
			printf("\n");
			break;
		default :
			printf("\n");
			printf("아래 항목에 해당하는 번호를 다시 눌러주세요.\n1. 없음\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이 행복카드\n->");
			break;
		} 		
	} while(advantage!=1 && advantage!=2 && advantage!=3 && advantage!=4 && advantage!=5 && advantage!=6);
	return advantage;
}

int calculate_manAge (int year, int month, int date){
	if (year+100 <= tm.tm_year) {
	year = year + 100;
	}
	manAge = tm.tm_year - year;
	if (year < tm.tm_year && month < tm.tm_mon+1) {
		manAge + 1;
	} else if (year < tm.tm_year && month < tm.tm_mon+1 && date < tm.tm_mday) {
		manAge + 1;
	} else if (year < tm.tm_year && month > tm.tm_mon+1){
		manAge - 1;
	} else if (year < tm.tm_year && month >= tm.tm_mon+1 && date > tm.tm_mday){
		manAge - 1;
	}
			
	//구매자 대상 저장 
	if (manAge < MIN_CHILD && manAge >= MIN_BABY) {
		generation = 2;//영유아
	} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN){
		generation = 3;//어린이
	} else if (manAge >= MIN_TEEN && manAge <= MAX_TEEN) {
		generation = 4;//청소년
	} else if (manAge < MIN_BABY){
		generation = 1;//신생아
	} else if (manAge >  MAX_ADULT) {
		generation = 6;//만65이상
	} else {
		generation = 5;//성인
	}return generation;
}

int calculate_ticket_price (int ticket, int dayTicket, int generation){
	if (ticket == 1){
		switch(dayTicket) {
		case 1:
			if (generation == 2) {
				price = BABY_ALL_DAY_PRICE;
			} else if (generation == 3 || generation == 6){
				price = CHILD_ALL_DAY_PRICE;
			} else if (generation == 4) {
				price = TEEN_ALL_DAY_PRICE;
			} else if (generation == 1){
				price = INFANT_PRICE;
			} else {
				price = ADULT_ALL_DAY_PRICE;
			}
			break;
		case 2:
			if (generation == 2) {
				price = BABY_ALL_AFTER4_PRICE;
			} else if (generation == 3 || generation == 6){
				price = CHILD_ALL_AFTER4_PRICE;
			} else if (generation == 4) {
				price = TEEN_ALL_AFTER4_PRICE;
			} else if (generation == 1){
				price = INFANT_PRICE;
			} else {
				price = ADULT_ALL_AFTER4_PRICE;
			} 
			break;
		}
	} else if (ticket == 2){
		switch(dayTicket) {
		case 1:
			if (generation == 2) {
				price = BABY_PARK_DAY_PRICE;
			} else if (generation == 3 || generation == 6){
				price = CHILD_PARK_DAY_PRICE;
			} else if (generation == 4) {
				price = TEEN_PARK_DAY_PRICE;
			} else if (generation == 1){
				price = INFANT_PRICE;
			} else {
				price = ADULT_PARK_DAY_PRICE;
			}
			break;
		case 2:
			if (generation == 2) {
				price = BABY_PARK_AFTER4_PRICE;
			} else if (generation == 3 || generation == 6){
				price = CHILD_PARK_AFTER4_PRICE;
			} else if (generation == 4) {
				price = TEEN_PARK_AFTER4_PRICE;
			} else if (generation == 1){
				price = INFANT_PRICE;
			} else {
				price = ADULT_PARK_AFTER4_PRICE;
			}
			break;
		}
	} return price;
}

void adjust_advantage(int advantage, int price, int qty){
	switch(advantage) {
		case 1://일반 
			for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					totalPrice += price;
					num++;
			}
			printf("일반 할인 미적용 선택하셨습니다.\n");
		break;
		case 2 ://장애인 
			for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
				 if (ticketCount > 2){
					totalPrice += price;
					num++;
				} else {
					disAdvantage = 2;
					totalDiscountPrice += price * DISABLE_DISCOUNT_RATE;
					disNum++;
				} 
			}
			printf("(장애인증 공식증빙 지참)본인 및 동반 1인까지 할인 적용됩니다.\n");							
		break;
		case 3 ://국가유공자 
			for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
				 if (ticketCount > 2){
					totalPrice += price;
					num++;
				} else {
					disAdvantage = 3;
					totalDiscountPrice += price * MERIT_DISCOUNT_RATE;
					disNum++;
				}
			}
			printf("(유공자증 공식증빙 지참)본인 및 동반 1인까지 할인 적용됩니다.\n");							
		break;
		case 4://휴가장병
			if (generation >=5){
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					if (ticketCount > 2){
						totalPrice += price;
						num++; 
					} else {
						disAdvantage = 4;
						totalDiscountPrice += price * MILITARY_DISCOUNT_RATE;
						disNum++;
					}
				}
				printf("휴가장병 및 동반 1인까지 할인 적용됩니다.\n");
			} else {
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					totalPrice += price;
					num++; 
				}
				printf("죄송합니다, 휴가장병 우대는 본인(성인기준) 이어야 합니다.\n");
			}
		break;
		case 5://임산부 
			if (gender == FEMALE_OLD || gender == FEMALE_NEW){
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					if (ticketCount > 1){
						totalPrice += price;
						num++; 
					} else {
						disAdvantage = 5;
						totalDiscountPrice += price * PREGNANT_DISCOUNT_RATE;
						disNum++;
					}
				}
			printf("(공식증빙지참) 임산부 본인 할인 적용되었습니다.\n");
			} else {
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					totalPrice += price;
					num++; 
				}
				printf("죄송합니다, 임산부 우대는 본인(여성) 이어야 합니다.\n");
			}
		break;
		case 6://다둥이 
			printf("할인가족 인원 선택 해 주세요.\n");
			scanf("%d", &numDaDoong); 
			for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
				if (ticketCount > numDaDoong){
					totalPrice += price;
					num++; 
				} else {
					disAdvantage = 6;
					totalDiscountPrice += price * MULTICHILD_DISCOUNT_RATE;
					disNum++;
				}
			}
			printf("(공식증빙지참) 인원수 (%d명) 할인 적용됩니다.\n", numDaDoong);
		break;
	}
}


void input_data_in_Arr(int ticket, int dayTicket, int advantage, int disAdvantage, int generation, int num, int disNum, int totalPrice, int totalDiscountPrice, int grandPrice) {
	orderArr[indexOfArray][TICKET_TYPE] = ticket;
	orderArr[indexOfArray][DAY_TYPE] = dayTicket;
	orderArr[indexOfArray][DISCOUNT_TYPE] = advantage;
	orderArr[indexOfArray][NON_DISCOUNT_TYPE] = disAdvantage;
	orderArr[indexOfArray][PERSON_TYPE] = generation;
	orderArr[indexOfArray][NOMAL_TICKET_QTY] = num;
	orderArr[indexOfArray][DISC_TICKET_QTY] = disNum;
	orderArr[indexOfArray][NORMAL_PRICE_SUM] = totalPrice;
	orderArr[indexOfArray][DISC_PRICE_SUM] = totalDiscountPrice;
	orderArr[indexOfArray][SUM_PRICE] = grandPrice;
}


int print_grand_price(int totalPrice, int totalDiscountPrice){
	grandPrice = totalPrice + totalDiscountPrice;
	printf("총 가격은 %d원 입니다.", grandPrice);
	printf(" 감사합니다.\n");
	printf("\n");
	return grandPrice;
}



void input_information(){
	check_ticket_type();
	check_day_type();
	check_person_ID();
	check_ticket_QTY();
	check_benefit();
} 

void caculate_data(){
	calculate_manAge (year, month, date);
	calculate_ticket_price (ticket, dayTicket, generation);
	adjust_advantage(advantage, price, qty);	
	input_data_in_Arr(ticket, dayTicket, advantage, disAdvantage, generation, num, disNum, totalPrice, totalDiscountPrice, grandPrice);
	print_grand_price(totalPrice, totalDiscountPrice);
}
	


int check_order_proceeding(){
	printf("계속 발권하시겠습니까? \n1. 계속 발권\n2. 종료\n->");
	do {
		scanf("%d", &conTicket);
		switch(conTicket){
		case 1: case 2:
			printf("\n");
			break;
		default : 
			printf("항목에 해당하는 넘버를 다시 눌러주세요. \n1. 계속 발권\n2. 종료\n->");
			break;
		} 
	} while (conTicket != 1 && conTicket != 2);
	if (conTicket == 1) {
		indexOfArray++;
	}
	return conTicket;
}

void print_total_order(){
	printf("\n티켓 발권을 종료합니다. 감사합니다.\n");
	printf("================================ 롯데월드================================\n");
	printf("이용권타입   시간타입   연령대    수량     가격                  할인타입\n");
	printf("-------------------------------------------------------------------------\n");
	for (int roundOfOrder = 0; roundOfOrder<=indexOfArray; roundOfOrder++){//할인 티켓 출력 
		switch (orderArr[roundOfOrder][TICKET_TYPE]) {
			case 1 :
				printf("%s","종합이용권");
				break;
			case 2 :
				printf("%s","파크이용권"); 
				break;
		} 
		switch (orderArr[roundOfOrder][DAY_TYPE]) {
			case 1 :
				printf("%10s", "1DAY");
				break;
			case 2 :
				printf("%10s","AFTER4"); 
				break;
		}
		switch (orderArr[roundOfOrder][PERSON_TYPE]) {
			case 1 :
				printf("%10s", "신생아");
				break;
			case 2 :
				printf("%10s","영유아"); 
				break;
			case 3 :
				printf("%10s","어린이"); 
				break;
			case 4 :
				printf("%10s", "청소년");
				break;
			case 5 :
				printf("%10s","성인"); 
				break;
			case 6 :
				printf("%10s","만67이상"); 
				break;
		}
		//할인권, 일반권 존재 시 
		if  (orderArr[roundOfOrder][DISC_TICKET_QTY] >= 1 && orderArr[roundOfOrder][NOMAL_TICKET_QTY] >= 1) {
			printf("  X %3d %7d원", orderArr[roundOfOrder][DISC_TICKET_QTY], orderArr[roundOfOrder][DISC_PRICE_SUM]);
			switch (orderArr[roundOfOrder][DISCOUNT_TYPE]) {
				case 2 :	
					printf("%26s\n","장애인 우대적용"); 
					break;
				case 3 :
					printf("%26s\n","국가유공자 우대적용");
					break;
				case 4 :
					printf("%26s\n", "휴가장병 우대적용");
					break;
				case 5 :
					printf("%26s\n","임산부 우대적용"); 
					break;
				case 6 :
					printf("%26s\n","다둥이 우대적용"); 
					break;
			}
			printf("\t\t\t\tX %3d %7d원", orderArr[roundOfOrder][NOMAL_TICKET_QTY], orderArr[roundOfOrder][NORMAL_PRICE_SUM]);
			switch (orderArr[roundOfOrder][NON_DISCOUNT_TYPE]) {
				case 2 :	
					printf("%26s\n","장애인할인 외 일반가격"); 
					break;
				case 3 :
					printf("%26s\n","국가유공자할인외 일반가격");
					break;
				case 4 :
					printf("%26s\n", "휴가장병할인외 일반가격");
					break;
				case 5 :
					printf("%26s\n","임산부할인 외 일반가격"); 
					break;
				case 6 :
					printf("%26s\n","다둥이할인 외 일반가격"); 
					break;
			}
		//할인권만 존재 시 
		} else if  (orderArr[roundOfOrder][DISC_TICKET_QTY] >= 1 && orderArr[roundOfOrder][NOMAL_TICKET_QTY] == 0) {
			printf("  X %3d %7d원", orderArr[roundOfOrder][DISC_TICKET_QTY], orderArr[roundOfOrder][DISC_PRICE_SUM]);
			switch (orderArr[roundOfOrder][DISCOUNT_TYPE]) {
				case 2 :	
					printf("%26s\n","장애인 우대적용"); 
					break;
				case 3 :
					printf("%26s\n","국가유공자 우대적용");
					break;
				case 4 :
					printf("%26s\n", "휴가장병 우대적용");
					break;
				case 5 :
					printf("%26s\n","임산부 우대적용"); 
					break;
				case 6 :
					printf("%26s\n","다둥이 우대적용"); 
					break;
			}
		//일반권만 존재 시 
		} else if  (orderArr[roundOfOrder][DISC_TICKET_QTY] == 0 && orderArr[roundOfOrder][NOMAL_TICKET_QTY] >= 1) {
			printf("  X %3d %7d원", orderArr[roundOfOrder][NOMAL_TICKET_QTY], orderArr[roundOfOrder][NORMAL_PRICE_SUM]);
			switch (orderArr[roundOfOrder][NON_DISCOUNT_TYPE]) {
				case 1 :
					printf("%26s\n", "할인 미적용");
					break;
			}
		}
		grandSum += orderArr[roundOfOrder][SUM_PRICE];
	}
	printf("-------------------------------------------------------------------------\n");
	printf("\t\t\t 총 누계%13d원\n", grandSum);
	printf("=========================================================================\n");
}


int main() {
	
	do{
		//입력 부분 
		input_information();
		//계산 부분
		caculate_data();
		//반복or 종료 확인한다.
		check_order_proceeding();
	} while(conTicket == 1);
	//출력 부분  
	print_total_order();

	//프로그램 종료 시 매출내역을 파일로 저장한다. 
	return 0;
}
