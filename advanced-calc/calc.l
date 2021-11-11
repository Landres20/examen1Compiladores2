%option noyywrap
%option yylineno

%{
    #include "tokens.h"

%}

DIGIT[0-9]

%%
"+" { return TOK_SUM; }
"=" { return '='; }
"-" { return TOK_SUB; }
"*" { return TOK_MUL; }
"/" { return TOK_DIV; }
"(" { return '('; }
")" { return ')'; }
"," { return ','; }
"." { return '.'; }
";" { return ';'; }
">" { return TOK_MAY; }
"<" { return TOK_MEN; }
"let" { return LET; }
"while" { return WHILE; }
"do" { return DO; }
"done" { return DONE; }

{DIGIT}+ { yylval.ftante = atof(yytext); return FLOAT_T; }
{DIGIT}+"."{DIGIT}+ { yylval.ftante = atof(yytext); return FLOAT_T; }
[a-zA-Z]+[a-zA-Z0-9]* { yylval.string_t = strdup(yytext); return STRING; }

[\n] { return EOL; }
[ \t] { /* ignorar */ }

. { printf("invalido %c\n", yytext[0]); }

%%


