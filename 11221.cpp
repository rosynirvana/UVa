#include <iostream>
#include <ios>
#include <string>
#include <cmath>
#include <algorithm>

std::string strip(const std::string&);
bool check(const std::string&, int);

int main()
{
  int c;
  std::ios_base::sync_with_stdio(false);
  std::cin >> c;
  std::cin.get();
  for(int i=1; i<=c; ++i){
    std::string input;
    std::getline(std::cin, input);
    std::string str = strip(input);
    int s = str.size();
    int n = static_cast<int>(sqrt(s));
    if(n * n != s || !check(str, n))
      std::cout << "Case #" << i << ":\nNo magic :(\n";
    else{
      std::cout << "Case #" << i << ":\n" << n << "\n";
    }
  }
  return 0;
}

std::string strip(const std::string& input)
{
  std::string s;
  for(std::string::const_iterator iter=input.begin();
      iter!=input.end(); ++iter)
    if(isalpha(*iter))
      s.push_back(toupper(*iter));

  return s;
}

bool check(const std::string& input, int n)
{
  int matrix[n][n];
  int pos = 0;
  for(int i=0; i!=n; ++i)
    for(int j=0; j!=n; ++j){
      matrix[i][j] = input[pos];
      ++pos;
    }

  std::string str2, str3, str4;
  for(int i=0; i!=n; ++i)
    for(int j=0; j!=n; ++j)
      str2.push_back(matrix[j][i]);

  for(int i=n-1; i>=0; --i)
    for(int j=n-1; j>=0; --j)
      str3.push_back(matrix[j][i]);

  str4 = input;
  std::reverse(str4.begin(), str4.end());
  if(input.compare(str2) == 0 && str2.compare(str3) == 0
     && str3.compare(str4) == 0)
     return true;
  return false;
}
