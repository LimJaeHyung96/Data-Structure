#include <stdio.h>

//�л� ���Ը�� ����ü �ۼ�
struct stdList {
	int stdNum;
	char name[7];
	int inTime;
};

int main(void){
	struct stdList s[5];
	struct stdList temp;

	for (int a = 0; a < 5; a++) {
		printf("�й�,�̸�,���Խð��� �Է����ּ���!\n");

		scanf("%d %s %d", &(s[a].stdNum), s[a].name, &(s[a].inTime));
		printf("\n");
	}

	//�Է� ��¥�� ������������ �������ִ� �ڵ�
	for (int i = 4; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (s[j].inTime > s[j + 1].inTime) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}

	printf("\n���ĵ� ���Ը�� �Դϴ�.\n");

	for (int b = 0; b < 5; b++) {
		printf("�й� : %d\n", s[b].stdNum);
		printf("�̸� : %s\n", s[b].name);
		printf("���Խð� : %04d\n", s[b].inTime); //0930�� �������� �����ֱ� ���� 0���� ä��
	}

	return 0;
}