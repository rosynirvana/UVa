#include <cstdio>

int main()
{
  int n;
  int ary[1000];
  while(scanf("%d", &n) && n != 0){
    int sum = 0;
    for(int i=0; i!=n; ++i){
      int a, b;
      scanf("%d.%d", &a, &b);
      ary[i] = a * 100 + b;
      sum += a * 100 + b;
    }
    int avg = sum / n;
    if(sum % n * 1.0 / n > 0.5 || sum % n * 2 == n)
      avg += 1;
    sum = 0;
    int sum2 = 0;
    for(int i=0; i!=n; ++i)
      if(ary[i] > avg)
	sum += ary[i] - avg;
      else
	sum2 += avg - ary[i];

    if(sum2 < sum)
      sum = sum2;

    printf("$%d.%02d\n", sum/100, sum%100);
  }
  return 0;
}
