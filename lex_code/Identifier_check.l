%option noyywrap
%{
	#include<stdio.h>
%}

%%
[a-zA-Z_]+([a-zA-Z0-9_])*	{printf("valid identifier\n");}
.+				{printf("Invalid identifier\n");}
%%
int main()
{
	printf("Enter a identifier :");
	yylex();
	return 0;
}
