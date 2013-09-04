#include <iostream>
#include <ios>
#include <vector>
#include <map>

using std::vector;
using std::map;

int main()
{
  int x;
  vector<int> seq;
  map<int, int> buf;
  while(std::cin >> x){
    map<int, int>::iterator iter = buf.find(x);
    if(iter == buf.end()){
      seq.push_back(x);
      buf[x] = 1;
    }
    else
      (iter->second) += 1;
  }
  for(vector<int>::const_iterator viter = seq.begin();
      viter != seq.end(); ++viter){
    map<int, int>::iterator miter = buf.find(*viter);
    std::cout << miter->first << " " << miter->second << "\n";
  }
  return 0;
}
    
