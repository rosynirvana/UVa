#include <iostream>
#include <ios>

inline int f91(int);

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i;
	while(std::cin >> i && i != 0)
		std::cout << "f91(" << i << ") = " << f91(i) << "\n";
	return 0;
}

int f91(int N)
{
	if(N<=100)
		return 91;
	else
		return N-10;
}