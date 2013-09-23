#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
bool is_pre(const string&, const string&);

int main()
{
  int case_num;
  std::cin >> case_num;
  while(case_num--){
    int data_size;
    std::cin >> data_size;
    vector<string> data;
    for(int i=0; i!=data_size; ++i){
      string input;
      std::cin >> input;
      data.push_back(input);
    }
    std::sort(data.begin(), data.end());
    int no_pre = true;
    for(size_t i=0; i!=data.size()-1; ++i)
      if(is_pre(data[i], data[i+1])){
	no_pre = false;
	break;
      }
    if(no_pre)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }
  return 0;
}

bool is_pre(const string& s1, const string& s2)
{
  if(s1.size() > s2.size())
    return false;

  for(size_t i=0; i!=s1.size(); ++i)
    if(s1[i] != s2[i])
      return false;
  return true;
}
      
