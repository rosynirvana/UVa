#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::vector;

int main()
{
  int f, r;
  while(std::cin >> f >> r){
    if(f == 0)
      break;

    vector<int> front, rear;
    for(int i=0; i!=f; ++i){
      int temp;
      std::cin >> temp;
      front.push_back(temp);
    }

    for(int i=0; i!=r; ++i){
      int temp;
      std::cin >> temp;
      rear.push_back(temp);
    }

    vector<double> result;
    for(vector<int>::const_iterator fiter = front.begin();
	fiter != front.end(); ++fiter)
      for(vector<int>::const_iterator riter = rear.begin();
	  riter != rear.end(); ++riter)
	result.push_back(1.0 * *fiter / *riter);

    std::sort(result.begin(), result.end());
 
    double max = -1;
    for(size_t i=0; i!=result.size()-1; ++i){
      if(result[i+1] / result[i] > max)
	max = result[i+1] / result[i];
    }
    std::cout << std::setprecision(2) << std::fixed << max << "\n";
  }
  return 0;
}
