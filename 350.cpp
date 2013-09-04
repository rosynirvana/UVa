#include <cstdio>

int main()
{
  int z, i ,m ,l;
  int c = 1;
  while(scanf("%d %d %d %d", &z, &i, &m, &l) && m != 0){
    int count = 0;
    int last_a = l, last_b = l;
    while(true){
      int a = (z*last_a+i)%m;
      
      int b = (z*last_b+i)%m;
      b = (z*b+i)%m;
      
      ++count;
      if(a == b)
	break;
      last_a = a;
      last_b = b;
    }
    printf("Case %d: %d\n", c, count);
    ++c;
  }
  return 0;
}
      
      
