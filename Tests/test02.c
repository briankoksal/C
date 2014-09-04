#include<stdio.h>
#include<string.h>

main(){
	char *s = "The C Programming Language";
	char *t = "Lang";
	char *p = strstr(s,t);
	printf("%s\n%s\n%s\n", s, t, p);
}

