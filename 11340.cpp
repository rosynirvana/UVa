#include <iostream>
#include <ios>
#include <string>
#include <utility>
#include <vector>
#include <cctype>

int main()
{
  int c;
  std::cin >> c;
  for(int i=0; i!=c; ++i){
    int d;
    std::cin >> d;
    int alpha[52] = {0};
    std::vector< std::pair<char, int> > punc;
    int num[10] = {0};
    for(int j=0; j!=d; ++j){
      char a;
      int b;
      std::cin >> a >> b;
      if(isupper(a))
	alpha[a - 'A'] = b;
      else if(islower(a))
	alpha[a - 'a' + 26] = b;
      else if(isdigit(a))
	num[a - '0'] = b;
      else
	punc.push_back(std::make_pair(a, b));
    }
    
    int line;
    std::cin >> line;
    std::cin.get();
    std::string input;
    int sum = 0;
    typedef std::vector< std::pair<char, int> >::const_iterator viter;
    for(int k=0; k!=line; ++k){
      std::getline(std::cin, input);
      for(std::string::const_iterator iter = input.begin();
	  iter != input.end(); ++iter){
	if(isupper(*iter))
	  sum += alpha[*iter - 'A'];
	else if(islower(*iter))
	  sum += alpha[*iter - 'a' + 26];
	else if(isdigit(*iter))
	  sum += num[*iter - '0'];
	else{
	  for(viter piter = punc.begin(); piter!=punc.end(); ++piter)
	    if(*iter == piter -> first){
	      sum += piter -> second;
	      break;
	    }
	}
      }
    }
	int dollar = sum / 100;
	int cent = sum % 100;
	if(cent >= 10)
	  std::cout << dollar << "." << cent << "$\n";
	else
	  std::cout << dollar << ".0" << cent << "$\n";
  }
  return 0;
}
	      
	  
