#include <iostream>
#include <ios>

int main()
{
  int money[5] = {1,5,10,25,50};
  int change[7490] = {1};
  for(int i=0; i!=5; ++i)
    for(int j=money[i]; j != 7490; ++j)
      change[j] += change[j - money[i]];

  int x;
  while(std::cin >> x){
    std::cout << change[x] << "\n";
  }
  return 0;
}
