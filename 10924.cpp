#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

bool isPrime(int num, vector<int>&);
int sumWord(const string&);

int main()
{
  int buf[5201];
  for(int i=0; i!=5201; ++i)
    buf[i] = i;
  buf[0] = 0;
  buf[1] = 0;
  vector<int> p_table;
  while(true){
    int i;
    for(i=2; i!=5201; ++i)
      if(buf[i] != 0)
	break;
    if(i >= 73)
      break;
    p_table.push_back(i);
    for(int j=i; j < 5201; j += i)
      buf[j] = 0;
  }

  for(int i=50; i != 5021; ++i)
    if(buf[i] != 0)
      p_table.push_back(i);

  string input;
  while(std::cin >> input){
    int i = sumWord(input);
    if(isPrime(i, p_table))
      std::cout << "It is a prime word.\n";
    else
      std::cout << "It is not a prime word.\n";
  }
  return 0;
}

bool isPrime(int i, vector<int>& p_table)
{
  if(i == 1)
    return true;
  if(i <= 5200)
    return std::binary_search(p_table.begin(), p_table.end(), i);

  for(int t=2; t*t <= i; ++t)
    if(i % t == 0)
      return false;
  return true;
}

int sumWord(const string& input)
{
  int sum = 0;
  for(string::const_iterator iter = input.begin();
      iter != input.end(); ++iter){
    if(isupper(*iter))
      sum += static_cast<int>(*iter - 'A' + 27);
    else
      sum += static_cast<int>(*iter - 'a' + 1);
  }
  return sum;
}
