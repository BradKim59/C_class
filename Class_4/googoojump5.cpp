#include <stdio.h>

int main(){
	const int WIDTH = 5;
	const int MAX = 15;
	for (int indexA = 2; indexA < 15; indexA += 5) {//�� �ⷰ, 5�� ���� �ö󰣴�. 
		for (int indexB = 1; indexB <= 9; indexB++) {//loop ��� 
			for (int indexC = 0; indexC < WIDTH; indexC++) {
			//�ܰ� loop�� �Ѱ����� ������ ������, indexC �� ���鼭 �ܿ� �������� ��� �ȴ�. 
				if (indexA + indexC > MAX) { //�� �մ��� 16�� �Ǹ� ������ 
					break;					
				}
				printf("%d X %d = %d\t", (indexA+indexC), indexB, (indexA+indexC)*indexB);
			}
			printf("\n"); //indexC �ݺ� ������ �����ϰ� �� �ݺ����� �ٽ� �ö󰣴�. 
		}
	}
	return 0;
//				printf("%d X %d = %d\t", indexA, indexB, indexA*indexB);
//			printf("%d X %d = %d\t", indexA+1, indexB, (indexA+1)*indexB);
//			printf("%d X %d = %d\t", indexA+2, indexB, (indexA+2)*indexB);
//			printf("%d X %d = %d\t", indexA+3, indexB, (indexA+3)*indexB);
//			printf("%d X %d = %d\n", indexA+4, indexB, (indexA+4)*indexB);
}
