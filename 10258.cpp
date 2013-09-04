#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <ios>
#include <sstream>

struct rec{
  bool first;
  int second;
  rec():first(false), second(0){}
};
struct contestant{
  int id;
  int num_of_solved;
  int penalty;
  contestant():id(0), num_of_solved(0), penalty(0){}
  contestant(int a, int b, int c): id(a), num_of_solved(b), penalty(c){}
};
bool comp(contestant a, contestant b)
{
  if(a.num_of_solved > b.num_of_solved)
    return true;
  if(a.num_of_solved < b.num_of_solved)
    return false;
  if(a.penalty < b.penalty)
    return true;
  if(a.penalty > b.penalty)
    return false;
  if(a.id < b.id)
    return true;
  return false;
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  int c;
  std::cin >> c;
    std::cin.get();
    std::cin.get();
    for(int z=0; z!=c; ++z){
    rec pool[9][100];
    bool participated[100] = {0};
    std::string input;
    while(std::getline(std::cin, input) && input.size() != 0){
    
      std::stringstream buf(input);
      int c, p, time;
      buf >> c >> p >> time;
      char state = input[input.size()-1];

      participated[c-1] = true;
      if(state != 'C' && state != 'I')
	continue;
      if(state == 'C' && pool[p-1][c-1].first == false){
	pool[p-1][c-1].first = true;
	pool[p-1][c-1].second += time;
      }
      else if(state == 'I' && pool[p-1][c-1].first == false)
	pool[p-1][c-1].second += 20;
    }

    std::vector< contestant > result;
    for(int i=0; i!=100; ++i){
      if(participated[i]){
	int solved = 0, penalty = 0;
	for(int j=0; j!=9; ++j){
	  if(pool[j][i].first){
	    solved += 1;
	    penalty += pool[j][i].second;
	  }
	}
	contestant temp(i+1, solved, penalty);
	result.push_back(temp);
      }
    }

    std::sort(result.begin(), result.end(), comp);
    for(size_t i=0; i!=result.size(); ++i)
      std::cout << result[i].id << " " << result[i].num_of_solved << " "
		<< result[i].penalty << "\n";
    if(z != c-1)
      std::cout << "\n";
    }
    
  return 0;
}
		    
	  
    
      
  
