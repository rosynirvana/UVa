#include <iostream>
#include <string>
#include <cmath>


int main()
{
  long long int base[32];
  for(int i=0; i!=32; ++i)
    base[i] = pow(2, i) - 1;

  std::string input;
  while(std::cin >> input){
    if(input.compare("0") == 0)
      break;

    long long int sum = 0;
    for(size_t i=0; i!=input.size(); ++i)
      if(input[i] == '2')
	sum += (base[input.size()-i] * 2);
      else if(input[i] == '1')
	sum += base[input.size() - i];

    std::cout << sum << "\n";
  }
  return 0;
}
