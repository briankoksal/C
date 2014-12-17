#include<stdio.h>
int output(char *s, char *t){ while(*t!='\0') *s++ = *t++; return 0; }
int main(){ 
	char s[10];
	char t[10] = "Hello1234";
	output(s,t);
	printf("%s", s);
	return 0;
}

