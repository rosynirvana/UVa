#include <iostream>
#include <vector>
#include <algorithm>

using std::binary_search;
using std::vector;

int main()
{
  char ary[1000001] = {0, 0};
  vector<int>p_table;
  for(int i=2; i!=1000001; ++i)
    ary[i] = i;
  while(true){
    int i;
    for(i=2; i!=1000001; ++i)
      if(ary[i] != 0)
	break;
    if(i>1000)
      break;
    p_table.push_back(i);
    ary[i] = 0;
    for(int j=i*i; j<=1000001; j+=i)
      ary[j] = 0;
  }
  for(int i=2; i!=1000001; ++i)
    if(ary[i])
      p_table.push_back(i);

  int x;
  while(std::cin >> x && x!=0){
    for(size_t i=1; i!=p_table.size(); ++i)
      if(binary_search(p_table.begin(), p_table.end(), x-p_table[i])){
	std::cout << x << " = " << p_table[i] << " + " << x-p_table[i] << "\n";
	break;
      }
  }
  return 0;
}
	
