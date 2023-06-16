%{
#include<stdio.h>
#include<string.h>
int i = 0;
%}
%%
([a-zA-Z0-9])* {i++;}
"\n" {printf(" Total world is :%d\n", i); i = 0;}
%%

int yywrap(void){}

int main()
{
	printf("Enter a line :");
	yylex();

	return 0;
}
