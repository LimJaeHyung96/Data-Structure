void reverse(char* p) {
	printf("> ");
	//문자열의 길이를 이용해서 뒤의 문자부터 하나씩 출력
	for (int i = strlen(p) - 1; i >= 0; i--) {
		printf("%c", p[i]);
	}
	printf("\n");
}