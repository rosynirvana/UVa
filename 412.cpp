#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using std::vector;
int gcd(int, int);
int main()
{
  int x;
  while(std::cin >> x && x != 0){
    vector<int> buf;
    for(int i=0; i!=x; ++i){
      int temp;
      std::cin >> temp;
      buf.push_back(temp);
    }
    int count = 0;
    for(size_t i=0; i!=buf.size(); ++i)
      for(size_t j=i+1; j!=buf.size(); ++j)
	if(gcd(buf[i], buf[j]) == 1)
	  count++;

    if(count != 0){
      double result = sqrt(3 * x * (x-1) * 1.0 / count);
      std::cout << std::setprecision(6) << std::fixed << result << "\n";
    }
    else
      std::cout << "No estimate for this data set.\n";
  }
  return 0;
}

int gcd(int x, int y)
{
  while(x !=0 && y != 0){
    if(x >= y)
      x = x % y;
    else
      y = y % x;
  }
  if(x == 0)
    return y;
  else
    return x;
}
