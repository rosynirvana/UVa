#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
int main()
{
  int n;
  int c = 1;
  while(std::cin >> n){
    if(n == 0)
      break;
    std::cout << "Case " << c << ":\n";
    std::vector<int> s, buf;
    for(int i=0; i!=n; ++i){
      int temp;
      std::cin >> temp;
      s.push_back(temp);
    }
    std::sort(s.begin(), s.end());
    size_t end = std::unique(s.begin(), s.end()) - s.begin();
    //std::cout << "end is " << end << "\n";
    for(size_t i=0; i!=end-1; ++i)
      for(size_t j=i+1; j!=end; ++j)
	buf.push_back(s[i] + s[j]);
    if(buf.size() == 0)
      buf.push_back(0);
    // std::cout << "buf.size() is " << buf.size() << "\n";
    std::sort(buf.begin(), buf.end());
    int q;
    std::cin >> q;
    for(int i=0; i!=q; ++i){
      int temp, result = 0;
      std::cin >> temp;
      int diff = INT_MAX;
      std::vector<int>::iterator up, low;
      up = std::lower_bound(buf.begin(), buf.end(), temp);
      low = std::lower_bound(buf.begin(), buf.end(), temp);

      if(low != buf.end()){
	if(abs(*low - temp) < diff){
	  diff = abs(*low - temp);
	  result = *low;
	}
	if(low != buf.begin()){
	  --low;
	  if(abs(*low - temp) < diff){
	    result = *low;
	    diff = abs(*low - temp);
	  }
	}
      }
      if(up != buf.end()){
	if(abs(*up - temp) < diff)
	   result = *up;
      }
      else{
	if(abs(buf.back() - temp) < diff)
	  result = buf.back();
      }
      std::cout << "Closest sum to " << temp << " is " << result << ".\n";
    }
    ++c;
  }
  return 0;
}
