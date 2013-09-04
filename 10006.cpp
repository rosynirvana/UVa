#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using std::binary_search;
using std::vector;

bool isprime(int);
int cal(int, int);

vector<int>p_table;
int bin[20];
int pos;

int main()
{
  std::ios_base::sync_with_stdio(false);
  
  int buf[65001] = {0, 0};
  for(int i=2; i!=65001; ++i)
    buf[i] = i;
  while(true){
    int i = 0;
    for(i=2; i!=65001; ++i)
      if(buf[i] != 0)
	break;
    if(i > 300)
      break;
    p_table.push_back(i);
    for(int j=i; j<65001; j+=i)
      buf[j] = 0;
  }
  for(int i=2; i!=65001; ++i)
    if(buf[i] != 0)
      p_table.push_back(i);

  int i;
  while(std::cin >> i && i != 0){
    if(isprime(i)){
      std::cout << i << " is normal.\n";
      continue;
    }
    int temp = i;
    pos = 0;
    while(temp > 0){
      bin[pos++] = temp & 1;
      temp /= 2;
    }

    bool carmichael = true;
    for(int j=2; j!=i; ++j)
      if(cal(j, i) != j){
	carmichael = false;
	break;
      }

    if(carmichael)
      std::cout << "The number " << i << " is a Carmichael number.\n";
    else
      std::cout << i << " is normal.\n";
  }
  return 0;
}

bool isprime(int i)
{
  if(binary_search(p_table.begin(), p_table.end(), i))
     return true;
  return false;
}

int cal(int a, int n)
{
  unsigned long long int product = 1;
  for(int i=pos-1; i>=0; --i)
    if(bin[i] == 1)
      product = product * product * a % n;
    else
      product = product * product % n;

  return product;
}
