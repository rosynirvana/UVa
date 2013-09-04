#include <iostream>
#include <ios>
#include <string>
#include <cctype>
#include <algorithm>

bool ispar(std::string&);

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::string input;
  while(std::getline(std::cin, input)){
    if(input.compare("DONE") == 0)
      break;
    if(ispar(input))
      std::cout << "You won't be eaten!\n";
    else
      std::cout << "Uh oh..\n";
  }
  return 0;
}

bool ispar(std::string& input)
{
  std::string stripped;
  for(std::string::const_iterator iter = input.begin();
      iter!=input.end(); ++iter)
    if(isalpha(*iter))
      stripped.push_back(toupper(*iter));
  std::string ori = stripped;
  std::reverse(stripped.begin(), stripped.end());
  if(stripped.compare(ori) == 0)
    return true;
  return false;
}
