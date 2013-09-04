#include <iostream>
#include <string>

using std::string;

int main()
{
  string input;
  std::getline(std::cin, input);
  while(std::getline(std::cin, input)){
    if(input[0] == '_')
      break;
    //    std::cout << input << "\n";
    for(string::iterator iter = input.begin(); iter != input.end();
	++iter)
      if(*iter == 'o')
	*iter = 1;
      else if(*iter == ' ')
	*iter = 0;

    int num = input[2]*64 + input[3]*32 + input[4]*16 + input[5]*8 +
      input[7]*4 + input[8]*2 + input[9];

    std::cout << static_cast<char>(num);
  }
  return 0;
}
