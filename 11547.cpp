#include <iostream>
#include <ios>
#include <cstdlib>

int main()
{
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  for(int i=0; i!=n; ++i){
    int x;
    std::cin >> x;
    std::cout << abs(315*x+36962) % 100 /10 << "\n";
  }
  return 0;
}
