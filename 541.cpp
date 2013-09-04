#include <iostream>
#include <ios>
#include <vector>

int main()
{
	int n;
	int ary[99][99];
	while(std::cin >> n && n != 0){
		for(int i=0; i!=n; ++i)
			for(int j=0; j!=n; ++j)
				std::cin >> ary[i][j];

		std::vector<int> col, row;
		for(int i=0; i!=n; ++i){
			int sum = 0;
			for(int j=0; j!=n; ++j)
				sum += ary[i][j];
			if(sum % 2 == 1)
				row.push_back(i);
		}

		for(int i=0; i!=n; ++i){
			int sum = 0;
			for(int j=0; j!=n; ++j)
				sum += ary[j][i];
			if(sum % 2 == 1)
				col.push_back(i);
		}

		if(col.size() == 0 && row.size() == 0)
			std::cout << "OK\n";
		else if(col.size() >= 2 || row.size() >= 2)
			std::cout << "Corrupt\n";
		else
			std::cout << "Change bit (" << row[0]+1 << "," << col[0]+1 << ")\n";
	}
	return 0;
}