#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

int main()
{
	std::string input;
	while(std::cin >> input && (input.compare("#") != 0)){
		int right = -1, left = -1;
		for(size_t i=0; i!=input.size()-1; ++i)
			if(input[i] < input[i+1]){
				left = i;
			}
		//std::cout << input[left];
		if(left != -1){
			int temp = 256;
			for(int i=left + 1; i != input.size(); ++i)
				if(input[i] > input[left] && input[i] < temp){
					right = i;
					temp = input[i];
				}
			//std::cout << "\n" << input[right];
			std::swap(input[left], input[right]);

			std::string::iterator b = input.begin()+left+1;
			std::sort(b, input.end());
			
			std::cout << input << "\n";
		}
		else
			std::cout << "No Successor\n";
	}
	return 0;
}