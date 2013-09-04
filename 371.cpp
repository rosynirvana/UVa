#include <iostream>
#include <utility>

int cycle(long long int);

int main()
{
  int l ,h;
  while(std::cin >> l >> h){
    if(l == h && l == 0)
      break;
    if(h < l)
      std::swap(l, h);
    int max = -1, pos = 0;
    for(int i=l; i<=h; ++i){
      int temp = cycle(i);
      if(temp > max){
	max = temp;
	pos = i;
      }
    }

    std::cout << "Between " << l << " and " <<
      h << ", " << pos << " generates the longest sequence of " 
	      << max << " values.\n";
  }
  return 0;
}

int cycle(long long int num)
{
  if(num == 1)
    return 3;

  int c = 0;
  while(num != 1){
    if(num % 2 == 0)
      num /= 2;
    else
      num = num * 3 + 1;
    ++c;
  }
  return c;
}

      
