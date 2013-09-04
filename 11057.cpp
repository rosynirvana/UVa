#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

int main()
{
  std::ios_base::sync_with_stdio(false);
  int n;
  while(std::cin >> n){
    std::vector<int> price;
    for(int i=0; i!=n; ++i){
      int temp;
      std::cin >> temp;
      price.push_back(temp);
    }
    int money;
    std::cin >> money;
    std::sort(price.begin(), price.end());

    int result;
    if(money % 2 == 0){
      int p = money / 2;
      std::vector<int>::iterator low, up;
      low = std::lower_bound(price.begin(), price.end(), p);
      up = std::upper_bound(price.begin(), price.end(), p);
      if(up != low){
	std::cout << "Peter should buy books whose prices are " << p << " and "
		<<p << ".\n\n";
	continue;
      }
    }
    for(std::vector<int>::const_iterator iter = price.begin();
	iter != price.end(); ++iter){
      if(*iter > money/2)
	break;
      int a, b;
      a = *iter;
      b = money - a;
      if(binary_search(price.begin(), price.end(), b))
	 result = a;
    }
    std::cout << "Peter should buy books whose prices are " << result << " and "
	      << money - result << ".\n\n";
  }
  return 0;
}
	 

    

    
