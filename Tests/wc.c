#include <stdio.h>

#define IN 1
#define OUT 2

main()
{
	int c;
	int nl, nw, nc;
	int state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n') nl++;
		if (c == '\t' || c == '\n' || c == ' ')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			nw++;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}

