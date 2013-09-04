#include <iostream>
#include <string>
#include <ios>
#include <algorithm>

std::string times(std::string& a, int num);

int main()
{
	long long small[20] = {1};
	for(int i=1; i < 20; ++i)
		small[i] = small[i-1] * (i+1);

	std::string big[980];
	big[0] = "2432902008176640000";
	for(int i=1; i < 980; ++i)
		big[i] = times(big[i-1], i+21);

	int x;
	while(std::cin >> x){
		if(x <= 20)
			std::cout << x << "!\n" << small[x-1];
		else
			std::cout << x << "!\n" << big[x-21];
	}

	return 0;
}