#include <stdio.h>
#include <time.h>

int main() {
	time_t timer = time(NULL);
	struct tm tm = *localtime(&timer);
	//������ �Է¹޴´�.
	int ticket; //���� or ��ũ �����Լ� 
	int dayTicket;// ���� or ���� ���� �Լ� 
	long long personID; //�ֹι�ȣ 
	int gender;//���� 
	int manAge;//������ 
	int monthNor [12] = {31,28,31,30,31,30,31,31,30,31,30,31};//��� ������ 
	int monthLun [12] = {31,29,31,30,31,30,31,31,30,31,30,31};//���� ������ 
	int qty = 1;//Ƽ�� ���� 
	int advantage;//��� ���μ��� 
	int numDaDoong;//�ٵ��� ��� 
	int conTicket;
	int price = 0;
	int totalPrice = 0; //���ι����� ���� 
	int totalDiscountPrice = 0;//���� ���� ���� 
	int grandPrice = 0; //�� ���� 
	int year;
	int month;
	int date;
	int num = 0; //���ι����� Ƽ�� ��
	int disNum = 0;//�������� Ƽ�� ��
	char *ticketType [11];//Ƽ�� ���� 
	char *dayType [11];//�̿�� �ð� 
	char *discountType [11];//���� ���� 
	char *nonDiscountType [11];//�� ���ν� ���⿡ ���� 
	char *personType [11];//�̿��� ���ɴ� 
	int arrNum[11];//���� ������ Ƽ�ϼ� �迭 
	int arrDiscountNum[11];//�������� Ƽ�ϼ� �迭 
	int arrTotalPrice[11];//�Ϲ� ���� �� �迭 
	int arrTotalDiscountPrice[11];//�������� ������ �迭 
	int indexOfArray = 0;//�迭 ���� 
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

	const int TWO_DIGIT = 100, ONE_DIGIT = 10,
		 OLD_GENERATION = 1900, NEW_GENERATION = 2000,
		 MALE_OLD = 1, FEMALE_OLD = 2, MALE_NEW = 3, FEMALE_NEW = 4,
		 BEFORE_BIRTH = 2, AFTER_BIRTH = 1;
	// ���̿� ���� ����
	const int MIN_BABY = 1, MIN_CHILD = 3, MIN_TEEN = 13,
		 MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;
	// ���̿� ���� �׷�
	const int BABY = 1, CHILD = 2, TEEN = 3, ADULT = 4, OLD = 5;
	// ������
	const float DISABLE_DISCOUNT_RATE = 0.5, MERIT_DISCOUNT_RATE = 0.5,
			MULTICHILD_DISCOUNT_RATE = 0.7,
	PREGNANT_DISCOUNT_RATE = 0.5, MILITARY_DISCOUNT_RATE = 0.51;
	// �ִ� �ֹ���
	const int MAX_COUNT = 10, MIN_COUNT = 1;
	
	do{
		do {
			printf("������ ���� �ϼ���\n1. �����̿��\n2. ��ũ�̿��\n");
			scanf("%d", &ticket);
			switch (ticket) {
				case 1:
					ticketType[indexOfArray] = "�����̿��";
					printf("\n");
					break;
				case 2:
					ticketType[indexOfArray] = "��ũ�̿��";
					printf("\n");
					break;
				default :
					printf("�׸� 1�̳� 2�� �����ּ���.\n");
			}
		} while (ticket!=1&&ticket!=2);
		
		do{
			printf("%s : �̿�ð��� ���� �ϼ���\n1. 1�ϱ� \n2. AFTER4(16�� ����) \n", ticketType[indexOfArray]);
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
					printf("�׸� 1�̳� 2�� �����ּ���.\n\n");
			}
		}while (dayTicket!=1&&dayTicket!=2);
		
		//�ֹι�ȣ �Է¹޴´�.
		do{
			printf("�ֹι�ȣ�� �Է��ϼ���\n");
			scanf("%lld", &personID);
			
			//������ �� ���� Ȯ�� 
			year = personID/YEAR_DIGIT;
			month = personID/MONTH_DIGIT%100;
			date = personID/DAY_DIGIT%100;
			gender = personID/GENDER_DIGIT%10;
						
			//�ֹι�ȣ ���� ĳġ
//			if (year+100 > tm.tm_year && year+900 < tm.tm_year+800 ) {
//				printf("����⵵ Ȯ�� �� �ּ���.\n");
//			}
			if (month < 1 && month > 12) {
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
			if (gender  <1 || gender > 4) {
				printf("�����ڵ� �ٽ� Ȯ�� �� �ּ���.\n");
			}
			if (999999999999<personID<10000000000000) {
				printf("�ֹε�Ϲ�ȣ�� 13�ڸ� �Դϴ�.\n");
			} 
		} while ((month < 1 && month > 12) || (date < 1 || date > monthLun[month-1]) || (date < 1 || date > monthNor[month-1]) || (gender  <1 || gender > 4) || (999999999999<personID<10000000000000));

		// ������ ��� 
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
			personType[indexOfArray] = "������";
		} else if (manAge >= MIN_CHILD && manAge < MIN_TEEN){
			personType[indexOfArray] = "���";
		} else if (manAge >= MIN_TEEN && manAge <= MAX_TEEN) {
			personType[indexOfArray] = "û�ҳ�";
		} else if (manAge < MIN_BABY){
			personType[indexOfArray] = "�Ż���";
		} else if (manAge >  MAX_ADULT) {
			personType[indexOfArray] = "��65�̻�";
		} else {
			personType[indexOfArray] = "����";
		}
		
		
		//���� ������ Ƽ�� ���
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

		//�ֹ����� �Է¹޴´�.
		printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
		do{
			if (qty > MAX_COUNT || qty < MIN_COUNT) {
				printf("\n");
				printf("�ٽ� �ֹ��� �ּ��� (1���̻�, �ִ� 10��)\n");
			}
			scanf("%d", &qty);
		}
	    while(qty > MAX_COUNT || qty < MIN_COUNT);
		printf("\n");
		
		//�������� �Է¹޴´�.
		printf("�������� �����ϼ���\n1. ����\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ��� �ູī��\n");
		scanf("%d", &advantage);
		printf("\n");
		//��������(�ӻ���Ͻ�, ���� ����) 
		switch(advantage) {
			case 1:
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
						totalPrice += price;
						num++;
				}
				printf("�Ϲ� ���� ������ �����ϼ̽��ϴ�.\n");
			break;
			case 2 :
				discountType[indexOfArray] = "����� �������";
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					 if (ticketCount > 2){
						totalPrice += price;
						num++;
					} else {
						totalDiscountPrice += price * DISABLE_DISCOUNT_RATE;
						disNum++;
					} 
				}
				printf("(������� �������� ����)���� �� ���� 1�α��� ���� ����˴ϴ�.\n");							
			break;
			case 3 :
				discountType[indexOfArray] = "���������� �������";
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					 if (ticketCount > 2){
						totalPrice += price;
						num++;
					} else {
						totalDiscountPrice += price * MERIT_DISCOUNT_RATE;
						disNum++;
					}
				}
				printf("(�������� �������� ����)���� �� ���� 1�α��� ���� ����˴ϴ�.\n");							
			break;
			case 4:
				discountType[indexOfArray] = "�ް��庴 �������";
				for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
					if (ticketCount > 2){
						totalPrice += price;
						num++; 
					} else {
						totalDiscountPrice += price * MILITARY_DISCOUNT_RATE;
						disNum++;
					}
				}
				printf("�ް��庴 �� ���� 1�α��� ���� ����˴ϴ�.\n");							
			break;
			case 5:
				discountType[indexOfArray] = "�ӻ�� �������";
				if (gender == 2 || gender == 4){
					for (int ticketCount = 1; ticketCount <= qty; ticketCount++){
						if (ticketCount > 1){
							totalPrice += price;
							num++; 
						} else {
							totalDiscountPrice += price * PREGNANT_DISCOUNT_RATE;
							disNum++;
						}
					printf("(������������) �ӻ�� ���� ���� ����Ǿ����ϴ�.\n");
					}
				} else {
					totalPrice = price*qty;
					num++; 
					printf("�˼��մϴ�, �ӻ�� ���� �����̾�� �մϴ�.\n");
				}	
			break;
			case 6:
				discountType[indexOfArray] = "�ٵ��̰��� �������";
				printf("���ΰ��� �ο� ���� �� �ּ���.\n");
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
				printf("(������������) �ο��� (%d��) ���� ����˴ϴ�.\n", numDaDoong);
			break;
		}
		
		//�ջ갪 �迭 ���� 
		arrNum[indexOfArray] = num; 
		arrDiscountNum[indexOfArray] = disNum; 
		arrTotalPrice[indexOfArray] = totalPrice;  
		arrTotalDiscountPrice[indexOfArray] = totalDiscountPrice;
		
		//���� ȯ�� 
		grandPrice = totalPrice + totalDiscountPrice;
		printf("�� ������ %d�� �Դϴ�.", grandPrice);
		printf(" �����մϴ�.\n");
		printf("\n");
		
		//���� �� �ʱ�ȭ 
		totalPrice = 0;
		totalDiscountPrice = 0;
		num = 0;
		disNum = 0;

		//�ݺ�or ���� Ȯ���Ѵ�.
		printf("��� �߱��Ͻðڽ��ϱ�? \n1. Ƽ�� �߱�\n2. ����\n");
		scanf("%d", &conTicket);	
		printf("\n");
		if (conTicket == 1) {
			indexOfArray++;
		}
	} while(conTicket == 1);
	
	
	//�����ϸ� �ֹ������� ��� ��µȴ�.
	printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n");
	printf("=========================== �Ե�����===========================\n");
	for (int orderTicketCount = 0; orderTicketCount<=indexOfArray; orderTicketCount++){//���� Ƽ�� ��� 
		if  (arrDiscountNum[orderTicketCount] >= 1) {
			printf("%s %6s %10s X %2d %7d�� %19s\n",ticketType[orderTicketCount], dayType[orderTicketCount],personType[orderTicketCount],arrDiscountNum[orderTicketCount], arrTotalDiscountPrice[orderTicketCount], discountType[orderTicketCount]);
		}
		if (arrNum[orderTicketCount] >= 1) {
			printf("%s %6s %10s X %2d %7d�� %19s\n",ticketType[orderTicketCount], dayType[orderTicketCount],personType[orderTicketCount],arrNum[orderTicketCount], arrTotalPrice[orderTicketCount], "������� ����");
		}
	}
	printf("===============================================================\n");
	
	//���α׷� ���� �� ���⳻���� ���Ϸ� �����Ѵ�. 
	return 0;
}
