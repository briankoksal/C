
#include <stdio.h>

int print(char *s);
int printbackward(char *s);
int main(){
	char s[] = "Hello, World!";
	char amessage[] = "now is the time";
	char *pmessage = "now is the time!";
	print(s);
	printbackward(s);
	print(amessage);
	print(pmessage);
return 0; }

int print(char *s){
	for (char *p = s; *p != '\0'; p++)
		putchar(*p);
	putchar('\n');
return 0; }

int printbackward(char *s){
	char *p = NULL, *q = NULL;
	for (p = s; *p != '\0'; p++);
	p--;
	for (q = p; q != s; q--)
		putchar(*q);
	putchar(*q);
	putchar('\n');
return 0; }

