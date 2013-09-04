#include <stdio.h>
#include <string.h>
#include <limits.h>

char getDigit(int num);

int main()
{
	int i;
	while(scanf("%d", &i) == 1){

		printf("%c\n", getDigit(i));
	}

	return 0;
}

char getDigit(int num)
{
	char buf[15];
	int main_num;

	if(num <= 9)
		return num+'0';

	if(num <= 189){
		num -= 10;
		main_num = num / 2 + 10;
		sprintf(buf, "%d", main_num);
		return buf[num % 2];
	}

	if(num <= 2889){
		num -= 190;
		main_num = num / 3 + 100;
		sprintf(buf, "%d", main_num);
		return buf[num % 3];
	}

	if(num <= 38889){
		num -= 2890;
		main_num = num / 4 + 1000;
		sprintf(buf, "%d", main_num);
		return buf[num % 4];
	}

	if(num <= 488889){
		num -= 38890;
		main_num = num / 5 + 10000;
		sprintf(buf, "%d", main_num);
		return buf[num % 5];
	}

	if(num <= 5888889){
		num -= 488890;
		main_num = num / 6 + 100000;
		sprintf(buf, "%d", main_num);
		return buf[num % 6];
	}

	if(num <= 68888889){
		num -= 5888890;
		main_num = num / 7 + 1000000;
		sprintf(buf, "%d", main_num);
		return buf[num % 7];
	}

	if(num <= 788888889){
		num -= 68888890;
		main_num = num / 8 + 10000000;
		sprintf(buf, "%d", main_num);
		return buf[num % 8];
	}

	if(num <= INT_MAX){
		num -= 788888890;
		main_num = num / 9 + 100000000;
		sprintf(buf, "%d", main_num);
		return buf[num % 9];
	}
	return -1;
}