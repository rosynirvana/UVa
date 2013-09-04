#include <iostream>
#include <string>
#include <cstring>

int main()
{
	std::string input;
	int ary[52] = {0};
	while(std::getline(std::cin, input) && input.size() != 0){
		memset(ary, 0 , sizeof(ary));
		for(std::string::iterator iter = input.begin(); 
			iter != input.end(); ++iter)
			if(isupper(*iter))
				ary[*iter - 'A'] += 1;
			else if(islower(*iter))
				ary[*iter - 'a' + 26] += 1;

		int max = -1;
		for(int i=0; i!=52; ++i)
			if(ary[i] > max)
				max = ary[i];
		for(int i=0; i!=52; ++i)
			if(ary[i] == max)
				std::cout << (i>25 ? static_cast<char>('a'+i-26) : static_cast<char>('A'+i));
		std::cout << " " << max << "\n";
	}
	return 0;
}