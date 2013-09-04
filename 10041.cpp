#include <iostream>
#include <ios>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
	int n;
	std::cin >> n;
	std::cin.get();
	for(int i=0; i!=n; ++i){
		std::string input;
		std::getline(std::cin, input);
		std::stringstream buf(input);
		int temp;
		buf >> temp;
		std::vector<int> pool;
		while(buf >> temp)
			pool.push_back(temp);

		std::sort(pool.begin(), pool.end());
		int sum = 0;
		int median = pool[pool.size()/2];
		for(size_t i=0; i!=pool.size(); ++i)
			sum += abs(pool[i] - median);

		std::cout << sum << "\n";
	}
	return 0;
}