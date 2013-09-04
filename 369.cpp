#include <iostream>
#include <ios>
#include <vector>

inline int gcd(int, int);

int main()
{
	int n, m;
	while(std::cin >> n >> m){
		if(n==0 && m==0)
			break;
		int oriM = m;
		long product = 1;
		if(m != n){
			if(m > n/2)
				m = n - m;

			std::vector<int> big, small;
			for(int i=0; i!= m; ++i)
				big.push_back(n-i);
		
			for(int i=m; i>=2; --i)
				small.push_back(i);

			for(std::vector<int>::iterator iter = small.begin(); 
				iter != small.end(); ++iter)
				for(std::vector<int>::iterator iterB = big.begin();
					iterB != big.end(); ++iterB)
					if(*iterB % *iter == 0){
						*iterB /= *iter;
						break;
					}
					else{
						int temp = gcd(*iterB, *iter);
						*iterB /= temp;
						*iter /= temp;

						if(*iter == 1)
							break;
					}

		
			for(std::vector<int>::const_iterator iter = big.begin();
				iter != big.end(); ++iter)
				product *= *iter;
		}
	
		std::cout << n << " things taken " << oriM << " at a time is " 
		<< product << " exactly.\n";
	}
	return 0;
}

int gcd(int a, int b)
{
	while(a > 0 && b > 0){
		if(a >= b)
			a = a % b;
		else
			b = b % a;
	}

	return (a == 0 ? b : a);
}