#include <iostream>
#include <ios>
#include <string>
#include <cstdlib>

int main()
{
  std::string input;
  std::ios_base::sync_with_stdio(false);
  while(std::cin >> input && input.compare("0")!=0){
    int num;
    if(input.size() <= 9){
      num = atoi(input.c_str());
    }
    else{
      int a = input.size()-1, b=input.size()-2;
      int sum1 = 0, sum2 = 0;
      for(; a>=0; a-=2)
	sum1 += (input[a] - '0');
      for(; b>=0; b-=2)
	sum2 += (input[b] - '0');
      num = abs(sum1 - sum2);
    }
    if(num % 11 == 0)
      std::cout << input << " is a multiple of 11.\n";
    else
      std::cout << input << " is not a multiple of 11.\n";
  }
  return 0;
}
