#include <stdio.h>
#include <string.h>

int main(){
	char *s = "Jane Street Company is a trading firm on Wall Street";
	char *t = "aeiou";
	char *p = strpbrk(s,t);
	char *q = strpbrk(s,t);
	printf("%s\n%s\n%s\n%s\n",s,t,p,q);
return 0; }
