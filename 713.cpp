#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using std::string;

string revplus(string&, string&);

int main()
{
  int n;
  std::cin >> n;
  for(int i=0; i!=n; ++i){
    string a, b;
    std::cin >> a >> b;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    string c = revplus(a, b);
    std::cout << c << "\n";
  }
  return 0;
}

string revplus(string& a, string& b)
{

  string c;
  int carry = 0;
  int i = a.size()-1, j = b.size() - 1;
  for(; i>=0 && j>=0; --i, --j){
    int temp = a[i] - '0' + b[j] - '0' + carry;
    if(temp >= 10){
      c.push_back(temp - 10 + '0');
      carry = 1;
    }
    else{
      c.push_back(temp + '0');
      carry = 0;
    }
  }

  for(; i>=0; --i){
    int temp = a[i] - '0' + carry;
    if(temp >= 10){
      c.push_back(temp - 10 + '0');
      carry = 1;
    }
    else{
      c.push_back(temp + '0');
      carry = 0;
    }
  }
    for(; j>=0; --j){
      int temp = b[j] - '0' + carry;
      if(temp >= 10){
	c.push_back(temp - 10 + '0');
	carry = 1;
      }
      else{
	c.push_back(temp + '0');
	carry = 0;
      }
    }
    if(carry == 1)
      c.push_back('1');

    int pos = -1;
    for(string::const_iterator iter = c.begin();
	iter != c.end(); ++iter)
      if(*iter != '0'){
	pos = iter - c.begin();
	break;
      }
    
    if(pos == -1)
      return "0";
    return c.substr(pos);
}
