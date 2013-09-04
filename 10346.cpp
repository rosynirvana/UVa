#include <iostream>
#include <ios>

int main()
{
	int cig, rate;
	while(std::cin >> cig >> rate){
		int sum = cig;
		int butt = cig;
		while(butt >= rate){
			cig = butt / rate;
			sum += cig;
			butt %= rate;
			butt += cig;
		}
		std::cout << sum << "\n";
	}
	return 0;
}