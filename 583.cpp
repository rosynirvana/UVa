#include <iostream>
#include <vector>

using std::vector;

int main()
{
  char ary[47000] = {0, 0};
  vector<int>p_table;
  for(int i=2; i!=47000; ++i)
    ary[i] = i;
  while(true){
    int i;
    for(i=2; i!=47000; ++i)
      if(ary[i] != 0)
	break;
    if(i>217)
      break;
    p_table.push_back(i);
    ary[i] = 0;
    for(int j=i*i; j<=47000; j+=i)
      ary[j] = 0;
  }
  for(int i=2; i!=47000; ++i)
    if(ary[i])
      p_table.push_back(i);

  int x;
  while(std::cin >> x && x != 0){
    if(x < 0){
      std::cout << x << " = " << -1 << " x ";
      x *= -1;
    }
    else
      std::cout << x << " = ";
    vector<int> result;
    for(vector<int>::const_iterator iter = p_table.begin();
	iter != p_table.end() && x>1; ++iter){
      while(x % *iter == 0){
	result.push_back(*iter);
	x /= *iter;
      }
    }
  
    if(x > 1)
      result.push_back(x);

    for(size_t i=0; i != result.size()-1; ++i)
      std::cout << result[i] << " x ";
    std::cout << result[result.size()-1] << "\n";
  }
  return 0;
}
	
