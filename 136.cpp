#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main()
{
	int i, j, k;
	std::vector<long long int> buf;

	for(i = 0; i <= 35; ++ i)
		for(j = 0; j <= 25; ++j)
			for(k = 0; k <= 15; ++k){
				long long int temp = static_cast<long long int>(pow(2, i) * pow(3, j) * pow(5, k));
				if(temp > 0)
					buf.push_back(temp);
			}

	std::sort(buf.begin(), buf.end());

	std::cout << "The 1500'th ugly number is " << buf[1499] << ".\n";

	return 0;
}
