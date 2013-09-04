#include <iostream>
#include <ios>

int main()
{
  std::ios_base::sync_with_stdio(false);
  int m, n;
  while(std::cin >> m >> n){
    std::cout << m * n - 1 << "\n";
  }
  return 0;
}
