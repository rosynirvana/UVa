#include <iostream>
#include <ios>
#include <climits>

int main()
{
  int num_parti, budget, num_hotel, num_week;
  while(std::cin >> num_parti >> budget >> num_hotel >> num_week){
    int min = INT_MAX;
    for(int i=0; i!=num_hotel; ++i){
      int price_per_day;
      std::cin >> price_per_day;
      for(int j=0; j!=num_week; ++j){
	int num_bed;
	std::cin >> num_bed;
	if(num_bed >= num_parti && num_parti * price_per_day <= budget
	   && num_parti * price_per_day < min)
	  min = num_parti *price_per_day;
      }
    }
    if(min == INT_MAX)
      std::cout << "stay home\n";
    else
      std::cout << min << "\n";
  }
  return 0;
}
