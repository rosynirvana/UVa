#include <iostream>
#include <ios>
#include <deque>
#include <stack>
#include <sstream>

void move_onto(int, int);
void move_over(int, int);
void pile_onto(int, int);
void pile_over(int, int);
void print_block(int);
inline void init(int);
inline int find(int);

std::deque<int> pool[25];
int ary[25];

int main()
{
  int n;
  std::cin >> n;
  std::cin.get();
  init(n);
  std::string input;
  while(std::getline(std::cin, input)){
    //std::cout << input << "\n";
    if(input.compare("quit") == 0)
      break;
    std::string a,b;
    int m,n;
    std::stringstream buf(input);
    buf >> a >> m >> b >> n;
    if(a.compare("move") == 0 && b.compare("onto") == 0)
      move_onto(m, n);
    else if(a.compare("move") == 0 && b.compare("over") == 0)
      move_over(m, n);
    else if(a.compare("pile") == 0 && b.compare("onto") == 0)
      pile_onto(m ,n);
    else
      pile_over(m, n);
    //print_block(n);
  }
  print_block(n);
  return 0;
}

void init(int a)
{
  for(int i=0; i!=a; ++i)
    pool[i].push_back(i);
  for(int i=0; i!=a; ++i)
    ary[i] = i;
}
void return_block(int a)
{
  ary[a] = a;
  pool[a].push_front(a);
}
void move_onto(int a, int b)
{
  int m = find(a);
  int n = find(b);
  if(m == n)
    return;
  int temp;
  temp = pool[m].front();
  //std::cout << m << " " << n << " " << temp << "\n";
  while(temp != a){
    return_block(temp);
    pool[m].pop_front();
    temp = pool[m].front();
  }
  pool[m].pop_front();
  temp = pool[n].front();
  while(temp != b){
    return_block(temp);
    pool[n].pop_front();
    temp = pool[n].front();
  }
  pool[n].push_front(a);
  ary[a] = n;
}
void move_over(int a, int b)
{
  int m = find(a);
  int n = find(b);
  if(m == n)
    return;
  int temp = pool[m].front();
  while(temp != a){
    return_block(temp);
    pool[m].pop_front();
    temp = pool[m].front();
  }
  pool[m].pop_front();
  pool[n].push_front(a);
  ary[a] = n;
}
void pile_onto(int a, int b)
{
  int m = find(a);
  int n = find(b);
  int temp = pool[n].front();
  if(m == n)
    return;
  while(temp != b){
    return_block(temp);
    pool[n].pop_front();
    temp = pool[n].front();
  }
  std::stack<int> stk;
  temp = pool[m].front();
  while(temp != a){
    stk.push(temp);
    pool[m].pop_front();
    temp = pool[m].front();
  }
  pool[m].pop_front();
  pool[n].push_front(a);
  ary[a] = n;
  while(!stk.empty()){
    int tem = stk.top();
    ary[tem] = n;
    stk.pop();
    pool[n].push_front(tem);
  }
}
void pile_over(int a, int b)
{
  int m = find(a);
  int n = find(b);
  if(m == n)
    return;
  std::stack<int> stk;
  int temp = pool[m].front();
  while(temp != a){
    stk.push(temp);
    pool[m].pop_front();
    temp = pool[m].front();
  }
  pool[m].pop_front();
  pool[n].push_front(temp);
  ary[a] = n;
  while(!stk.empty()){
    int tem = stk.top();
    //std::cout << tem << "\n";
    stk.pop();
    ary[tem] = n;
    pool[n].push_front(tem);
  }
}
int find(int a)
{
  return ary[a];
}
void print_block(int n)
{
  for(int i=0; i!=n; ++i){
    std::cout << i << ":";
    if(pool[i].size() != 0)
      std::cout << " ";
    while(pool[i].size() > 1){
      int temp = pool[i].back();
      std::cout << temp << " ";
      pool[i].pop_back();
    }
    if(pool[i].size() == 1){
      int temp = pool[i].back();
      std::cout << temp;
      pool[i].pop_back();
    }
    if(pool[i].size() == 0)
      std::cout << "\n";
  }
}
