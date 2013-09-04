#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
  int ary[1001] = {0, 0};
  for(int i=2; i!=1001; ++i)
    ary[i] = i;
  vector<int> p_table;
  p_table.push_back(1);
  while(true){
    int i;
    for(i=2; i!=1001; ++i)
      if(ary[i] != 0)
	break;
    if(i > 34)
      break;
    p_table.push_back(i);
    ary[i] = 0;
    for(int j=i*i; j<=1001; j+=i)
      ary[j] = 0;
  }
  for(int i=2; i!=1001; ++i)
    if(ary[i])
      p_table.push_back(i);
  /*
  for(size_t i=0; i!=p_table.size(); ++i)
    std::cout << p_table[i] << " ";
  std::cout << "\n";
  */
  int a, b;
  while(std::cin >> a >> b){
    vector<int>::iterator iter;
    iter = std::lower_bound(p_table.begin(), p_table.end(), a);
    if(*iter != a)
      --iter;
    int count = iter - p_table.begin();
    int start, end;
    //    std::cout << *iter << "\n";
    if((count+1) % 2 == 0){
      start = count/2-b+1;
      end = count/2+b;
    }
    else{
      start = count/2-b+1;
      end = count/2+b-1;
    }
    
    if(start < 0)
      start = 0;
    if(end >= p_table.size())
      end = p_table.size() - 1;
    
    //std::cout << "end is " << end << "\n";

    std::cout << a << " " << b << ": ";
    vector<int> result;
    for(; p_table[start]<=a && start <= end; ++start)
      result.push_back(p_table[start]);
    for(size_t i=0; i!=result.size(); ++i){
      std::cout << result[i];
      if(i != result.size()-1)
	std::cout << " ";
    }
    std::cout << "\n\n";
  }
  return 0;
}
