// 5.1 Pointers and Addresses
// 5.2 Pointers and Function Arguments
// 5.3 Pointers and Arrays
// 5.4 Address Arithmetic
// 5.5 Character Pointers and Functions
// 5.6 Pointer Arrays; Pointers to Pointers
// 5.7 Multi-dimensional Arrays
// 5.8 Initialization of Pointer Arrays
// 5.9 Pointers vs. Multi-dimensional Arrays
// 5.10 Command-line Arguments
// 5.11 Pointers to Functions
// 5.12 Complicated Declarations

//chapter5: pointers and arrays
//pointer is a variable that contains the address of a variable
//generic pointer: void *

//5.1 pointers and addresses
//a pointer is a group of cells that can hold an address
int x = 1, y = 2, z[10];
int *ip;	/* ip is a pointer to int */
ip = &x;	/* ip now is pointed to x */
y = *ip;	/* y is now 1 */
*ip = 0;	/* x is now 0 */
ip = &z[0];	/* ip now points to z[0] */

double *dp, atof(char *);
*ip = *ip + 10;
y = *ip + 1;
*ip += 1;
++*ip;
(*ip)++;
iq = ip;

//5.2 pointers and function arguments
swap(a, b);
void swap(int x, int y){	/* WRONG */
	int temp;

	temp = x;
	x = y;
	y = temp;
}

swap(&a, &b);
void swap(int *px, int *py){
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}

int n, array[SIZE], getint(int *);
for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
	;


#include <ctype.h>
int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn){
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}/*getint*/


//5.3 pointers and arrays
/* strlen: return length of string s */
int strlen(char *s){
	int n ;
	for (n = 0; *s != '\0'; n++)
		n++;
	return n;
}/*strlen*/

strlen("hello, world");	/* string constant */
strlen(array);			/* char array[100] */
strlen(ptr);			/* char *ptr; */

//5.4 address arithmetic
/* strlen: return length of string s */
int strlen(char *s){
	char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}/*strlen*/

//5.5 character pointers and functions
"I am a string"
printf("hello, world\n");
char *pmessage;
pmessage = "now is the time";
char amessage[] = "now is the time";	/* an array */
char *pmessage = "now is the time";		/* a pointer */

/* strcpy: copy t to s; array subscript version */
void strcpy(char *s, char *t)
{
	int i;
	i = 0;
	while ((s[i] = s[i]) ! = '\0')
		i++;
}
/* strcpy: copy t to s; pointer version 1 */
void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}
/* strcpy: copy t to s; pointer version 2 */
void strcpy(char *s, char *t)
{
	while (((*s++ = *t++)) != '\0')
		;
}
/* strcpy: copy t to s; pointer version 3 */
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t){
	int i;
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}/*strcmp*/

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t){
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}/*strcmp*/

//exercise 5.3: write a pinter version of the function strcat that we showed in chapter2: strcat(s,t) copies the string t to the end of s.
//exercise 5.4: write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
//exercise 5.5: write version of the library function strncpy, strncat, and strncmp, which operates on at most the first n characters of their argument strings. for example, strncpy(s,t,n) copies at most n characters of t to s.
//exercise 5.6: rewrite appropriate program from earlier chapters and exercises with pointers instead of array indexing. good possibilities include geline, atoi, itoa, and theri variants, reverse, and strindex and getop.

//5.6 pointer arrays and pointers to pointers
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readline(char *lineptr[], int nlines);
void writeline(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main(){}/*main*/

#define MAXLEN 1000
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writeline(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* getline: get line into s, return length */
int getline(char *s, int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 &&(c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, right);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
//exercise 5.7: rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. how much faster the program is?

//5.7 multi-dimensional arryas
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

//5.8 initialization of pointer arrays
/* month_name: return name of n-th month */
char *month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};
	return (n < 1 || n > 12) ? name[0] : name[n];
}

//5.9 pointer vs multi-dimensional arrays
char *name[] = { "Illegal month", "Jan", "Feb", "Mar" };
char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar" };

//5.10 command-line arguments
#include <stdio.h>
/* echo command-line arguments; 1st version */
main(int argc, char *argv[])
{
	int i;
	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc-1) ? " " : "");
	printf("\n");
	return 0;
}


#include <stdio.h>
/* echo command-line arguments; 2nd version */
main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
	return 0;
}


#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (getline(line, MAXLINE) > 0)
	if (strstr(line, argv[1]) != NULL) {
		printf("%s", line);
		found++;
	}
return found;
}


#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
				break;
	}

	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (getline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}

//5.11 pointers to functions

#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
main(int argc, char *argv[])
{
	int nlines; /* number of input lines read */
	int numeric = 0; /* 1 if numeric sort */
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right) 	/* do nothing if array contains */
		return; 		/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}
#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j;)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

//5.12 complicated declarations


/* dcl: parse a declarator */
void dcl(void)
{
	int ns;
	for (ns = 0; gettoken() == '*'; ) 	/* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}


/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
	int type;
	if (tokentype == '(') { 		/* ( dcl ) */
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME) 	/* variable name */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");

	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype; 				/* type of last token */
char token[MAXTOKEN]; 		/* last token string */
char name[MAXTOKEN]; 		/* identifier name */
char datatype[MAXTOKEN]; 	/* data type = char, int, etc. */
char out[1000];

main() /* convert declaration to words */
{
	while (gettoken() != EOF) { 	/* 1st token on line */
		strcpy(datatype, token); 	/* is the datatype */
		out[0] = '\0';
		dcl(); 						/* parse rest of line */
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}


int gettoken(void) /* return next token */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;

	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}


/* undcl: convert word descriptions to declarations */
main()
{

	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {

		strcpy(out, token);

		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
	}
	return 0;
}





