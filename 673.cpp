#include <stack>
#include <iostream>
#include <ios>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::string input;
	int n;
	std::cin >> n;
	std::cin.get();
	for(int i=0; i<n; ++i){
		std::getline(std::cin, input);
		//std::cout << input << "\n";
		bool match = true;
		if(input.size() != 0){
			std::stack<char> buf;
			for(std::string::const_iterator iter = input.begin(); 
				iter != input.end(); ++iter){
				if(*iter == '(' || *iter == '[')
					buf.push(*iter);
				else if(*iter == ')'){
					if(!buf.empty() && buf.top() == '(')
						buf.pop();
					else{
						match = false;
						break;
					}
				}
				else if(*iter == ']'){
					if(!buf.empty() && buf.top() == '[')
						buf.pop();
					else{
						match = false;
						break;
					}
				}
			}
			if(!buf.empty())
				match = false;
		}
		if(match)
			std::cout << "Yes\n";
		else
			std::cout << "No\n";
	}
	return 0;
}