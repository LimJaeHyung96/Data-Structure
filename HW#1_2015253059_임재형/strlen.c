int strlen(char* s) {
	char* p = s;

	while (*p) //null ���ڰ� �� ������ while�� ����
		p++;

	return p-s; //null���ڰ� �ִ� ���� �ּ�(p)�� ���ڿ��� ó�� ���� �ּ�(s)�� ���� ���ڿ��� ���̰� ����
}