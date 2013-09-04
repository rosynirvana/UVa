#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	int buf[50];
	int set = 1;
	std::cin >> n;
	while(n != 0){
		for(int i=0; i<n; ++i)
			std::cin >> buf[i];

		int sum = 0;
		for(int i=0; i<n; ++i)
			sum += buf[i];

		int avg = sum/n;
		int move = 0;
		for(int i=0; i<n; ++i)
			if(buf[i] > avg)
				move += (buf[i] - avg);

		std::cout << "Set #" << set << "\n";
		std::cout << "The minimum number of moves is " << move << ".\n\n";
		std::cin >> n;
		++set;
	}
	return 0;
}