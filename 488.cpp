#include <iostream>
#include <ios>

void print_wave(int);

int main()
{
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  for(int i=0; i!=n; ++i){
    int a, f;
    std::cin >> a >> f;
    if(i != 0)
      std::cout << "\n";

    for(int j=0; j!=f; ++j){
      print_wave(a);
      if(j != f-1)
	std::cout << "\n";
    }
  }
  return 0;
}

void print_wave(int a)
{
    for(int i=1; i<=a; ++i){
      for(int j=1; j<=i; ++j)
	std::cout << i;
      std::cout << "\n";
    }
    for(int i=a-1; i>=1; --i){
      for(int j=i; j>=1; --j)
	std::cout << i;
      std::cout << "\n";
    }
  
}
