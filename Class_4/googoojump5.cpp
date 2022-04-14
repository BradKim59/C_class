#include <stdio.h>

int main(){
	const int WIDTH = 5;
	const int MAX = 15;
	for (int indexA = 2; indexA < 15; indexA += 5) {//단 출럭, 5씩 숫자 올라간다. 
		for (int indexB = 1; indexB <= 9; indexB++) {//loop 출력 
			for (int indexC = 0; indexC < WIDTH; indexC++) {
			//단과 loop가 한가지씩 내려올 때마다, indexC 가 돌면서 단에 더해지며 출력 된다. 
				if (indexA + indexC > MAX) { //두 합단이 16이 되면 출력취소 
					break;					
				}
				printf("%d X %d = %d\t", (indexA+indexC), indexB, (indexA+indexC)*indexB);
			}
			printf("\n"); //indexC 반복 끝나면 개행하고 단 반복으로 다시 올라간다. 
		}
	}
	return 0;
//				printf("%d X %d = %d\t", indexA, indexB, indexA*indexB);
//			printf("%d X %d = %d\t", indexA+1, indexB, (indexA+1)*indexB);
//			printf("%d X %d = %d\t", indexA+2, indexB, (indexA+2)*indexB);
//			printf("%d X %d = %d\t", indexA+3, indexB, (indexA+3)*indexB);
//			printf("%d X %d = %d\n", indexA+4, indexB, (indexA+4)*indexB);
}
