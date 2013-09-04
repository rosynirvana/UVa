#include <iostream>
#include <ios>
#include <cmath>

int main()
{
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  for(int i=0; i!=n; ++i){
    int l, h;
    std::cin >> l >> h;
    int max = 0, num = 0;
    for(int j=l; j <= h; ++j){
      int current = 2;
      int sqr = sqrt(j);
      if(sqr * sqr == j)
	current += 1;
      for(int k=2; k*k < j; ++k)
	if(j % k == 0)
	  current += 2;
      if(current > max){
	max = current;
	num = j;
      }
    }
    if(l == h && l == 1){
      num = 1;
      max = 1;
    }
    std::cout << "Between " << l << " and " << h << ", " << num
	      << " has a maximum of " << max << " divisors.\n";
  }
  return 0;
}
