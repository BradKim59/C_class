#include <stdio.h>
#include <time.h>

int main() {
	time_t timer = time(NULL);
	struct tm tm = *localtime(&timer);
	//권종을 입력받는다.
	int ticket; //종합 or 파크 구별함수 
	int dayTicket;// 종일 or 오후 구별 함수 
	long long personID; //주민번호 
	int gender;//성별 
	int manAge;//만나이 
	int monthNor [12] = {31,28,31,30,31,30,31,31,30,31,30,31};//평달 월말일 
	int monthLun [12] = {31,29,31,30,31,30,31,31,30,31,30,31};//윤달 월말일 
	int qty = 1;//티켓 수량 
	int advantage;//우대 할인선택 
	int numDaDoong;//다둥이 멤버 
	int conTicket;
	int price = 0;
	int totalPrice = 0; //할인미적용 가격 
	int totalDiscountPrice = 0;//할인 적용 가격 
	int grandPrice = 0; //총 가격 
	int year;
	int month;
	int date;
	int num = 0; //할인미적용 티켓 수
	int disNum = 0;//할인적용 티켓 수
	char *ticketType [11];//티켓 종류 
	char *dayType [11];//이용권 시간 
	char *discountType [11];//할인 종류 
	char *nonDiscountType [11];//비 할인시 여기에 저장 
	char *personType [11];//이용자 연령대 
	int arrNum[11];//할인 미적용 티켓수 배열 
	int arrDiscountNum[11];//할인적용 티켓수 배열 
	int arrTotalPrice[11];//일반 가격 합 배열 
	int arrTotalDiscountPrice[11];//할인적용 가격합 배열 
	int indexOfArray = 0;//배열 순서 
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

	const int TWO_DIGIT = 100, ONE_DIGIT = 10,
		 OLD_GENERATION = 1900, NEW_GENERATION = 2000,
		 MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMALE_NEW = 4,
		 BEFORE_BIRTH = 2, AFTER_BIRTH = 1;
	// 나이에 따른 범위
	const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13,
		 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;
	// 나이에 따른 그룹
	const int BABY = 1, CHILD = 2, TEEN = 3, ADULT = 4, OLD = 5;
	// 할인율
	const float DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5,
			MULTICHILD_DISCOUNT_RATE = 0.7,
	PREGNANT_DISCOUNT_RATE = 0.5, MILITARY_DISCOUNT_RATE = 0.51;
	// 최대 주문량
	const int MAX_COUNT = 10, MIN_COUNT = 1;
	
	do{
		do {
			printf("권종을 선택 하세요\n1. 종합이용권\n2. 파크이용권\n");
			scanf("%d", &ticket);
			switch (ticket) {
				case 1:
					ticketType[indexOfArray] = "종합이용권";
					printf("\n");
					break;
				case 2:
					ticketType[indexOfArray] = "파크이용권";
					printf("\n");
					break;
				default :
					printf("항목 1이나 2를 눌러주세요.\n");
			}
		} while (ticket!=1&&ticket!=2);
		
		do{
			printf("%s : 이용시간을 선택 하세요\n1. 1일권 \n2. AFTER4(16시 이후) \n", ticketType[indexOfArray]);
			scanf("%d", &dayTicket);
			switch (dayTicket) {
				case 1:
					dayType[indexOfArray] = "1DAY";
					printf("\n");
					break;
				case 2:
					dayType[indexOfArray] = "AFTER4";
					printf("\n");
					break;
				default :
					printf("항목 1이나 2를 눌러주세요.\n\n");
			}
		}while (dayTicket!=1&&dayTicket!=2);
		
		//주민번호 입력받는다.
		do{
			printf("주민번호를 입력하세요\n");
			scanf("%lld", &personID);
			
			//만나이 및 성별 확인 
			year = personID/YEAR_DIGIT;
			month = personID/MONTH_DIGIT%100;
			date = personID/DAY_DIGIT%100;
			gender = personID/GENDER_DIGIT%10;
						
			//주민번호 오류 캐치
//			if (year+100 > tm.tm_year && year+900 < tm.tm_year+800 ) {
//				printf("출생년도 확인 해 주세요.\n");
//			}
			if (month < 1 && month > 12) {
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
			if (gender  <1 || gender > 4) {
				printf("성별코드 다시 확인 해 주세요.\n");
			}
			if (999999999999<personID<10000000000000) {
				printf("주민등록번호는 13자리 입니다.\n");
			} 
		} while ((month < 1 && month > 12) || (date < 1 || date > monthLun[month-1]) || (date < 1 || date > monthNor[month-1]) || (gender  <1 || gender > 4) || (999999999999<personID<10000000000000));

		// 만나이 계산 
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
			personType[indexOfArray] = "영유아";
		} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN){
			personType[indexOfArray] = "어린이";
		} else if (manAge >= MIN_TEEN && manAge <= MAX_TEEN) {
			personType[indexOfArray] = "청소년";
		} else if (manAge < MIN_BABY){
			personType[indexOfArray] = "신생아";
		} else if (manAge >  MAX_ADULT) {
			personType[indexOfArray] = "만65이상";
		} else {
			personType[indexOfArray] = "성인";
		}
		
		
		//받은 값으로 티켓 계산
		if (ticket == 1){
			switch(dayTicket) {
			case 1:
				if (manAge < MIN_CHILD && manAge >= MIN_BABY) {
					price = BABY_ALL_DAY_PRICE;
				} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN || manAge > MAX_ADULT){
					price = CHILD_ALL_DAY_PRICE;
				} else if (manAge > MIN_TEEN && manAge <= MAX_TEEN) {
					price = TEEN_ALL_DAY_PRICE;
				} else if (manAge < MIN_BABY){
					price = INFANT_PRICE;
				} else {
					price = ADULT_ALL_DAY_PRICE;
				}
				break;
			case 2:
				if (manAge < MIN_CHILD && manAge >= MIN_BABY) {
					price = BABY_ALL_AFTER4_PRICE;
				} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN || manAge > MAX_ADULT){
					price = CHILD_ALL_AFTER4_PRICE;
				} else if (manAge > MIN_TEEN && manAge <= MAX_TEEN) {
					price = TEEN_ALL_AFTER4_PRICE;
				} else if (manAge < MIN_BABY){
					price = INFANT_PRICE;
				} else {
					price = ADULT_ALL_AFTER4_PRICE;
				} 
				break;
			}
		} else if (ticket == 2){
			switch(dayTicket) {
			case 1:
				if (manAge < MIN_CHILD && manAge >= MIN_BABY) {
					price = BABY_PARK_DAY_PRICE;
				} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN || manAge > MAX_ADULT){
					price = CHILD_PARK_DAY_PRICE;
				} else if (manAge > MIN_TEEN && manAge <= MAX_TEEN) {
					price = TEEN_PARK_DAY_PRICE;
				} else if (manAge < MIN_BABY){
					price = INFANT_PRICE;
				} else {
					price = ADULT_PARK_DAY_PRICE;
				}
				break;
			case 2:
				if (manAge < MIN_CHILD && manAge >= MIN_BABY) {
					price = BABY_PARK_AFTER4_PRICE;
				} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN || manAge > MAX_ADULT){
					price = CHILD_PARK_AFTER4_PRICE;
				} else if (manAge > MIN_TEEN && manAge <= MAX_TEEN) {
					price = TEEN_PARK_AFTER4_PRICE;
				} else if (manAge < MIN_BABY){
					price = INFANT_PRICE;
				} else {
					price = ADULT_PARK_AFTER4_PRICE;
				}
				break;
			}
		}
		printf("\n");

		//주문개수 입력받는다.
		printf("몇개를 주문하시겠습니까? (최대 10개)\n");
		do{
			if (qty > MAX_COUNT || qty < MIN_COUNT) {
				printf("\n");
				printf("다시 주문해 주세요 (1개이상, 최대 10개)\n");
			}
			scanf("%d", &qty);
		}
	    while(qty > MAX_COUNT || qty < MIN_COUNT);
		printf("\n");
		
		//우대사항을 입력받는다.
		printf("우대사항을 선택하세요\n1. 없음\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이 행복카드\n");
		scanf("%d", &advantage);
		printf("\n");
		//할인조건(임산부일시, 성별 구별) 
		switch(advantage) {
			case 1:
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
						totalPrice += price;
						num++;
				}
				printf("일반 할인 미적용 선택하셨습니다.\n");
			break;
			case 2 :
				discountType[indexOfArray] = "장애인 우대적용";
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					 if (ticketCount > 2){
						totalPrice += price;
						num++;
					} else {
						totalDiscountPrice += price * DISABLE_DISCOUNT_RATE;
						disNum++;
					} 
				}
				printf("(장애인증 공식증빙 지참)본인 및 동반 1인까지 할인 적용됩니다.\n");							
			break;
			case 3 :
				discountType[indexOfArray] = "국가유공자 우대적용";
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					 if (ticketCount > 2){
						totalPrice += price;
						num++;
					} else {
						totalDiscountPrice += price * MERIT_DISCOUNT_RATE;
						disNum++;
					}
				}
				printf("(유공자증 공식증빙 지참)본인 및 동반 1인까지 할인 적용됩니다.\n");							
			break;
			case 4:
				discountType[indexOfArray] = "휴가장병 우대적용";
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					if (ticketCount > 2){
						totalPrice += price;
						num++; 
					} else {
						totalDiscountPrice += price * MILITARY_DISCOUNT_RATE;
						disNum++;
					}
				}
				printf("휴가장병 및 동반 1인까지 할인 적용됩니다.\n");							
			break;
			case 5:
				discountType[indexOfArray] = "임산부 우대적용";
				if (gender == 2 || gender == 4){
					for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
						if (ticketCount > 1){
							totalPrice += price;
							num++; 
						} else {
							totalDiscountPrice += price * PREGNANT_DISCOUNT_RATE;
							disNum++;
						}
					printf("(공식증빙지참) 임산부 본인 할인 적용되었습니다.\n");
					}
				} else {
					totalPrice = price*qty;
					num++; 
					printf("죄송합니다, 임산부 우대는 본인이어야 합니다.\n");
				}	
			break;
			case 6:
				discountType[indexOfArray] = "다둥이가족 우대적용";
				printf("할인가족 인원 선택 해 주세요.\n");
				scanf("%d", &numDaDoong); 
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					if (ticketCount > numDaDoong){
						totalPrice += price;
						num++; 
					} else {
						totalDiscountPrice += price * MULTICHILD_DISCOUNT_RATE;
						disNum++;
					}
				}
				printf("(공식증빙지참) 인원수 (%d명) 할인 적용됩니다.\n", numDaDoong);
			break;
		}
		
		//합산값 배열 저장 
		arrNum[indexOfArray] = num; 
		arrDiscountNum[indexOfArray] = disNum; 
		arrTotalPrice[indexOfArray] = totalPrice;  
		arrTotalDiscountPrice[indexOfArray] = totalDiscountPrice;
		
		//총합 환산 
		grandPrice = totalPrice + totalDiscountPrice;
		printf("총 가격은 %d원 입니다.", grandPrice);
		printf(" 감사합니다.\n");
		printf("\n");
		
		//누적 값 초기화 
		totalPrice = 0;
		totalDiscountPrice = 0;
		num = 0;
		disNum = 0;

		//반복or 종료 확인한다.
		printf("계속 발권하시겠습니까? \n1. 티켓 발권\n2. 종료\n");
		scanf("%d", &conTicket);	
		printf("\n");
		if (conTicket == 1) {
			indexOfArray++;
		}
	} while(conTicket == 1);
	
	
	//종료하면 주문내역이 모두 출력된다.
	printf("티켓 발권을 종료합니다. 감사합니다.\n");
	printf("=========================== 롯데월드===========================\n");
	for (int orderTicketCount = 0; orderTicketCount<=indexOfArray; orderTicketCount++){//할인 티켓 출력 
		if  (arrDiscountNum[orderTicketCount] >= 1) {
			printf("%s %6s %10s X %2d %7d원 %19s\n",ticketType[orderTicketCount], dayType[orderTicketCount],personType[orderTicketCount],arrDiscountNum[orderTicketCount], arrTotalDiscountPrice[orderTicketCount], discountType[orderTicketCount]);
		}
		if (arrNum[orderTicketCount] >= 1) {
			printf("%s %6s %10s X %2d %7d원 %19s\n",ticketType[orderTicketCount], dayType[orderTicketCount],personType[orderTicketCount],arrNum[orderTicketCount], arrTotalPrice[orderTicketCount], "우대적용 없음");
		}
	}
	printf("===============================================================\n");
	
	//프로그램 종료 시 매출내역을 파일로 저장한다. 
	return 0;
}
