%code requires{
    #include "ast.h"
}

%{

    #include <cstdio>
    using namespace std;
    int yylex();
    extern int yylineno;
    void yyerror(const char * s){
        fprintf(stderr, "Line: %d, error: %s\n", yylineno, s);
    }

    #define YYERROR_VERBOSE 1
%}

%union{
  float ftante;
  Expression * expr;
  const char * string_t;
  Declaration * decl;
}

%type<expr> EXPR
%type<expr> TERM
%type<expr> FACTOR

%token<ftante> FLOAT_T
%token<string_t> STRING
%token TOK_SUM
%token TOK_SUB
%token TOK_MUL
%token TOK_DIV
%token TOK_MAY
%token TOK_MEN
%token TOK_WHILE
%token TOK_ID
%token OP
%token EOL
%token ADD SUB MUL DIV WHILE DO DONE LET

%%
START: 
    |START EXPR EOL{ printf("\n"); }
    ;

EXPR: EXPR TOK_SUM TERM{$$= new AddExpression($1, $3); $$->evaluate(); }
    | EXPR TOK_SUB TERM{$$= new SubExpression($1, $3); $$->evaluate(); }
    | EXPR TOK_MAY TERM{$$= new MayExpression($1, $3); $$->evaluate(); }
    | EXPR TOK_MEN TERM{$$= new MenExpression($1, $3); $$->evaluate(); }
    | TERM{$$= $1;}
    ;

TERM: FACTOR{$$= $1;}
    | TERM TOK_MUL FACTOR{$$= new MulExpression($1, $3); $$->evaluate(); }
    | TERM TOK_DIV FACTOR{$$= new DivExpression($1, $3); $$->evaluate(); }
    ;

FACTOR: FLOAT_T {$$= new NumExpression($1); $$->evaluate(); }
    ;

%%
