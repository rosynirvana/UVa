#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int n;
	scanf("%u", &n);
	while(n != 0){
		unsigned int temp = (unsigned int)(sqrt(n));
		if(temp * temp == n)
			puts("yes");
		else
			puts("no");
		scanf("%u", &n);
	}
	return 0;
}