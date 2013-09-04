#include <iostream>
#include <ios>
#include <utility>

int bubbleSort(int *, int);

int main()
{
	std::ios_base::sync_with_stdio(false);
	int c;
	std::cin >> c;
	for(int i=0; i!=c; ++i){
		int l;
		std::cin >> l;
		if(l != 0){
			int* buf = new int[l];
			for(int j=0; j!=l; ++j)
				std::cin >> buf[j];

			int swap = bubbleSort(buf, l);
			std::cout << "Optimal train swapping takes " << swap <<" swaps.\n";
			delete[] buf;
		}
		else
			std::cout << "Optimal train swapping takes 0 swaps.\n";
	}
	return 0;
}

int bubbleSort(int *buf, int length)
{
	int swap = 0;
	for(int i=0; i != length-1; ++i)
		for(int j=0; j <= length-2-i; ++j){
			if(buf[j] > buf[j+1]){
				std::swap(buf[j], buf[j+1]);
				++swap;
			}
		}

	return swap;
}