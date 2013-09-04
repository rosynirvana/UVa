/* WA on UVa but AC on ZeroJudge so it must be a stupid formatting problem */
#include <iostream>
#include <ios>
#include <string>

using std::string;

int main()
{
  int n, p, c = 1;
  while(std::cin >> n >> p){
    if(n == p && n == 0)
      break;
    if(c != 1)
      std::cout << "\n";
    std::cin.get();
    string buf;
    for(int i=0; i!=n; ++i){
      std::getline(std::cin, buf);
    }
    
    string current, opt_name;
    double price, rate, opt_price, opt_rate;
    double num;
    bool all = false;
    std::getline(std::cin, current);
    std::cin >> price >> num;
    std::cin.get();
    opt_name = current;
    opt_price = price;
    if(num == n)
      all = true;
    else{
      rate = num / n;
      opt_rate = rate;
    }
    for(int i=0; i!=num; ++i){
      std::getline(std::cin, buf);
    }
    
    for(int i=1; i!=p; ++i){
      std::getline(std::cin, current);
      std::cin >> price >> num;
      std::cin.get();
      rate = num / n;
      if(num == n && all == true && price < opt_price){
	opt_name = current;
	opt_price = price;
      }
      if(num == n && all != true){
	all = true;
	opt_name = current;
	opt_price = price;
      }
      if(num != n && all != true && rate > opt_rate){
	opt_name = current;
	opt_price = price;
	opt_rate = rate;
      }
      for(int i=0; i!=num; ++i)
	std::getline(std::cin, buf);
    }
    std::cout << "RFP #" << c << "\n" << opt_name << "\n";
    ++c;
  }
  return 0;
}
  
      
