#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <cctype>

using std::string;

int sum_word(const string&);

int main()
{
  string a, b;
  while(true){
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    if(std::cin.eof())
      break;
    double x = sum_word(a);
    double y = sum_word(b);
    if(x || y){
      double r = (x > y ? y / x : x / y);
      r *= 100;
      std::cout << std::setprecision(2) << std::fixed << r << " %\n";
    }
    else
      std::cout << "\n";
  }
  return 0;
}

int sum_word(const string& input)
{
  int sum = 0;
  for(string::const_iterator iter = input.begin();
      iter != input.end(); ++iter)
    if(isalpha(*iter))
      sum += (tolower(*iter) - 'a' + 1);

  while(sum >= 10)
    sum = sum / 10 + sum % 10;

  return sum;
}
