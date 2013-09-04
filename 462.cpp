#include <iostream>
#include <ios>
#include <string>
#include <sstream>
#include <cstring>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::string input;
  while(std::getline(std::cin, input)){
    if(input.size() == 0)
      break;
    std::stringstream buf(input);
    std::string a_card;
    bool deck[4][13];
    memset(deck, 0, sizeof(deck));
    while(buf >> a_card){
      int x, y;
      if(isdigit(a_card[0]))
	x = a_card[0] - '0' - 2;
      else if(a_card[0] == 'A')
	x = 12;
      else if(a_card[0] == 'T')
	x = 8;
      else if(a_card[0] == 'J')
	x = 9;
      else if(a_card[0] == 'Q')
	x = 10;
      else if(a_card[0] == 'K')
	x = 11;

      switch(a_card[1]){
      case 'S':
	y = 0;
	break;
      case 'H':
	y = 1;
	break;
      case 'D':
	y = 2;
	break;
      case 'C':
	y = 3;
	break;
      }

      deck[y][x] = true;
    }

    int score_part1 = 0, score_part2 = 0;
    int c_S = 0, c_H = 0, c_D=0, c_C=0;
    for(int i=12; i >= 9; --i)
      for(int j=0; j <= 3; ++j)
	if(deck[j][i])
	  score_part1 += (i-8);
    for(int i=0; i<=3; ++i){
      int count = 0;
      for(int j=0; j<=12; ++j)
	if(deck[i][j])
	  ++count;
      if(deck[i][11] && count == 1)
	score_part1 -= 1;
      if(deck[i][10] && count <= 2)
	score_part1 -= 1;
      if(deck[i][9] && count <= 3)
	score_part1 -= 1;
      switch(count){
      case 2:
	score_part2 += 1;
	break;
      case 1:
	score_part2 += 2;
	break;
      case 0:
	score_part2 += 2;
	break;
      }
    }
    for(int i=0; i!=13; ++i)
      if(deck[0][i])
	c_S += 1;
    for(int i=0; i!=13; ++i)
      if(deck[1][i])
	c_H += 1;
    for(int i=0; i!=13; ++i)
      if(deck[2][i])
	c_D += 1;
    for(int i=0; i!=13; ++i)
      if(deck[3][i])
	c_C += 1;
    bool stopped[4] = {false, false, false, false};
    if(deck[0][12] || (deck[0][11] && c_S >= 2) || (deck[0][10] && c_S >= 3))
       stopped[0] = true;
    if(deck[1][12] || (deck[1][11] && c_H >= 2) || (deck[1][10] && c_H >= 3))
      stopped[1] = true;
    if(deck[2][12] || (deck[2][11] && c_D >= 2) || (deck[2][10] && c_D >= 3))
      stopped[2] = true;
    if(deck[3][12] || (deck[3][11] && c_C >= 2) || (deck[3][10] && c_C >= 3))
      stopped[3] = true;

    bool all_stopped = stopped[1] && stopped[0] && stopped[2] && stopped[3];

    if(score_part1 + score_part2 < 14)
      std::cout << "PASS\n";
    else if(score_part1 >= 16 && all_stopped)
      std::cout << "BID NO-TRUMP\n";
    else{
      int max = -1;
      max = c_S > c_H ? c_S : c_H;
      max = max > c_D ? max : c_D;
      max = max > c_C ? max : c_C;

      if(max == c_S)
	std::cout << "BID S\n";
      else if(max == c_H)
	std::cout << "BID H\n";
      else if(max == c_D)
	std::cout << "BID D\n";
      else 
	std::cout << "BID C\n";
    }
  }
  return 0;
}
