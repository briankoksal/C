
#include <stdio.h>

int main(){

	int x = 1, y = 2, z[5] = {3,4,5,6,7};
	int *ip;

	ip = &x;
	printf("x = %d; y = %d; z[0] = %d; *ip = %d; ip = %d; [ip points to x]\n", x, y, z[0], *ip, (int)ip);

	y = *ip;
	printf("x = %d; y = %d; z[0] = %d; *ip = %d; ip = %d; [get *ip values]\n", x, y, z[0], *ip, (int)ip);

	*ip = 0;
	printf("x = %d; y = %d; z[0] = %d; *ip = %d; ip = %d; [put *ip values]\n", x, y, z[0], *ip, (int)ip);

	ip = &z[0];
	printf("x = %d; y = %d; z[0] = %d; *ip = %d; ip = %d; [ip points to z]\n", x, y, z[0], *ip, (int)ip);

return 0;}

