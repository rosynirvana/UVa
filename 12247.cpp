#include <iostream>
#include <ios>

int main()
{
  std::ios_base::sync_with_stdio(false);
  int deck[5];
  while(true){
    for(int i=0; i!=5; ++i)
      std::cin >> deck[i];
    if(deck[0] == deck[1] && deck[1] == 0)
      break;
    int alldeck[52] = {0};
    for(int i=0; i!=5; ++i)
      alldeck[deck[i]-1] = 1;
    
    int pe_min, pe_max, pe_middle;
    pe_min = deck[0] < deck[1] ? deck[0] : deck[1];
    pe_min = pe_min < deck[2] ? pe_min : deck[2];
    pe_max = deck[0] > deck[1] ? deck[0] : deck[1];
    pe_max = pe_max > deck[2] ? pe_max : deck[2];

    for(int i=0; i!=3; ++i)
      if(deck[i] != pe_min && deck[i] != pe_max)
	pe_middle = deck[i];

    int p_min, p_max;
    p_min = deck[3] > deck[4] ? deck[4] : deck[3];
    p_max = deck[3] > deck[4] ? deck[3] : deck[4];
    
    if(p_min < pe_middle && p_max > pe_max){
      int i = pe_max-1;
      for(; i!=52; ++i)
	if(alldeck[i] == 0)
	  break;
      if(i == 52)
	std::cout << "-1";
      else
	std::cout << i+1 << "\n";
    }
    else if(p_min < pe_middle)
      std::cout << "-1\n";
    else if(p_max > pe_middle && p_max < pe_max){
      int i;
      for(i = pe_middle-1; i!=52; ++i)
	if(alldeck[i] == 0)
	  break;
      if(i == 52)
	std::cout << "-1\n";
      else
	std::cout << i+1 << "\n";
    }
    else if(p_max > pe_max){
      if(p_min > pe_max){
	int i;
	for(i=0; i!=52; ++i)
	  if(alldeck[i] == 0)
	    break;
	std::cout << i + 1 << "\n";
      }
      else if(p_min < pe_max && p_min > pe_middle){
	int i;
	for(i=pe_middle; i!=52; ++i)
	  if(alldeck[i] == 0)
	    break;
	if(i == 52)
	  std::cout << "-1\n";
	else
	  std::cout << i+1 << "\n";
      }
    }
  }
  return 0;
}
	  

    
