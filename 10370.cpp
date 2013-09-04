#include <iostream>
#include <ios>
#include <iomanip>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int C;
	int score[1000];
	std::cin >> C;
	for(int i=0; i!=C; ++i){
		int N, sum = 0;
		std::cin >> N;

		for(int j=0; j!=N; ++j){
			std::cin >> score[j];
			sum += score[j];
		}

		double avg = sum * 1.0 / N;

		int count = 0;
		for(int j=0; j!=N; ++j)
			if(score[j] > avg)
				++count;


		std::cout << std::setprecision(3) << std::fixed << count * 1.0 / N * 100 << "%\n";
	}
	return 0;
}