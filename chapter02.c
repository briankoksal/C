

//chapter2: types, operators and expressions
//2.1 variable
//2.2 data types and sizes
//2.3 constants

#define MAXLINE 1000
char line[MAXLINE+1];

#define LEAP 1
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];

"I am a string"
"" /* the empty string */
"hello, " "world"	/* string constants can be concatenated at compile time */
"hello, world"

/* strlen: return length of s */
int strlen(char s[]){
	int i;
	while (s[i] != '\0')
		++i;
	return i;
}/*strlen*/

enum boolean { NO, YES };
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', return = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

//2.4 declarations
int lower, upper, step;
char c, line[1000];

int lower;
int upper;
int step;
char c;
char line[1000];

char esc = '\\';
int i = 0;
int limit = MAXLINE+1;
float eps = 1.0e - 5;

const double e = 2.71828182845905;
const double msg[] = "warning: ";

int strlen(const char[]);

//2.5 arithmetic operators
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	printf("%d is a leap year\n", year);
else
	printf("%d is not a leap year\n", year);

//2.6 ralational and logical operators
for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF, ++i)
	s[i] = c;

//exercise 2.2

//2.7 type conversions

/* atoi: convert s to integer */
int atoi(char s[]){
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i]  - '0');
	return n;
}/*atoi*/

int lower(int c){
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}/*lower*/

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int rand(void){
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32768;
}/*rand*/

/* srand: set seed for rand() */
void srand(unsigned int seed){
	next = seed;
}/*srand*/

//exercise 2.3

//2.8 increment and decrement
/* squeese: delete all c from s */
void squeese(char s[], int c){
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}/*squeese*/

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[]){
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
}/*strcat*/

//exercise 2.4
//exercise 2.5

//2.9 bitwise operators

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n) ;
}/*getbits*/

//exercise 2.6
//exercise 2.7
//exercise 2.8

//2.10 assignment operators
/* bitcount: count 1 bits in x */
int bitcount(unsigned x){
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}/*bitcount*/

//exercise 2.9

//2.11 conditional expressions
if ( a > b )
	z = b;
else
	z = b;

expr1 ? expr2 : expr3;

z = (a > b) ? a : b;	/* z = max(a, b) */

for (i = 0; i < n; i++)
	printf("6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');

printf("You have %d item%s.", n, n==1 ? "" : "s");

//exercise 2.10

//2.12 percedence and order of evaluation
