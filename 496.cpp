#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using std::sort;
using std::binary_search;
using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::vector;

void fetchNumber(string, vector<int>&);

int main()
{
	string input;
	while(getline(cin, input)){
		if(input.size() == 0)
			break;
		string input2;
		getline(cin,input2);

		vector<int> s1, s2;
		fetchNumber(input, s1);
		fetchNumber(input2, s2);

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		unsigned int found = 0, not_found = 0;
		vector<int>::iterator iterLbegin, iterLend, iterS, iterSEnd;
		if(s1.size() >= s2.size()){
			iterLbegin = s1.begin();
			iterLend = s1.end();
			iterS = s2.begin();
			iterSEnd = s2.end();
		}
		else{
			iterLbegin = s2.begin();
			iterLend = s2.end();
			iterS = s1.begin();
			iterSEnd = s1.end();
		}

		while(iterS != iterSEnd){
			//std::cout << *iterS << "; " ;
			if(binary_search(iterLbegin, iterLend, *iterS))
				++found;
			else
				++not_found;
			if(found >= 1 && not_found >= 1)
				break;
			++iterS;
		}
		//std::cout << found << " " << not_found << std::endl;
		enum resultType{aIsProperOfb, bIsProperOfa, equal, disjoint, confused};
		resultType result;

		if(s1.size() == s2.size() && found == s1.size())
			result = equal;
		else if(s1.size() > s2.size() && not_found == 0)
			result = bIsProperOfa;
		else if(s1.size() < s2.size() && not_found == 0)
			result = aIsProperOfb;
		else if(not_found != 0 && found != 0)
			result = confused;
		else
			result = disjoint;

		switch(result){
			case aIsProperOfb:
			cout << "A is a proper subset of B\n";
			break;
			case bIsProperOfa:
			cout << "B is a proper subset of A\n";
			break;
			case equal:
			cout << "A equals B\n";
			break;
			case disjoint:
			cout << "A and B are disjoint\n";
			break;
			case confused:
			cout << "I'm confused!\n";
		}

		input.clear();
	}
	return 0;
}

void fetchNumber(string input, vector<int>& buf)
{
	string::const_iterator left = input.begin(), right = input.begin();
	for(; right != input.end(); ++right){
		if(isspace(*right)){
			int temp;
			string tempstr = input.substr(left-input.begin(), right-left);
			temp = atoi(tempstr.c_str());
			buf.push_back(temp);
			left = right;
		}	
	}
	int temp;
	string tempstr = input.substr(left-input.begin(), right-left);
	temp = atoi(tempstr.c_str());
	buf.push_back(temp);
/*
	for(vector<int>::const_iterator iter = buf.begin(); iter != buf.end(); ++iter)
		std::cout << *iter << " ";

	std::cout << std::endl;
	*/
}