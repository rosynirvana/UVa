#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for(int i=0; i!=n; ++i){
		int f;
		std::cin >> f;
		int sum = 0;
		for(int j=0; j!=f; ++j){
			int a, b, c;
			std::cin >> a >> b >> c;
			sum += a*c;
		}
		std::cout << sum << "\n";
	}
	return 0;
}