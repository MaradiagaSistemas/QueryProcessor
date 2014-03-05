%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */
 
#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"
 
int yyerror(SExpression **expression, yyscan_t scanner, const char *msg) {
    // Add error handling routine as needed
}
 
%}
 
%code requires {
 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
 
}
 
%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { SExpression **expression }
%parse-param { yyscan_t scanner }
 
%union {
    int value;
    SExpression *expression;
}
 

%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_ENTRE
%token TOKEN_MENOS
%token TOKEN_IGUAL
%token TOKEN_ASTERISCO
%token TOKEN_MAS
%token TOKEN_SELECT
%token TOKEN_INSERT
%token TOKEN_UPDATE
%token TOKEN_DELETE
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_SUM
%token TOKEN_AVG
%token TOKEN_MIN
%token TOKEN_MAX
%token TOKEN_COUNT
%token TOKEN_ALTER
%token TOKEN_ADD
%token TOKEN_COLUMN
%token TOKEN_DROP
%token TOKEN_CHANGE
%token TOKEN_NULL
%token TOKEN_NOT
%token TOKEN_DEFAULT
%token TOKEN_PRIMARY
%token TOKEN_FOREIGN
%token TOKEN_KEY
%token TOKEN_HAVING
%token TOKEN_GROUP
%token TOKEN_BY
%token TOKEN_INNER
%token TOKEN_JOIN
%token TOKEN_MAYORQUE
%token TOKEN_MENORQUE
%token TOKEN_MAYORIGUAL
%token TOKEN_MENORIGUAL
%token TOKEN_AS
%token TOKEN_WHERE
%token TOKEN_FROM
%token TOKEN_COMA
%token TOKEN_PUNTO
%token TOKEN_PUNTOCOMA
%token TOKEN_ON





%token <value> TOKEN_NUMBER
 
%type <expression> expr
 
%%
 
input
    : expr { *expression = $1; }
    ;
 
expr
    : TOKEN_LPAREN expr TOKEN_RPAREN { $$ = $2; }
    | TOKEN_NUMBER { $$ = createNumber($1); }
    ;
 
%%