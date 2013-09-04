#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>

using std::map;
using std::bitset;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::getline;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i!=n; ++i){
		int person, tree;
		vector< bitset<100> > data;
		scanf("%d %d", &person, &tree);
		//cout << person << " " << tree <<"\n";
		getchar();
		for(int i=0; i != person; ++i)
			data.push_back( bitset<100>() );

		while(true){
			char buffer[81];
			if(fgets(buffer, 80, stdin) == 0)
				break;
			if(buffer[0] == '\n')
				break;
			string input(buffer);

			int first, second;
			size_t pos_blank = input.find(' ');

			string num1 = input.substr(0, pos_blank);
			string num2 = input.substr(pos_blank+1, input.size() - pos_blank - 1);
			first = atoi(num1.c_str());
			second = atoi(num2.c_str());

			//cout << first << " " << second << "\n";
			
			data[first-1][second-1] = 1;
			input.clear();
		}
		
		map<string, int> result;
		for(vector< bitset<100> >::const_iterator iter = data.begin(); iter != 
			data.begin() + person; ++iter){
			string temp = iter -> to_string();
			//cout << temp <<"\n"; 
			if(result.find(temp) == result.end())
				result[temp] = 1;
		}
		
		cout << result.size() << "\n";
		if(i != n-1)
			cout << "\n";
	}
	return 0;
}