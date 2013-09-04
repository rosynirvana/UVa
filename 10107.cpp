#include <iostream>
#include <ios>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i;
	std::vector<int> buf;
	while(std::cin >> i){
		std::vector<int>::iterator iter;
		for(iter = buf.begin(); iter != buf.end(); ++iter)
			if(*iter > i)
				break;

		if(iter == buf.end())
			buf.push_back(i);
		else
			buf.insert(iter, i);

		int length = buf.size();
		if(length % 2 == 1)
			std::cout << buf[length/2] << "\n";
		else
			std::cout << (buf[length/2-1] + buf[length/2])/2 << "\n";
	}
	return 0;
}