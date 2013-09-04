#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;
using std::string;

bool comp(pair<string, int> a, pair<string, int> b)
{
  return a.second < b.second;
}

int main()
{
  int n;
  std::cin >> n;
  for(int i=0; i!=n; ++i){
    if(i!=0)
      std::cout << "\n";

    int length, count;
    vector< pair<string, int> > result;
    std::cin >> length >> count;
    for(int j=0; j!=count; ++j){
      string input;
      std::cin >> input;
      int reverse = 0;
      for(string::const_iterator iter = input.begin();
	  iter != input.end(); ++iter)
	for(string::const_iterator iiter = iter;
	    iiter != input.end(); ++iiter)
	  if(*iiter < *iter)
	    ++reverse;
      result.push_back(std::make_pair(input, reverse));
    }
    std::stable_sort(result.begin(), result.end(), comp);
    /* stable_sort or WA */
    
    for(size_t i=0; i!=result.size(); ++i)
      std::cout << result[i].first << "\n";
  }
  return 0;
}
