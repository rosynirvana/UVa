#include <iostream>
#include <string>

using std::string;

bool is_vowel(char ch);

int main()
{
  int n;
  std::cin >> n;
  string s1, s2;
  while(std::cin >> s1 >> s2){
    bool same = true;
    if(s1.size() != s2.size()){
      std::cout << "No\n";
      continue;
    }
    for(size_t i=0; i!=s1.size(); ++i)
      if(tolower(s1[i]) != tolower(s2[i])){
	if(!(is_vowel(s1[i]) && is_vowel(s2[i]))){
	  same = false;
	  break;
	}
      }
    if(same)
      std::cout << "Yes\n";
    else
      std::cout << "No\n";
  }
  return 0;
}

bool is_vowel(char ch)
{
  char a = tolower(ch);
  if(a == 'a' || a == 'e' || a == 'i' ||
     a == 'o' || a == 'u')
    return true;
  return false;
}
      

