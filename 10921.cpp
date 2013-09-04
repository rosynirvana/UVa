#include <iostream>
#include <ios>
#include <string>

char conv(char);

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::string input;
  while(std::cin >> input){
    for(std::string::const_iterator iter = input.begin();
	iter != input.end(); ++iter)
      std::cout << conv(*iter);
    std::cout << "\n";
  }
  return 0;
}

char conv(char c)
{
  if(c >= 'A' && c <= 'C')
    return '2';
  if(c >= 'D' && c <= 'F')
    return '3';
  if(c >= 'G' && c <= 'I')
    return '4';
  if(c >= 'J' && c <= 'L')
    return '5';
  if(c >= 'M' && c <= 'O')
    return '6';
  if(c >= 'P' && c <= 'S')
    return '7';
  if(c >= 'T' && c <= 'V')
    return '8';
  if(c >= 'W' && c <= 'Z')
    return '9';

  if(c == '1')
    return '1';
  if(c == '0')
    return '0';
 
    return '-';
}
