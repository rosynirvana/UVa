#include <cstdio>

int main()
{
	int c;
	bool conv = true;
	while(c = getchar()){
		if(c == EOF)
			break;
		if( c == '"'){
			if(conv){
				putchar('`');
				putchar('`');
				conv = false;
			}
			else{
				putchar('\'');
				putchar('\'');
				conv = true;
			}
		}
		else
			putchar(c);
	}
	return 0;
}