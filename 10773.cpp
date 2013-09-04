#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
  int n;
  std::cin >> n;
  for(int i=1; i<=n; ++i){
    double distance, river, boat;
    std::cin >> distance >> river >> boat;
    std::cout << "Case " << i << ": ";
    if(river >= boat || river == 0 || boat == 0)
      std::cout << "can't determine\n";
    else
      std::cout << std::setprecision(3) << std::fixed << 
	distance * ( 1.0/sqrt(boat*boat-river*river) - 1.0/boat) << "\n";
  }
  return 0;
}
