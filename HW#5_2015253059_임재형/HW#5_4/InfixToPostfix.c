#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"
#include "InfixToPostfix.h"

// ������, �ǿ�����, ��ȣ -> enueration type ��ȯ, operator, operand, parenthesis -> enueration type transform
precedence getToken(char ch) {
	precedence token;
	switch(ch) {
		case '(':	token = lparen;		break;
		case ')': 	token = rparen;		break;
		case '+':	token = plus;		break;
		case '-':	token = minus;		break;
		case '*':	token = multiply;	break;
		case '/':	token = divide;		break;
		case '%':	token = mod;		break;
		case '\0':	token = eos;		break;
		default:	token = operand;
	}
	
	return token;
}

// enumeration type�� ���� ������, ��ȣ ���, operator, parenthesis display according to enumeration type
char printToken(precedence token) {
	char ch = 'a';
	switch(token) {
		case lparen:	ch = '(';	break;
		case rparen:	ch = ')';	break;
		case plus:		ch = '+';	break;
		case minus:		ch = '-';	break;
		case multiply:	ch = '*';	break;
		case divide:	ch = '/';	break;
		case mod:		ch = '%';	break; 
	}
	
	return ch;
}

// ������ �켱���� ���: ��ȣ < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
int prec(precedence symbol) {
	switch(symbol) {
		case lparen:
		case rparen:	return 0;
		case plus:
		case minus:		return 1;
		case multiply:
		case divide:
		case mod:		return 2;
	}
}

// ����ǥ��� -> ����ǥ��� ��ȯ ����, inflix notation -> postfix notation transform operation
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// �������� ���� ���, recording the type of operator
	
	while (token != eos) {
		if (token == operand) { //�ǿ����ڴ� �״�� ���
			result[n++] = exp[0];
		}
		else if (token == plus || token == minus || token == multiply || token == divide) { //�������Ͻ�
			if (isEmpty(S)) //������ ��������̸� push
				push(S, printToken(token));
			else if (prec(getToken(peek(S))) < prec(token)) //top�� �ִ� �ͺ��� �켱������ �� ������ push
				push(S, printToken(token));
			else if (prec(getToken(peek(S))) >= prec(token)) { //top�� �ִ� �ͺ��� �켱������ ���ų� ������
				result[n++] = pop(S); //���
				while (prec(getToken(peek(S))) < prec(token)) { //�˻��ϴ� �������� �켱������ top���� ���� ������ ��� pop
					result[n++] = pop(S);
				}
				push(S, printToken(token)); //�ش� �����ڸ� push����
			}
		}
		else if (token == lparen) //(�� ������ push
			push(S, printToken(token));
		else if (token == rparen) { //top�� (�϶����� ���
			while (peek(S) != '(') {
				result[n++] = pop(S);
			}
			pop(S); //(�� pop�ؼ� ����
		}
		exp++; //���� ���� �˻�
		symbol = exp[0];
		token = getToken(symbol);
	}
	while (!isEmpty(S)) { //���ÿ� ���� ������ ���� ���
		result[n++] = pop(S);
	}

	return result;
}

// ����ǥ����� ��� ����, computation of postfix notaion
float evalPostfix(Stack* S, char* exp) {
	int op1, op2;
	int n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);
	
	while (token != eos) {
		if (token == operand) //�����ڴ� ���ÿ� push
			push(S, exp[0]-48); //char���� int������ ��ȯ
		else if (token == plus || token == minus || token == multiply || token == divide) { //�������Ͻ�
			op2 = pop(S);
			op1 = pop(S);
			if (token == plus) //�� �����ڿ� �°� ����� �ؼ� ���ÿ� push����
				push(S, op1 + op2);
			else if (token == minus)
				push(S, op1 - op2);
			else if (token == multiply)
				push(S, op1 * op2);
			else if (token == divide)
				push(S, op1 - op2);
		}
		exp++; //���� ���� �˻�
		symbol = exp[0];
		token = getToken(symbol);
	}

	return pop(S); //������ top�� �ִ� ��� ���
}
