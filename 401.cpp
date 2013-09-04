#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

static bool mirrorC(char, char);
bool is_mirror(const std::string&);
bool is_parlindrome(const std::string&);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::string input;
	while(std::cin >> input){
		bool is_par, is_mir;
		is_par = is_parlindrome(input);
		is_mir = is_mirror(input);
		if(is_par && is_mir)
			std::cout << input << " -- is a mirrored palindrome.\n";
		else if(is_par)
			std::cout << input << " -- is a regular palindrome.\n";
		else if(is_mir)
			std::cout << input << " -- is a mirrored string.\n";
		else
			std::cout << input << " -- is not a palindrome.\n";
		std::cout << "\n";
	}
	return 0;
}

bool mirrorC(char a, char b)
{
	if(a == 'A' && b == 'A')
		return true;
	if((a == 'E' && b == '3') || (a == '3' && b == 'E'))
		return true;
	if(a == 'H' && b == 'H')
		return true;
	if(a == 'I' && b == 'I')
		return true;
	if((a == 'J' && b == 'L') || (a == 'L' && b == 'J'))
		return true;
	if(a == 'M' && b == 'M')
		return true;
	if(a == 'O' && b == 'O')
		return true;
	if((a == 'S' && b == '2') || (a == '2' && b == 'S'))
		return true;
	if((a == 'T' || a == 'U' || a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == '1' || a == '8') && b == a)
		return true;
	if((a == 'Z' && b == '5') || (a == '5' && b == 'Z'))
		return true;

	return false;
}

bool is_mirror(const std::string& a)
{
	std::string b(a);
	std::reverse(b.begin(), b.end());
	for(size_t i = 0; i != a.size(); ++i)
		if(!mirrorC(a[i], b[i]))
			return false;
	return true;
}

bool is_parlindrome(const std::string& a)
{
	std::string b(a);
	std::reverse(b.begin(), b.end());
	if(a.compare(b) != 0)
		return false;

	return true;
}