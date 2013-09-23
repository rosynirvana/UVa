#include <iostream>
#include <string>
#include <cmath>

using std::string;

int main()
{
  int case_num;
  std::cin >> case_num;
  std::cin.get();
  string input;
  for(int c=0; c!=case_num; ++c){
    std::getline(std::cin, input);
    int len = input.size();
    int l = sqrt(len);
    if(l * l != len){
      std::cout << "INVALID\n";
      continue;
    }
    for(int i=0; i!=l; ++i)
      for(int j=i; j<len; j+=l)
	std::cout << input[j];
    std::cout << "\n";
  }
  return 0;
}
	
      
