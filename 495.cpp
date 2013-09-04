#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

std::string plus(std::string& a, std::string& b);

int main()
{
	std::ios_base::sync_with_stdio(false);
	long long small[93] = {0, 1};
	for(int i=2; i<=92; ++i)
		small[i] = small[i-1] + small[i-2];

	std::string big[4908];
	big[0] = "12200160415121876738";
	big[1] = "19740274219868223167";
	for(int i=2; i<4908; ++i)
		big[i] = plus(big[i-1], big[i-2]);

	int x;
	while(std::cin >> x){
		if(x <= 92)
			std::cout << "The Fibonacci number for " << x << " is " 
			<< small[x] << "\n";
		else
			std::cout << "The Fibonacci number for " << x << " is " 
			<< big[x-93] << "\n";
	}
	return 0;
}

std::string plus(std::string& a, std::string& b)
{
	int i, j;
	int carry = 0;
	std::string c;
	for(i = a.size()-1, j = b.size()-1; i>=0 && j>=0; --i, --j){
		int temp = (a[i]-'0') + (b[j]-'0') + carry;
		if(temp >= 10){
			carry = 1;
			c.push_back(temp-10+'0');
		}
		else{
			carry = 0;
			c.push_back(temp+'0');
		}
	}
	for(; i>=0; --i){
		int temp = (a[i]-'0') + carry;
		if(temp >= 10){
			carry = 1;
			c.push_back(temp-10+'0');
		}
		else{
			carry = 0;
			c.push_back(temp+'0');
		}
	}
	for(; j>=0; --j){
		int temp = (b[j]-'0') + carry;
		if(temp >= 10){
			carry = 1;
			c.push_back(temp-10+'0');
		}
		else{
			carry = 0;
			c.push_back(temp+'0');
		}
	}
	if(carry == 1)
		c.push_back('1');
	std::reverse(c.begin(), c.end());
	return c;
}