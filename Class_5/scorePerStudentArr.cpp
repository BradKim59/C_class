#include <stdio.h>

int main() {
	/** 학생은 max 20, 과목은 max 10개 라고 가정
다음과 같이 선언
// score[학생번호][과목번호] => 모든 점수 저장
int score[21][10] = {0};

// sum[학생번호] => 학생번호 별 과목총점
int sum[21] = {0};

// ave[학생번호] => 학생번호 별 과목 평균
int ave[21] = {0};

// subjectAve[과목번호] => 과목 별 평균
int subjectAve[10]; 
*/
	int StudentCount;
	int subjectCount;
	int indexStudent;
	int indexClass;
	int scoreKopo;
	int score [21][10] = {0};
	int sum [21] = {0};
	int subjectSum [21] = {0};

	float average[21] = {0};
	float subjectAverage[21] = {0};

	//입력 
	printf("과목 수 입력 : \n");
	scanf("%d",&subjectCount);
	printf("학생 수 입력 : \n");
	scanf("%d", &StudentCount);
	for (int index = 1; index <= StudentCount; index++){
		printf("Koposw%d 학생의 점수 %d개를 차례대로 입력하세요. : \n",index , subjectCount);
		for (int index2 = 1; index2 <= subjectCount; index2++){
			scanf("%d", &score[index][index2]);	
		}
	}	 
	// 계산 
	for (int index = 1; index <= StudentCount; index++){
		for (int index2 = 1; index2 <= subjectCount; index2++){
			sum[index] += score[index][index2];// 학생이 고정되고 점수가 더해짐. 
			subjectSum[index2] += score [index][index2];
			// 과목이 바뀔때마다 더해지는 위치도 달라짐, 학생이 바뀌면서 똑같은 과목에 더해짐. 
		}
		average[index] = sum[index] / (float) subjectCount; // 학생 별로 카운트 되며 평균 
	}
	for (int index = 1; index <= subjectCount; index++) {
		subjectAverage[index] = subjectSum[index] / (float) subjectCount;//과목별로 카운트되며 평균. 
	}
	// 출력
	printf("\n");
	for (int index = 1; index < StudentCount; index++) {
		printf("koposw%d 학생의 과목 총점 %d, 평균 %.2f\n", index, sum[index], average[index]);
	}
	for (int index = 1; index < subjectCount; index++) {
		printf("%d 과목 별 평균 %.2f\n", index, sum[index], average[index]);
	}
} 
