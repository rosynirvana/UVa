/* AC on zerojudge but WA on Uva, I don't know why */
#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	for(int i=0; i!=T; ++i){
		int lower, upper;
		std::cin >> lower >> upper;
		if(lower % 2 == 0)
			++lower;

		int sum = 0;
		for(; lower <= upper; lower += 2)
			sum += lower;

		std::cout << "Case " << i+1 << ": " << sum << "\n";
	}
	return 0;
}