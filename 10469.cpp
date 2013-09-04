#include <iostream>
#include <ios>
#include <algorithm>

std::string toBin(unsigned int);
std::string no_carry_plus(const std::string&, const std::string&);
unsigned int toDec(const std::string&);

int main()
{
	std::ios_base::sync_with_stdio(false);
	unsigned int a, b;
	while(std::cin >> a >> b){
		std::string a_s = toBin(a);
		std::string b_s = toBin(b);
		//std::cout << a_s << " " << b_s << "\n";
		std::string c_s = no_carry_plus(a_s, b_s);
		//std::cout << c_s << "\n";
		std::cout << toDec(c_s) << "\n";
	}
	return 0;
}

std::string toBin(unsigned int a)
{
	//std::cout << "toBin" << "\n";
	char buf[40];
	int pos = 0;
	while(a > 0){
		buf[pos++] = (a % 2 + '0');
		a /= 2;
	}
	buf[pos] = '\0';
	std::string result(buf);
	std::reverse(result.begin(), result.end());
	return result;
}

std::string no_carry_plus(const std::string& a, const std::string& b)
{
	//std::cout << "plus" << "\n";
	std::string result;
	int i, j;
	for(i = a.size()-1, j = b.size() -1; i >= 0 && j >= 0; --i, --j){
		if(a[i] == b[j])
			result.push_back('0');
		else
			result.push_back('1');
	}
	//std::cout << i << " " << j <<"\n";
	for(; i>=0; --i)
		result.push_back(a[i]);
	for(; j>=0; --j)
		result.push_back(b[j]);

	std::reverse(result.begin(), result.end());
	return result;
}

unsigned int toDec(const std::string& a)
{
	//std::cout << "toDec" << "\n";
	unsigned int base = 1;
	unsigned int result = 0;
	for(int i = a.size()-1; i >= 0; --i, base *= 2)
		result += (base * (a[i] - '0'));

	return result;
}