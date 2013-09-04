#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int sum(string&, vector<int>&);
bool check(int, int, string);

int main()
{
	int n;
	cin >> n;
	for(int i=0; i != n; ++i){
		vector<int> buf;
		for(int i=0; i !=12; ++i)
			buf.push_back(1);
		vector<string> obj;
		string temp;
		for(int i=0; i<9; ++i){
			cin >> temp;
			obj.push_back(temp);
		}
		for(vector<int>::iterator iter = buf.begin(); iter != buf.end();
			++iter){
			*iter = 0;
			if(check(sum(obj[0], buf), sum(obj[1], buf), obj[2])&&
			check(sum(obj[3], buf), sum(obj[4], buf), obj[5])&&
			check(sum(obj[6], buf), sum(obj[7], buf), obj[8]))
				break;
			
			*iter = 2;
			if(check(sum(obj[0], buf), sum(obj[1], buf), obj[2])&&
			check(sum(obj[3], buf), sum(obj[4], buf), obj[5])&&
			check(sum(obj[6], buf), sum(obj[7], buf), obj[8]))
				break;
			*iter = 1;
		}
		for(vector<int>::const_iterator iter = buf.begin(); iter != buf.end();
			++iter){
			//cout << *iter << " ";
			if(*iter == 2)
				cout << static_cast<char>('A' + (iter - buf.begin())) << " is the counterfeit coin and it is heavy.\n";
			else if(*iter == 0) 
				cout << static_cast<char>('A' + (iter - buf.begin())) << " is the counterfeit coin and it is light.\n";
		}
	}
	return 0;
}

int sum(string& obj, vector<int>& buf)
{
	int s = 0;
	for(string::const_iterator iter = obj.begin(); iter != obj.end();
		++iter){
		s += buf[*iter - 'A'];
	}
	return s;
}

bool check(int a, int b, string balance)
{
	if(balance.compare("even") == 0 && a == b)
		return true;

	if(balance.compare("up") == 0 && a > b)
		return true;

	if(balance.compare("down") == 0 && a < b)
		return true;

	return false;
}