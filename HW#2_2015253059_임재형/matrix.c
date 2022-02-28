#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}matrix;

void transposeSM(matrix a[], matrix b[]) {
	for (int i = 0; i < 11; i++) { //전치행렬 연산을 수행함
		b[i].col = a[i].row;
		b[i].row = a[i].col;
		b[i].value = a[i].value;
	}

	matrix temp[] = {0, };
	for (int i = 10; i >= 2; i--) { //열 순서로 오름차순 정렬함
		for (int j = 1; j < i; j++) {
			if (b[j].col > b[j + 1].col) {
				temp[0] = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp[0];
			}
		}
	}

	for (int i = 10; i >= 2; i--) { //행 순서로 오름차순 정렬함
		for (int j = 1; j < i; j++) {
			if (b[j].row > b[j + 1].row) {
				temp[0] = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp[0];
			}
		}
	}
}

int main() {
	int i, j;
	matrix a[11] = {	{8,7,10}, 
						{0,2,2},
						{0,6,12},
						{1,4,7},
						{2,0,23},
						{3,3,31},
						{4,1,14},
						{4,5,25},
						{5,6,6},
						{6,0,52},
						{7,4,11}
	};
	matrix b[11] = {0, };
	transposeSM(a, b);
	
	printf("Matrix a\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, a[i].row, a[i].col, a[i].value);
	printf("Transpose Matrix b\n");
	for(i=0; i<11; i++)
		printf("%d: %d %d %d\n", i, b[i].row, b[i].col, b[i].value);
	return 0;
}
