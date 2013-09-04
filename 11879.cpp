#include <iostream>
#include <ios>
#include <string>
#include <cstdlib>

using std::string;

void minus(string&, int);

int main()
{
  string input;
  while(std::cin >> input){
    if(input.compare("0") == 0)
      break;

    while(input.size() >= 10){
      int temp = (input[input.size()-1] - '0') * 5;
      input.resize(input.size() - 1);
      minus(input, temp);
    }

    int a = atoi(input.c_str());
    if(a % 17 == 0)
      std::cout << "1" << "\n";
    else
      std::cout << "0" << "\n";
  }
  return 0;
}

void minus(string& input, int a)
{
  int temp = input[input.size() - 1] - '0'+
    (input[input.size() - 2] - '0') * 10;
  int borrow;
  if(temp >= a){
    borrow = 0;
    temp -= a;
  }
  else{
    borrow = -1;
    temp = 100 + temp - a;
  }
  input[input.size() - 1] = temp % 10 + '0';
  input[input.size() - 2] = temp / 10 + '0';
  for(size_t i=input.size()-3; borrow == -1 && i>=0; --i){
    if(input[i] == '0')
      input[i] = '9';
    else{
      input[i] -= 1;
      borrow = 0;
    }
  }

  if(input[0] == '0')
    input = input.substr(1);
}
