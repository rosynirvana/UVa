#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	long long a, b;
	while(std::cin >> a >> b){
		if(a==b && b==0)
			break;

		int carryNum = 0;
		int carry = 0;

		while(a>0 && b>0){
			int m, n;
			m = a%10;
			n = b%10;
			if(m+n+carry>=10){
				carry = 1;
				++carryNum;
			}
			else
				carry = 0;

			a /= 10;
			b /= 10;
		}

		long long int c;
		if(a > 0)
			c = a;
		else
			c = b;

		while(c > 0){
			int m;
			m = c % 10;
			if(m + carry >= 10){
				carry = 1;
				++carryNum;
			}
			else
				carry = 0;
			c /= 10;
		}

		if(carryNum == 0)
			std::cout << "No carry operation.\n";
		else if(carryNum == 1)
			std::cout << "1 carry operation.\n";
		else
			std::cout << carryNum << " carry operations.\n";
	}
	return 0;
}