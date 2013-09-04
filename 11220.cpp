#include <iostream>
#include <string>
#include <sstream>

using std::string;

int main()
{
  int c;
  std::cin >> c;
  std::cin.get();
  std::cin.get();
  string input;
  for(int i=0; i!=c; ++i){
    std::cout << "Case #" << i+1 << ":\n";
    while(std::getline(std::cin, input)){
      if(input.size() == 0)
	break;

      std::stringstream buf(input);
      string result;
      unsigned int count = 0;
      while(buf >> input){
	if(input.size() >= count+1){
	  result.push_back(input[count]);
	  ++count;
	}
      }
     std::cout << result << "\n";
    }
    if(i != c-1)
      std::cout << "\n";
  }
  return 0;
}
