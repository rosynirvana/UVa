#include <iostream>
#include <ios>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

bool comp(std::pair<char, int> p1, std::pair<char, int> p2)
{
	if(p1.second > p2.second)
		return true;

	if(p1.first < p2.first)
		return true;

	return false;
}

int main()
{
	int n;
	std::cin >> n;
	std::cin.get();
	std::string input;
	int buf[26] = {0};
	std::vector< std::pair<char, int> > result;
	for(int i=0; i!=n; ++i){
		std::getline(std::cin, input);
		for(std::string::const_iterator iter=input.begin(); iter!=input.end();
			++iter){
			if(isalpha(*iter))
				++buf[toupper(*iter) - 'A'];
		}
	}
	for(int i=0; i!=26; ++i)
		if(buf[i] != 0)
			result.push_back( std::make_pair(static_cast<char>('A'+i), buf[i]));
	std::sort(result.begin(), result.end(), comp);

	for(size_t i=0; i!=result.size(); ++i)
		std::cout << result[i].first << " " << result[i].second << "\n";

	return 0;
}