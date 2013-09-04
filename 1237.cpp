#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

struct data{
  string name;
  int lower, upper;

  data(string d, int l, int u): name(d), lower(l), upper(u){}
};

int main()
{
  int n;
  std::cin >> n;
  for(int i=0; i!=n; ++i){
    if(i!=0)
      std::cout << "\n";
    int d;
    vector<data> db;
    std::cin >> d;
    for(int j=0; j!=d; ++j){
      string name;
      int lower, upper;
      std::cin >> name >> lower >> upper;
      db.push_back(data(name, lower, upper));
    }
    int c;
    std::cin >> c;
    for(int j=0; j!=c; ++j){
      int price;
      std::cin >> price;
      bool found = false;
      string result;
      for(vector<data>::const_iterator iter = db.begin();
	  iter != db.end(); ++iter){
	if(price >= iter->lower && price <= iter->upper){
	  if(found){
	    found = false;
	    break;
	  }
	  else{
	    found = true;
	    result = iter->name;
	  }
	}
      }
      if(found)
	std::cout << result << "\n";
      else
	std::cout << "UNDETERMINED\n";
    }
  }
  return 0;
}
