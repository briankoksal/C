#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *p = malloc(sizeof(char)*10);
	memcpy(p, "HelloWorld", 10);
	p = memset(p, '\0', 5);
	for (int i = 0; i < 10; i++) putchar(*p++);
return 0; }
