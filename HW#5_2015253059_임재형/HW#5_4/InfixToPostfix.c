#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"
#include "InfixToPostfix.h"

// 연산자, 피연산자, 괄호 -> enueration type 변환, operator, operand, parenthesis -> enueration type transform
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

// enumeration type에 따라 연산자, 괄호 출력, operator, parenthesis display according to enumeration type
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

// 연산자 우선순위 계산: 괄호 < +, - < *, /, %, calculate operator priority : parentheses < +, - < *, /, %
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

// 중위표기식 -> 후위표기식 변환 연산, inflix notation -> postfix notation transform operation
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// 연산자의 종류 기록, recording the type of operator
	
	while (token != eos) {
		if (token == operand) { //피연산자는 그대로 출력
			result[n++] = exp[0];
		}
		else if (token == plus || token == minus || token == multiply || token == divide) { //연산자일시
			if (isEmpty(S)) //스택이 공백상태이면 push
				push(S, printToken(token));
			else if (prec(getToken(peek(S))) < prec(token)) //top에 있는 것보다 우선순위가 더 높으면 push
				push(S, printToken(token));
			else if (prec(getToken(peek(S))) >= prec(token)) { //top에 있는 것보다 우선순위가 같거나 낮으면
				result[n++] = pop(S); //출력
				while (prec(getToken(peek(S))) < prec(token)) { //검사하는 연산자의 우선순위가 top보다 높을 때까지 계속 pop
					result[n++] = pop(S);
				}
				push(S, printToken(token)); //해당 연산자를 push해줌
			}
		}
		else if (token == lparen) //(는 무조건 push
			push(S, printToken(token));
		else if (token == rparen) { //top이 (일때까지 출력
			while (peek(S) != '(') {
				result[n++] = pop(S);
			}
			pop(S); //(를 pop해서 버림
		}
		exp++; //다음 문자 검사
		symbol = exp[0];
		token = getToken(symbol);
	}
	while (!isEmpty(S)) { //스택에 남은 연산자 전부 출력
		result[n++] = pop(S);
	}

	return result;
}

// 후위표기식의 계산 연산, computation of postfix notaion
float evalPostfix(Stack* S, char* exp) {
	int op1, op2;
	int n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);
	
	while (token != eos) {
		if (token == operand) //연산자는 스택에 push
			push(S, exp[0]-48); //char형을 int형으로 변환
		else if (token == plus || token == minus || token == multiply || token == divide) { //연산자일시
			op2 = pop(S);
			op1 = pop(S);
			if (token == plus) //각 연산자에 맞게 계산을 해서 스택에 push해줌
				push(S, op1 + op2);
			else if (token == minus)
				push(S, op1 - op2);
			else if (token == multiply)
				push(S, op1 * op2);
			else if (token == divide)
				push(S, op1 - op2);
		}
		exp++; //다음 문자 검사
		symbol = exp[0];
		token = getToken(symbol);
	}

	return pop(S); //스택의 top에 있는 결과 출력
}
