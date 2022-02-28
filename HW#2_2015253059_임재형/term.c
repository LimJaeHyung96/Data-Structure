#include <stdio.h>
#pragma warning ( disable : 4996 )

#define MAX_TERMS 20


typedef struct {    // 구조체 term 정의
    float coef; // 다항식의 각 항의 계수를 저장할 변수
    int exp;    // 다항식의 각 항의 차수를 저장할 변수
} term;

void addTerm(term* A, term* B, term* C) {
    int a = 0;
    while (A[a].exp != 0 || A[a].coef != 0) { //A의 요소들을 C로 옮김
        C[a].exp = A[a].exp;
        C[a].coef = A[a].coef;
        a++;
    }
    
    int b = 0;
    while (B[b].exp != 0 || B[b].coef != 0) {
        int c = 0;
        int expCheck = 0; //차수가 같은 값이 없을 경우 배열의 맨 뒤에 추가하기 위해 세팅
        float temp = 0;
        while (C[c].exp != 0 || C[c].coef != 0) {
            if (B[b].exp == C[c].exp) { //B와 C의 차수가 같을 때 계수를 합쳐서 C에 저장
                temp = B[b].coef + C[c].coef;
                C[c].coef = temp;
                expCheck = 1; //차수가 같은 값이 있을 경우 맨 뒤에 추가 안함
                break;
            } 
            c++;
        }
       if (expCheck == 0) { //배열의 맨 뒤에 추가
            C[c].exp = B[b].exp;
            C[c].coef = B[b].coef;
       }
        b++;
    }

    int tempExp;
    float tempCoef;
    int i = 0, j = 0;
    while (C[i].exp != 0 || C[i].coef != 0) { //다항식을 내림차순으로 정렬함
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