#include <iostream>
#include <map>
#include <string>
#include <ios>

using std::string;
using std::map;
using std::cout;
using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  cin.get();
  map<string, int> result;
  string input;
  for(int i=0; i!=n; ++i){
    cin >> input;
    map<string, int>::iterator iter = result.find(input);
    if(iter == result.end())
      result[input] = 1;
    else
      (iter -> second) +=1;
    std::getline(cin, input);
  }

  for(map<string, int>::iterator iter = result.begin(); iter!=result.end();
      ++iter)
    std::cout << iter->first << " " << iter->second << "\n";
  return 0;
}
