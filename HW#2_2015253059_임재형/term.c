#include <stdio.h>
#pragma warning ( disable : 4996 )

#define MAX_TERMS 20


typedef struct {    // ����ü term ����
    float coef; // ���׽��� �� ���� ����� ������ ����
    int exp;    // ���׽��� �� ���� ������ ������ ����
} term;

void addTerm(term* A, term* B, term* C) {
    int a = 0;
    while (A[a].exp != 0 || A[a].coef != 0) { //A�� ��ҵ��� C�� �ű�
        C[a].exp = A[a].exp;
        C[a].coef = A[a].coef;
        a++;
    }
    
    int b = 0;
    while (B[b].exp != 0 || B[b].coef != 0) {
        int c = 0;
        int expCheck = 0; //������ ���� ���� ���� ��� �迭�� �� �ڿ� �߰��ϱ� ���� ����
        float temp = 0;
        while (C[c].exp != 0 || C[c].coef != 0) {
            if (B[b].exp == C[c].exp) { //B�� C�� ������ ���� �� ����� ���ļ� C�� ����
                temp = B[b].coef + C[c].coef;
                C[c].coef = temp;
                expCheck = 1; //������ ���� ���� ���� ��� �� �ڿ� �߰� ����
                break;
            } 
            c++;
        }
       if (expCheck == 0) { //�迭�� �� �ڿ� �߰�
            C[c].exp = B[b].exp;
            C[c].coef = B[b].coef;
       }
        b++;
    }

    int tempExp;
    float tempCoef;
    int i = 0, j = 0;
    while (C[i].exp != 0 || C[i].coef != 0) { //���׽��� ������������ ������
        j = i + 1;
        while (C[j].exp != 0 || C[j].coef != 0) {
            if (C[i].exp < C[j].exp) {
                tempExp = C[j].exp;
                tempCoef = C[j].coef;
                C[j] = C[i];
                C[i].exp = tempExp;
                C[i].coef = tempCoef;
            }
            j++;
        }
        i++;
    }
}


void printTerm(term* p) {
    int i = 0;
    while (p[i].exp != 0 || p[i].coef != 0) {
        printf("%3.0fx^%d", p[i].coef, p[i].exp);
        i++;
        if (p[i].exp != -1 && p[i].coef > 0)
            printf(" +");
    }
    printf("\n");
}

int main() {
    term A[MAX_TERMS] = { {3,19}, {4,5}, {1,0} };
    term B[MAX_TERMS] = { {5,8}, {7,5}, {1,1} };
    term C[MAX_TERMS] = { 0 };
    addTerm(A, B, C);

    printf("\n A(x)="); printTerm(A);
    printf("\n B(x)="); printTerm(B);
    printf("\n C(x)="); printTerm(C);
    
    return 0;
}