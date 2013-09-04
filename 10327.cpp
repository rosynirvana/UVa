#include <iostream>
#include <ios>
#include <utility>

int main()
{
	int n;
	int ary[1000];
	while(std::cin >> n){
		for(int i=0; i!=n; ++i)
			std::cin >> ary[i];

		int swap = 0;
		int last_loop_swap = -1;
		for(int i=0; i!=n-1; ++i){
			if(last_loop_swap == 0)
				break;
			int current_swap = 0;
			for(int j=0; j!=n-1-i;++j)
				if(ary[j] > ary[j+1]){
					std::swap(ary[j], ary[j+1]);
					++current_swap;
				}
			last_loop_swap = current_swap;
			swap +=last_loop_swap;
		}

		std::cout << "Minimum exchange operations : " << swap << "\n";
	}
	return 0;
}