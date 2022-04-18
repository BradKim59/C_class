#include <stdio.h>
#include <time.h>

time_t timer = time(NULL);
struct tm tm = *localtime(&timer);
//�Է� �� ���� ���� 
int ticket, dayTicket, qty = 1, advantage, numDaDoong, conTicket;
long long personID;
//��� �� ���� ���� 
int year, month, date, gender, manAge, disAdvantage, generation, discountType;
int price, totalPrice, totalDiscountPrice, grandPrice, grandSum;
int num, disNum, indexOfArray = 0;
//�迭 ���� 
int monthNor [12] = {31,28,31,30,31,30,31,31,30,31,30,31};//��� ������ 
int monthLun [12] = {31,29,31,30,31,30,31,31,30,31,30,31};//���� ������ 
int orderArr[10][10]; 
// ���� �� ��� ����
const int TICKET_TYPE = 0, DAY_TYPE = 1, DISCOUNT_TYPE = 2, PERSON_TYPE = 3, NOMAL_TICKET_QTY = 4, 
DISC_TICKET_QTY = 5, NORMAL_PRICE_SUM = 6, DISC_PRICE_SUM = 7, NON_DISCOUNT_TYPE = 8, SUM_PRICE = 9; 
//���� �̿�� 
const int INFANT_PRICE = 0,
	ADULT_ALL_DAY_PRICE = 62000, ADULT_ALL_AFTER4_PRICE = 50000,
	TEEN_ALL_DAY_PRICE = 54000, TEEN_ALL_AFTER4_PRICE = 43000,
	CHILD_ALL_DAY_PRICE = 47000, CHILD_ALL_AFTER4_PRICE = 36000,
	BABY_ALL_DAY_PRICE = 15000, BABY_ALL_AFTER4_PRICE = 15000;
//��ũ �̿�� 
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
// ���̿� ���� ����
const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13,
	 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;

// ������
const float DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5,
		MULTICHILD_DISCOUNT_RATE = 0.7,	PREGNANT_DISCOUNT_RATE = 0.5, 
		MILITARY_DISCOUNT_RATE = 0.51;
// �ִ� �ֹ���
const int MAX_COUNT = 10, MIN_COUNT = 1;

int check_ticket_type() {
	price = 0;
	totalPrice = 0; //���ι����� ���� 
	totalDiscountPrice = 0;//���� ���� ���� 
	grandPrice = 0; //�� ���� 
	num = 0; //���ι����� Ƽ�� ��
	disNum = 0;//�������� Ƽ�� ��
	disAdvantage = 1;//���ο�� �� �����
	printf("������ ���� �ϼ���.\n1. �����̿��\n2. ��ũ�̿��\n->");
	do {
		scanf("%d", &ticket);
		switch (ticket) {
			case 1: case 2:
				printf("\n");
				break;
			default :
				printf("\n");
				printf("�׸� 1�̳� 2�� �����ּ���.\n1. �����̿��\n2. ��ũ�̿��\n->");
		}		
	} while (ticket!=1 && ticket!=2); 
	return ticket;
}

int check_day_type() {
	printf("�̿�ð��� ���� �ϼ���.\n1. 1�ϱ� \n2. AFTER4(16�� ����) \n->");
	do{
		scanf("%d", &dayTicket);
		switch (dayTicket) {
			case 1: case 2:
				printf("\n");
				break;
			default :
				printf("\n");
				printf("�׸� 1�̳� 2�� �����ּ���.\n1. 1�ϱ� \n2. AFTER4(16�� ����) \n->");
				break;
		}
	}while (dayTicket!=1 && dayTicket!=2);
	return dayTicket;
}

void check_person_ID() {
	do{
		printf("�ֹι�ȣ�� �Է��ϼ���\n->");
		scanf("%lld", &personID);
		printf("\n");
		//������ �� ���� Ȯ�� 
		year = personID/YEAR_DIGIT;
		month = personID/MONTH_DIGIT%100;
		date = personID/DAY_DIGIT%100;
		gender = personID/GENDER_DIGIT%10;
		
		//�ֹι�ȣ ���� ĳġ
		if (year > tm.tm_year-100 && year < 40 ) {
			printf("����⵵ Ȯ�� �� �ּ���.\n");
		}
		if (month < 1 || month > 12) {
			printf("����� �ٽ� Ȯ�� �� �ּ���.\n");
		}
		if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
			if (date < 1 || date > monthLun[month-1]) {
				printf("����� �ٽ� Ȯ�� �� �ּ���.\n");
			}
		} else {
			if (date < 1 || date > monthNor[month-1]) {
				printf("����� �ٽ� Ȯ�� �� �ּ���.\n");
			}
		}
		if (gender  < 1 || gender > 4) {
			printf("�����ڵ� �ٽ� Ȯ�� �� �ּ���.\n");
		}
		if (personID < 1000000000 || personID > 10000000000000) {
			printf("�ֹε�Ϲ�ȣ�� 13�ڸ� �Դϴ�.\n");
		} 
	} while ((month < 1 || month > 12) || (date < 1 || date > monthLun[month-1]) 
			|| (date < 1 || date > monthNor[month-1]) || (gender  <1 || gender > 4) 
			|| (personID < 1000000000 || personID > 10000000000000) || (year > tm.tm_year-100 && year < 40 ));
}

int check_ticket_QTY() {
	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n->");
	do{
		scanf("%d", &qty);
		printf("\n");
		if (qty > MAX_COUNT || qty < MIN_COUNT) {
			printf("�ٽ� �ֹ��� �ּ��� (1���̻�, �ִ� 10��)\n->");
		}
	} while(qty > MAX_COUNT || qty < MIN_COUNT);
	return qty;
}

int check_benefit() {
	printf("�������� �����ϼ���\n1. ����\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ��� �ູī��\n->");
	do {
		scanf("%d", &advantage);
		switch (advantage) {
		case 1: case 2: case 3: case 4: case 5: case 6:
			printf("\n");
			break;
		default :
			printf("\n");
			printf("�Ʒ� �׸� �ش��ϴ� ��ȣ�� �ٽ� �����ּ���.\n1. ����\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ��� �ູī��\n->");
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
			
	//������ ��� ���� 
	if (manAge < MIN_CHILD && manAge >= MIN_BABY) {
		generation = 2;//������
	} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN){
		generation = 3;//���
	} else if (manAge >= MIN_TEEN && manAge <= MAX_TEEN) {
		generation = 4;//û�ҳ�
	} else if (manAge < MIN_BABY){
		generation = 1;//�Ż���
	} else if (manAge >  MAX_ADULT) {
		generation = 6;//��65�̻�
	} else {
		generation = 5;//����
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
		case 1://�Ϲ� 
			for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					totalPrice += price;
					num++;
			}
			printf("�Ϲ� ���� ������ �����ϼ̽��ϴ�.\n");
		break;
		case 2 ://����� 
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
			printf("(������� �������� ����)���� �� ���� 1�α��� ���� ����˴ϴ�.\n");							
		break;
		case 3 ://���������� 
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
			printf("(�������� �������� ����)���� �� ���� 1�α��� ���� ����˴ϴ�.\n");							
		break;
		case 4://�ް��庴
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
				printf("�ް��庴 �� ���� 1�α��� ���� ����˴ϴ�.\n");
			} else {
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					totalPrice += price;
					num++; 
				}
				printf("�˼��մϴ�, �ް��庴 ���� ����(���α���) �̾�� �մϴ�.\n");
			}
		break;
		case 5://�ӻ�� 
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
			printf("(������������) �ӻ�� ���� ���� ����Ǿ����ϴ�.\n");
			} else {
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					totalPrice += price;
					num++; 
				}
				printf("�˼��մϴ�, �ӻ�� ���� ����(����) �̾�� �մϴ�.\n");
			}
		break;
		case 6://�ٵ��� 
			printf("���ΰ��� �ο� ���� �� �ּ���.\n");
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
			printf("(������������) �ο��� (%d��) ���� ����˴ϴ�.\n", numDaDoong);
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
	printf("�� ������ %d�� �Դϴ�.", grandPrice);
	printf(" �����մϴ�.\n");
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
	printf("��� �߱��Ͻðڽ��ϱ�? \n1. ��� �߱�\n2. ����\n->");
	do {
		scanf("%d", &conTicket);
		switch(conTicket){
		case 1: case 2:
			printf("\n");
			break;
		default : 
			printf("�׸� �ش��ϴ� �ѹ��� �ٽ� �����ּ���. \n1. ��� �߱�\n2. ����\n->");
			break;
		} 
	} while (conTicket != 1 && conTicket != 2);
	if (conTicket == 1) {
		indexOfArray++;
	}
	return conTicket;
}

void print_total_order(){
	printf("\nƼ�� �߱��� �����մϴ�. �����մϴ�.\n");
	printf("================================ �Ե�����================================\n");
	printf("�̿��Ÿ��   �ð�Ÿ��   ���ɴ�    ����     ����                  ����Ÿ��\n");
	printf("-------------------------------------------------------------------------\n");
	for (int roundOfOrder = 0; roundOfOrder<=indexOfArray; roundOfOrder++){//���� Ƽ�� ��� 
		switch (orderArr[roundOfOrder][TICKET_TYPE]) {
			case 1 :
				printf("%s","�����̿��");
				break;
			case 2 :
				printf("%s","��ũ�̿��"); 
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
				printf("%10s", "�Ż���");
				break;
			case 2 :
				printf("%10s","������"); 
				break;
			case 3 :
				printf("%10s","���"); 
				break;
			case 4 :
				printf("%10s", "û�ҳ�");
				break;
			case 5 :
				printf("%10s","����"); 
				break;
			case 6 :
				printf("%10s","��67�̻�"); 
				break;
		}
		//���α�, �Ϲݱ� ���� �� 
		if  (orderArr[roundOfOrder][DISC_TICKET_QTY] >= 1 && orderArr[roundOfOrder][NOMAL_TICKET_QTY] >= 1) {
			printf("  X %3d %7d��", orderArr[roundOfOrder][DISC_TICKET_QTY], orderArr[roundOfOrder][DISC_PRICE_SUM]);
			switch (orderArr[roundOfOrder][DISCOUNT_TYPE]) {
				case 2 :	
					printf("%26s\n","����� �������"); 
					break;
				case 3 :
					printf("%26s\n","���������� �������");
					break;
				case 4 :
					printf("%26s\n", "�ް��庴 �������");
					break;
				case 5 :
					printf("%26s\n","�ӻ�� �������"); 
					break;
				case 6 :
					printf("%26s\n","�ٵ��� �������"); 
					break;
			}
			printf("\t\t\t\tX %3d %7d��", orderArr[roundOfOrder][NOMAL_TICKET_QTY], orderArr[roundOfOrder][NORMAL_PRICE_SUM]);
			switch (orderArr[roundOfOrder][NON_DISCOUNT_TYPE]) {
				case 2 :	
					printf("%26s\n","��������� �� �Ϲݰ���"); 
					break;
				case 3 :
					printf("%26s\n","�������������ο� �Ϲݰ���");
					break;
				case 4 :
					printf("%26s\n", "�ް��庴���ο� �Ϲݰ���");
					break;
				case 5 :
					printf("%26s\n","�ӻ������ �� �Ϲݰ���"); 
					break;
				case 6 :
					printf("%26s\n","�ٵ������� �� �Ϲݰ���"); 
					break;
			}
		//���αǸ� ���� �� 
		} else if  (orderArr[roundOfOrder][DISC_TICKET_QTY] >= 1 && orderArr[roundOfOrder][NOMAL_TICKET_QTY] == 0) {
			printf("  X %3d %7d��", orderArr[roundOfOrder][DISC_TICKET_QTY], orderArr[roundOfOrder][DISC_PRICE_SUM]);
			switch (orderArr[roundOfOrder][DISCOUNT_TYPE]) {
				case 2 :	
					printf("%26s\n","����� �������"); 
					break;
				case 3 :
					printf("%26s\n","���������� �������");
					break;
				case 4 :
					printf("%26s\n", "�ް��庴 �������");
					break;
				case 5 :
					printf("%26s\n","�ӻ�� �������"); 
					break;
				case 6 :
					printf("%26s\n","�ٵ��� �������"); 
					break;
			}
		//�ϹݱǸ� ���� �� 
		} else if  (orderArr[roundOfOrder][DISC_TICKET_QTY] == 0 && orderArr[roundOfOrder][NOMAL_TICKET_QTY] >= 1) {
			printf("  X %3d %7d��", orderArr[roundOfOrder][NOMAL_TICKET_QTY], orderArr[roundOfOrder][NORMAL_PRICE_SUM]);
			switch (orderArr[roundOfOrder][NON_DISCOUNT_TYPE]) {
				case 1 :
					printf("%26s\n", "���� ������");
					break;
			}
		}
		grandSum += orderArr[roundOfOrder][SUM_PRICE];
	}
	printf("-------------------------------------------------------------------------\n");
	printf("\t\t\t �� ����%13d��\n", grandSum);
	printf("=========================================================================\n");
}


int main() {
	
	do{
		//�Է� �κ� 
		input_information();
		//��� �κ�
		caculate_data();
		//�ݺ�or ���� Ȯ���Ѵ�.
		check_order_proceeding();
	} while(conTicket == 1);
	//��� �κ�  
	print_total_order();

	//���α׷� ���� �� ���⳻���� ���Ϸ� �����Ѵ�. 
	return 0;
}
