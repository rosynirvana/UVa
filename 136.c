#include <stdio.h>
#include <stdbool.h>

bool isUglyNum(int);
int ugly[1500] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15};
int pos = 11;

int main()
{
	int i;
	for(i=16;; ++i){
		if(isUglyNum(i))
			ugly[pos++] = i;

		if(pos == 1501)
			break;
	}

	printf("The 1500'th ugly number is %d\n", i);
	return 0;
}

bool isUglyNum(int n)
{
	int i = pos - 1;

	for(int run = 0; i>=0 && run <= 20; --i, ++run)
		if(n % ugly[i] == 0)
			n /= ugly[i];
	
	while(n % 2 == 0)
		n /= 2;

	while(n % 3 == 0)
		n /= 3;

	while(n % 5 == 0)
		n /= 5;

	if(n == 1)
		return true;

	return false;
}