%{
#include <stdio.h>
int ch_count = 0;
int line_count = 0;
%}

%%
\n      { line_count++; ch_count++; }
.       { ch_count++; }
%%

int main() {
    printf("Enter text (Press Ctrl+D on Linux or Ctrl+Z on Windows to stop):\n");
    yylex();
    printf("\nTotal Characters: %d\n", ch_count);
    printf("Total Lines: %d\n", line_count + 1);
    return 0;
}

int yywrap() {
    return 1;
}
