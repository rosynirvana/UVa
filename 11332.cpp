#include <iostream>
#include <ios>
#include <string>
#include <cstdio>

using std::string;
using std::cin;
using std::cout;

string sum(const string&);

int main()
{
  std::ios_base::sync_with_stdio(false);
  string input;
  while(cin >> input){
    if(input.compare("0") == 0)
      break;

    std::cout << sum(input) << "\n";
  }
  return 0;
}

string sum(const string& input)
{
  if(input.size() == 1)
    return input;

  int temp = 0;
  for(string::const_iterator iter = input.begin();
      iter != input.end(); ++iter)
    temp += (*iter - '0');

  while(temp >= 10)
    temp = temp / 10 + temp % 10;

  char buf[2];
  sprintf(buf, "%d", temp);
  return buf;
}
