#include <iostream>
#include <bitset>
#include <string>

int main()
{
  unsigned long i;
  while(std::cin >> i && i != 0){
    std::bitset<35> bin(i);
    std::string b = bin.to_string();
    size_t i;
    for(i = 0; i != b.size(); ++i)
      if(b[i] == '1')
	break;

    std::cout << "The parity of " << b.substr(i) << " is " << bin.count()
	      << " (mod 2).\n";
  }
  return 0;
}
