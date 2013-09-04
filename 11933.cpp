#include <iostream>
#include <ios>
#include <cmath>
int main()
{
  std::ios_base::sync_with_stdio(false);
  int n;
  while(std::cin >> n && n != 0){
    int ary[32];
    int pos = 0;
    while(n > 0){
      ary[pos++] = n % 2;
      n /= 2;
    }

    int a = 0, b = 0;
    int one = 1;
    for(int i=0; i<pos; ++i){
      if(ary[i]){
	if(one % 2 == 1)
	  a += pow(2, i);
	else
	  b += pow(2, i);
	++one;
      }
    }
    std::cout << a << " " << b << "\n";
  }
  return 0;
}
