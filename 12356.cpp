#include <iostream>
#include <ios>
#include <cstring>

struct leap{
  int left;
  int right;
  leap():left(-2), right(-2) {}
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  int S, B;
  while(std::cin >> S >> B && S!=0){
    leap* line = new leap[S];
    
    for(int i=0; i!=B; ++i){
      int L, R;
      std::cin >> L >> R;
      if(R >= S || line[R].right == -2)
	line[L-1].right = R;
      else
	line[L-1].right = line[R].right;
     
      if(L-2 < 0 || line[L-2].left == -2)
	line[R-1].left = L-2;
      else
	line[R-1].left = line[L-2].left;
      #ifdef DEBUG
      for(int i=0; i!=S; ++i)
	std::cout <<"(" << line[i].left << "," << line[i].right <<")";
      std::cout << std::endl;
      #endif
      if(line[R-1].left < 0)
	std::cout << "* ";
      else
	std::cout << line[R-1].left+1 << " ";
      
      if(line[L-1].right>= S)
	std::cout << "*\n";
      else
	std::cout << line[L-1].right+1 << "\n";
    }
    std::cout << "-\n";
    delete[] line;
  }
  return 0;
}
