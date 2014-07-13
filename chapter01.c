

//chapter1: a tutorial introduction
//1.1 getting started

#include <stdio.h>
main(){
	printf("hello, world\n");
}/*main*/

#include <stdio.h>
main(){
	printf("hello, ");
	printf("world");
	printf("\n");
}/*main*/

//exercise 1.1
//exercise 1.2

//1.2 variables and arithmetic expressions
#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
main(){
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}/*main*/

#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating-point version */
main(){
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}/*main*/

//exercise 1.3
//exercise 1.4

//1.3 the for statement
#include <stdio.h>

/* print Fahrenheit-Celsius table */
main(){
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3.0d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}/*main*/

//exercise 1.5

//1.4 symbolic constants
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

/* print Fahrenheit-Celsius table */
main(){
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3.0d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}/*main*/

//1.5 character input and output
//1.5.1 file copying
#include <stdio.h>

/* copy input to output; 1st version*/
main(){
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}/*main*/

#include <stdio.h>

/* copy input to output; 2nd version */
main(){
	int c;
	while ((c = getchar()) != EOF)
		putchar(c);
}/*main*/

//exercise 1.6
//exercise 1.7

//1.5.2 character counting
#include <stdio.h>

/* count characters in input; 1st version */
main(){
	long nc;

	nc = 0;
	while(getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}/*main*/

#include <stdio.h>

/* count characters in input; 2nd version */
main(){
	double nc;

	for(nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}/*main*/


//1.5.2 line counting
#include <stdio.h>

/* count lines in input */
main(){
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}/*main*/

//exercise 1.8:
//exercise 1.9:
//exercise 1.10:

//1.5.4 word counting
#include <stdio.h>

#define IN  1
#define OUT 0

/* count lines, words, and characters in input */
main(){
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) ! = EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}/*main*/

//exercise 1.11
//exercise 1.12

//1.6 arrays
#include <stdio.h>

/* count digits, white space, others */
main(){
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\t' || c == '\n')
			++nwhite;
		else
			++nother;

	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}/*main*/

//exercise 1.13
//exercise 1.14

//1.7 functions
#include <stdio.h>

int power(int m, int n);

/* test power function */
main(){
	int i;
	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", power(2, i), power(-3, i));
	return 0;
}/*main*/

/* power: raise base to n-th power; n >=0 */
int power(int base, int n){
	int i, p;
	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}/*power*/

//exercise 1.15

//1.8 arguments - call by value
//1.9 character arrays

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main(){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}/*main*/

/* getline: read a line into s, return length */
int getline(char s[], int lim){
	int c, i;
	for (i = 0; i < lim - 1 &&(c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}/*getline*/

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]){
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}/*copy*/

//exercise 1.16
//exercise 1.17
//exercise 1.18
//exercise 1.19

//1.10 external variables and scope
#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline();
void copy();

/* print longest input line; specialized version */
main(){
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline()) > 0)
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}/*main*/

/* getline: specialized version */
int getline(void){
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 &&(c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}/*getline*/

/* copy: specialized version */
void copy(void){
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}/*copy*/

//exercise 1.20
//exercise 1.21
//exercise 1.22
//exercise 1.23
//exercise 1.24

