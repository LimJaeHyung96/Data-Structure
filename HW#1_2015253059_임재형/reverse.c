void reverse(char* p) {
	printf("> ");
	//���ڿ��� ���̸� �̿��ؼ� ���� ���ں��� �ϳ��� ���
	for (int i = strlen(p) - 1; i >= 0; i--) {
		printf("%c", p[i]);
	}
	printf("\n");
}