
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
//5.8 initialization of pointer arrays
//5.9 pointer vs multi-dimensional arrays
//5.10 command-line arguments
//5.11 pointers to functions
//5.12 complicated declarations


