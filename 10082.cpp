#include <cstdio>
char conv(char);

int main()
{
  //printf("%d\n", EOF);
  while(int c = getchar()){
    if(c == EOF)
      break;
   putchar(conv(c));
  }
  return 0;
}

char conv(char c)
{
  if(c >= '2' && c <= '9')
    return c-1;
  switch(c){
  case ' ':
    return ' ';
  case '1':
    return '`';
  case '0':
    return '9';
  case '-':
    return '0';
  case '=':
    return '-';
  case 'W':
    return 'Q';
  case 'E':
    return 'W';
  case 'R':
    return 'E';
  case 'T':
    return 'R';
  case 'Y':
    return 'T';
  case 'U':
    return 'Y';
  case 'I':
    return 'U';
  case 'O':
    return 'I';
  case 'P':
    return 'O';
  case '[':
    return 'P';
  case ']':
    return '[';
  case '\\':
    return ']';
  case 'S':
    return 'A';
  case 'D':
    return 'S';
  case 'F':
    return 'D';
  case 'G':
    return 'F';
  case 'H':
    return 'G';
  case 'J':
    return 'H';
  case 'K':
    return 'J';
  case 'L':
    return 'K';
  case ';' :
    return 'L';
  case '\'':
    return ';';
  case 'X':
    return 'Z';
  case 'C':
    return 'X';
  case 'V':
    return 'C';
  case 'B':
    return 'V';
  case 'N':
    return 'B';
  case 'M':
    return 'N';
  case ',':
    return 'M';
  case '.':
    return ',';
  case '/':
    return '.';
  case '\n':
    return '\n';
  }
  return 0;
}
