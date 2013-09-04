#include <iostream>
#include <ios>
#include <cstdio>
#include <cstring>

long long int revNum(long long int);
inline bool isParlindrome(long long int);

int main()
{
	//std::cout << revNum(1234);
	std::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	for(int i=0; i!=N; ++i){
		long long a;
		std::cin >> a;
		int round = 1;
		a += revNum(a);
		while(!isParlindrome(a)){
			//std::cout << a;
			a += revNum(a);
			round += 1;
		}
		std::cout << round << " " << a << "\n";
	}
	return 0;
}

long long int revNum(long long int a)
{
	char buf[22];
	sprintf(buf, "%lld", a);
	//std::cout << buf;
	int length = strlen(buf);
	long long int result = 0;
	for(int i = length-1; i>=0; --i)
		result = result * 10 + static_cast<int>(buf[i] - '0');
	return result;
}

bool isParlindrome(long long int a)
{
	return a == revNum(a);
}