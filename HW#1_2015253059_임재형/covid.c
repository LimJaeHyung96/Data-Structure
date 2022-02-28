#include <stdio.h>

//학생 출입명부 구조체 작성
struct stdList {
	int stdNum;
	char name[7];
	int inTime;
};

int main(void){
	struct stdList s[5];
	struct stdList temp;

	for (int a = 0; a < 5; a++) {
		printf("학번,이름,출입시간을 입력해주세요!\n");

		scanf("%d %s %d", &(s[a].stdNum), s[a].name, &(s[a].inTime));
		printf("\n");
	}

	//입력 날짜를 오름차순으로 정렬해주는 코드
	for (int i = 4; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (s[j].inTime > s[j + 1].inTime) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}

	printf("\n정렬된 출입명부 입니다.\n");

	for (int b = 0; b < 5; b++) {
		printf("학번 : %d\n", s[b].stdNum);
		printf("이름 : %s\n", s[b].name);
		printf("출입시간 : %04d\n", s[b].inTime); //0930의 형식으로 보여주기 위해 0으로 채움
	}

	return 0;
}