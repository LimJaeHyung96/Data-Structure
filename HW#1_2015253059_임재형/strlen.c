int strlen(char* s) {
	char* p = s;

	while (*p) //null 문자가 올 때까지 while문 동작
		p++;

	return p-s; //null문자가 있는 곳의 주소(p)와 문자열의 처음 시작 주소(s)를 빼면 문자열의 길이가 나옴
}