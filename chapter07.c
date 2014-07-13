

//chapter7: input and output
//7.1 standard input and output
//7.2 formatted output - printf
//7.3 variable-length argument lists
//7.4 formatted input - scanf
//7.5 file access
//7.6 error handling - stderr and exit
//7.7 line input and output
//7.8 miscellanesous functions

//7.1 standard input and output
#include <stdio.h>
#include <ctype.h>

main()	/* lower: convert input to lower case */
{
	int c;
	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}
//7.2 formatted output - printf
#include <stdio.h>

main()	/* format = min-width.precision */
{
	char *s = "hello, world";

	printf(":%s:\n", s);
	printf(":%10s:\n", s);
	printf(":%.10s:\n", s);
	printf(":%-10s:\n", s);
	printf(":%.15s:\n", s);
	printf(":%-15s:\n", s);
	printf(":%15.10s:\n", s);
	printf(":%-15.10s:\n", s);

	return 0;
}
//7.3 variable-length argument lists
#include <stdarg.h>
/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
		va_list ap;

		char *p;
		char *sval;
		int ival;
		double dval;

		va_start(ap, fmt);
		for (p = fmt; *p; p++){
			if (*p != '%'){
				putchar(*p);
				continue;
			}
			switch(*++p){
				case 'd':
					ival = va_arg(ap, int);
					printf("%d", ival);
					break;
				case 'f':
					dval = va_arg(ap, double);
					printf("%f", dval);
					break;
				case 's':
					for (sval = va_arg(ap, char *); *sval; sval++)
						putchar(*sval);
					break;
				default:
					putchar(*p);
					break;
			}
		}

		va_end(ap);
}
//7.4 formatted input - scanf
#include <stdio.h>

main()
{
	double sum, v;
	sum = 0;
	while (scanf("%lf", &v) == 1)
		printf("\t%.2f\n", sum += v);
	return 0;
}

// fgets&sscanf
int main(){
	char s[0xff];
	char monthname[0xf];
	int day, month, year;

	while (fgets(s,sizeof(s),stdin) != NULL){
		if ( sscanf(s, "%d %s %d", &day, monthname, &year) == 3 )
			printf("valid: %s\n",s);
		else if (sscanf(s, "%d %d %d", &month, &day, &year) == 3 )
			printf("valid: %s\n",s);
		else
			printf("invalid: %s\n",s);
	}

return 0; }

//7.5 file access
#include <stdio.h>

/* cat: concatenate files, version 1 */
main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while(--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}
/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

//7.6 error handling - stderr and exit

#include <stdio.h>

/* cat: concatenate files, version 2 */
main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);
	char *prog = argv[0];	/* program name for errors */

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while(--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		if (ferror(stdout)) {
			fprintf(stderr, "%s: error writing stdout\n", prog);
			exit(2);
		}
	exit(0);
}

//7.7 line input and output

/* fgets: get at most n chars from iop */
char *fgets(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;
	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int fputs(char *s, FILE, *iop)
{
	int c;
	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}

/* getline: read a line, return length */
int getline(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}

//7.8 miscellanesous functions
