#include <iostream>
#include <ios>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::string input;
  while(std::cin >> input){
    if(input.compare("0:00") == 0)
      break;
    std::stringstream buf(input);
    int h, m;
    char sep;
    buf >> h >> sep >> m;
    double m_angle = 6 * m;
    double h_angle = 30 * h + 0.5 * m;
    double result;
    result = fabs(m_angle - h_angle);
    if(result > 180)
      result = 360 - result;
    std::cout << std::setprecision(3) << std::fixed << result << "\n";
  }
  return 0;
}
