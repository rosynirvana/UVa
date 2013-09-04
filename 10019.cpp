#include <iostream>
#include <ios>

inline int count_one_in_hex(int);

int main()
{
	int n;
	std::cin >> n;
	for(int i=0; i!=n; ++i){
		int x;
		std::cin >> x;

		int temp = x;
		int b1 = 0;
		while(x > 0){
			b1 += x % 2;
			x /= 2;
		}

		int b2 = 0;
		x = temp;
		while(x > 0){
			b2 += count_one_in_hex(x % 10);
			x /= 10;
		}

		std::cout << b1 << " " << b2 << "\n";
	}
	return 0;
}

int count_one_in_hex(int x)
{
	if(x == 1 || x == 2 || x == 4 || x == 8)
		return 1;
	if(x == 3 || x == 5 || x == 9 || x == 6)
		return 2;
	return 3;
}