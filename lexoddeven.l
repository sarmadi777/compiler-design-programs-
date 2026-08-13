%{
#include <stdio.h>
#include <stdlib.h>
int num;
%}

%%
[0-9]+ {
    num = atoi(yytext);
    if (num % 2 == 0)
        printf("Even Number\n");
    else
        printf("Odd Number\n");
}
.|\n   { /* Ignore other characters or whitespace */ }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a number: ");
    yylex();
    return 0;
}
