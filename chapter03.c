

//chapter3: control flow
//3.1 statements and blocks
x = 0;
i++;
printf(...);
//expression; -> statement

//3.2 if-else
if (n > 0)
	if (a > b)
		z = a;
	else
		z = b;

//3.3 else-if
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}/*binsearch*/

//exercise 3.1

//3.4 switch
#include <stdio.h>

main(){
	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF) {
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			ndigit[c-'0']++;
			break;
		case ' ':
		case '\n':
		case '\t':
			nwhite++;
			break;
		default:
			nother++;
			break;
		}
	}
	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}/*main*/

//exercise 3.2

//3.5 loops - while and for

while ((c = getchar()) == ' ' || c == '\n' || c == '\t')
	;

#include <stdio.h>

/* atoi: convert s to integer; version 2 */
int atoi(char s[]){
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = n * 10 + (s[i] - '0');

	return sign * n;
}/*atoi*/

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n){
	int gap, i, j, temp;

	for(gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i-gap; j >= 0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}/*shellsort*/

#include <stdio.h>

/* reverse: reverse string s in place */
void reverse(char s[]){
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}/*reverse*/

//exercise 3.3

//3.6 loops - do-while

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0'
	reverse[s];
}/*itoa*/

//exercise 3.4
//exercise 3.5
//exercise 3.6

//3.7 break and continue
/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]){
	int n;
	for (n = strlen(s)-1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n+1] = '\0';
	return n;
}/*trim*/

//3.8 goto and labels


