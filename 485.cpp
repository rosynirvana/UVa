#include <iostream>
#include <ios>
#include <vector>

char* plus_one(char*);
void plus(char*, char*);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::vector<char*> base;
	std::vector<char*> next;
	std::cout << "1\n1 1\n";
	for(int i=3; ; ++i){
		std::cout << "1 ";
		std::cout << plus_one(base[0]);
	}
}