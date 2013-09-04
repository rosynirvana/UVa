#include <iostream>
#include <ios>
#include <cstdlib>
#include <bitset>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int buf[3000];
	int n;
	while(std::cin >> n){
		std::bitset<3000> pool;
		for(int i=0; i!=n; ++i)
			std::cin >> buf[i];

		for(int i=0; i!=n-1; ++i){
			int temp = abs(buf[i] - buf[i+1]);
			//std::cout << temp << "\n";
			if(temp <= 0 || temp > n-1)
				break;
			else
				pool[temp-1] = 1;
		}
		//std::cout << pool.to_string();
		if(pool.count() == n-1)
			std::cout << "Jolly\n";
		else
			std::cout << "Not jolly\n";

	}
	return 0;
}