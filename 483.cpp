#include <iostream>
#include <string>
#include <algorithm>
#include <ios>
#include <sstream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::string input;
	while(std::getline(std::cin, input) && input.size() != 0){
		std::stringstream buf(input);
		std::string str;
		buf >> str;
		while(buf){
			std::reverse(str.begin(), str.end());
			std::cout << str;
			if(buf >> str)
				std::cout << " ";
		}
		std::cout << "\n";
	}
	return 0;
}