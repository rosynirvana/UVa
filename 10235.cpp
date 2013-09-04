#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

inline bool is_prime(int x, vector<int>& p_table);
inline int rev(int x);

int main()
{
  int buf[1001] = {0,0};
  vector<int> p_table;
  for(int i=2; i!=1001; ++i)
    buf[i] = i;
  while(true){
    int i;
    for(i=2; i!=1001; ++i)
      if(buf[i] != 0)
	break;
    if(i > 35)
      break;
    p_table.push_back(i);
    for(int j=i; j<1001; j+=i)
      buf[j] = 0;
  }
  for(int i=2; i!=1001; ++i)
    if(buf[i]!=0)
      p_table.push_back(i);

  int x;
  while(std::cin >> x){
    if(!is_prime(x, p_table))
      std::cout << x << " is not prime.\n";
    else{
      int y = rev(x);
      if(x == y || !is_prime(y, p_table))
	std::cout << x << " is prime.\n";
      else
	std::cout << x << " is emirp.\n";
    }
  }
  return 0;
}

bool is_prime(int x, vector<int>& p_table)
{
  if(x == 1)
    return false;

  int upper = sqrt(x);
  for(vector<int>::const_iterator iter = p_table.begin();
      iter != p_table.end() && *iter <= upper; ++iter)
    if(x % *iter == 0)
      return false;
  return true;
}

int rev(int x)
{
  int product = 0;
  while(x > 0){
    product = product * 10 + x % 10;
    x /= 10;
  }

  return product;
}
