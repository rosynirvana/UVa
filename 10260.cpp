#include <iostream>
#include <string>

using std::string;

char mapping(char);

int main()
{
  string input;
  while(std::cin >> input){
    if(input.size() == 0)
      break;

    string result;
    char last;
        
    for(string::const_iterator iter = input.begin();
	iter != input.end(); ++iter){
      if(*iter == 'A' || *iter == 'E' || *iter == 'I' ||
	 *iter == 'O' || *iter == 'U' || *iter == 'H' ||
	 *iter == 'W' || *iter == 'Y')
	last = mapping(*iter);
      else{
	if(iter == input.begin()){
	  last = mapping(*iter);
	  result.push_back(mapping(*iter));
	}
	else{
	  if(mapping(*iter) != last){
	    last = mapping(*iter);
	    result.push_back(mapping(*iter));
	  }
	}
      }
    }
    if(result.size() > 0)
      std::cout << result << "\n";
    else
      std::cout << "\n";
  }
  return 0;
}

char mapping(char c)
{
  if(c == 'B' || c == 'F' || c == 'P' || c == 'V')
    return '1';
  if(c == 'C' || c== 'G' || c == 'J' || c == 'K'||
     c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
    return '2';
  if(c == 'D' || c == 'T')
    return '3';
  if(c == 'L')
    return '4';
  if(c == 'M' || c == 'N')
    return '5';
  if(c == 'R')
    return '6';
  return '0';
}
	    
