

//chapter4: functions and program structure
//4.1 basics of functions

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching pattern */
main(){
	char line[MAXLINE];

	int found = 0;
	while (getline(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}/*main*/

/* getline: get line into s, return length */
int getline(char s[], int lim){
	int c, i;
	for (i = 0; i < lim - 1 &&(c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}/*getline*/

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]){
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && t[k]==s[j]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}/*strindex*/

//exercise 4.1

//4.2 functions returning non-integers

#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]){
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (val = 0.0; isdigit(s[i]);i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}/*atof*/

//exercise 4.2

//4.3 external variables
#include <stdio.h>
#include <stdlib.h>

#define MAXOP	100
#define NUMBER	'0'

/* reverse Polish caculator */
main(){
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command%s\n", s);
			break;
		}
	}
	return 0;
}/*main*/


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto values */
void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}/*push*/

/* pop: pop and return pop value from stack */
double pop(void){
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}/*pop*/

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]){
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}/*getop*/

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}/*getch*/

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("unget: too many characters\n");
	else
		buf[bufp++] = c;
}/*ungetch*/

//exercise 4.3
//exercise 4.4
//exercise 4.5
//exercise 4.6
//exercise 4.7
//exercise 4.8
//exercise 4.9
//exercise 4.10

//4.4 scope rules
//4.5 header files
//4.6 static variables

static char buf[];
static int bufp = 0;

int getch(void) {...}
void ungetch(int c) {...}

//exercise 4.11

//4.7 register variables
//4.8 block structures
//4.9 initialization
//4.10 recursion
#include<stdio.h>

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[], int left, int right){
	int i, last;
	void swap(int v[], int left, int right);

	if (left >= right)
		return;

	swap(v, left, (left + right)/2);	/* do nothing if array contains */
	last = left;						/* fewer than two elements */
	for (i = left+1; i <= right; i++)	/* move partition elem */
		if (v[i] < v[left])				/* to v[0]*/
			swap(v, ++last, i);
	swap(v, left, last);				/* restore partition elem */
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}/*qsort*/

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j){
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}/*swap*/

//exercise 4.12
//exercise 4.13

//4.11 the c preprocessor
//4.11.1 file inclusion
#include "filename"
#include <filename>

//4.11.2 macro substitution
#define name replacement_text
#define forever for(;;)	/* infinite loop */
#define max(A, B) ((A) > (B) ? (A) : (B))
max(i++, j++)	/* WRONG */
#define square(x) x * x /* WRONG */
#undef getchar
int getchar(void) { ... }
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back

//4.11.3 conditional inclusion
#if !defined(HDR)
#define HDR
/* contents of hdr.h go here */
#endif

#if SYSTEM == SYSV
	#define HDR "sysv.h"
#elif SYSTEM == BSD
	#define HDR "bsd.h"
#elif SYSTEM == MSDOS
	#define HDR "msdos.h"
#else
	#define HDR "default.h"
#endif
#include HDR

#ifndef HDR
#define HDR
/* contents of hdr.h go here */
#endif

//exercise 4.14

