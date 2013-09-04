#include <iostream>
#include <vector>

using std::vector;

int main()
{
  int t;
  std::cin >> t;
  for(int i=0; i!=t; ++i){
    int n;
    vector<int> buf;
    std::cin >> n;
    for(int j=0; j!=n; ++j){
      int temp;
      std::cin >> temp;
      buf.push_back(temp);
    }
    
    int result = 0;
    vector<int>::const_iterator iter = buf.begin();
    ++iter;
    for(; iter != buf.end(); ++iter){
      int count = 0;
      for(vector<int>::const_iterator inner_iter = buf.begin();
	  inner_iter != iter; ++inner_iter)
	if(*iter >= *inner_iter)
	  ++count;
      result += count;
    }
    std::cout << result << "\n";
  }
  return 0;
}

    
