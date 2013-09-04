#include <iostream>
#include <ios>
#include <vector>
#include <utility>
#include <sstream>
#include <cmath>
#include <string>

using std::string;
using std::stringstream;
using std::pair;
using std::make_pair;
using std::vector;

int main()
{
  int buf[32768] = {0,0};
  for(int i=2; i!= 32768; ++i)
    buf[i] = i;
  vector<int> p_table;
  while(true){
    int i;
    for(i=2; i!=32768; ++i)
      if(buf[i] != 0)
	break;
    if(i > 182)
      break;
    p_table.push_back(i);
    for(int j=i; j<32768; j+=i)
      buf[j] = 0;
  }
  for(int i=2; i!=32768; ++i)
    if(buf[i] != 0)
      p_table.push_back(i);

  string input;
  stringstream input_buf;
  while(std::getline(std::cin, input)){
    if(input.compare("0") == 0)
      break;
    input_buf.clear();
    input_buf << input;
    int b, e;
    int product = 1;
    while(input_buf >> b >> e)
      product = product * static_cast<int>(pow(b, e));
    product -= 1;

    vector< pair<int, int> > result;
    
    for(vector<int>::const_iterator iter = p_table.begin();
	iter != p_table.end(); ++iter){
      if(product % *iter == 0){
	result.push_back(make_pair(*iter, 1));
	product /= *iter;
	while(product % *iter == 0 && product > 1){
	  result.back().second += 1;
	  product /= *iter;
	}
	if(product == 1)
	  break;
      }
    }
    for(int i = result.size()-1; i >= 0; --i){
      std::cout << result[i].first << " " << result[i].second;
      if(i != 0)
	std::cout << " ";
    }
    std::cout << "\n";
  }
  return 0;
}

