#include <stdio.h>

int main() {
	/** �л��� max 20, ������ max 10�� ��� ����
������ ���� ����
// score[�л���ȣ][�����ȣ] => ��� ���� ����
int score[21][10] = {0};

// sum[�л���ȣ] => �л���ȣ �� ��������
int sum[21] = {0};

// ave[�л���ȣ] => �л���ȣ �� ���� ���
int ave[21] = {0};

// subjectAve[�����ȣ] => ���� �� ���
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

	//�Է� 
	printf("���� �� �Է� : \n");
	scanf("%d",&subjectCount);
	printf("�л� �� �Է� : \n");
	scanf("%d", &StudentCount);
	for (int index = 1; index <= StudentCount; index++){
		printf("Koposw%d �л��� ���� %d���� ���ʴ�� �Է��ϼ���. : \n",index , subjectCount);
		for (int index2 = 1; index2 <= subjectCount; index2++){
			scanf("%d", &score[index][index2]);	
		}
	}	 
	// ��� 
	for (int index = 1; index <= StudentCount; index++){
		for (int index2 = 1; index2 <= subjectCount; index2++){
			sum[index] += score[index][index2];// �л��� �����ǰ� ������ ������. 
			subjectSum[index2] += score [index][index2];
			// ������ �ٲ𶧸��� �������� ��ġ�� �޶���, �л��� �ٲ�鼭 �Ȱ��� ���� ������. 
		}
		average[index] = sum[index] / (float) subjectCount; // �л� ���� ī��Ʈ �Ǹ� ��� 
	}
	for (int index = 1; index <= subjectCount; index++) {
		subjectAverage[index] = subjectSum[index] / (float) subjectCount;//���񺰷� ī��Ʈ�Ǹ� ���. 
	}
	// ���
	printf("\n");
	for (int index = 1; index < StudentCount; index++) {
		printf("koposw%d �л��� ���� ���� %d, ��� %.2f\n", index, sum[index], average[index]);
	}
	for (int index = 1; index < subjectCount; index++) {
		printf("%d ���� �� ��� %.2f\n", index, sum[index], average[index]);
	}
} 
