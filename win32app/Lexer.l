%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
 
#include "Expression.h"
#include "Parser.h"
 
#include <stdio.h>
 
%}
 
%option outfile="Lexer.c" header-file="Lexer.h"
%option warn nodefault
 
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge


LPAREN      "("
RPAREN      ")"
ENTRE       "/"
MENOS		"-"	
IGUAL		"="
ASTERISCO	"*"
MAS         "+"
SELECT      "SELECT"
INSERT		"INSERT"
UPDATE      "UPDATE"
DELETE		"DELETE"
AND			"AND"
OR			"OR"
SUM			"SUM"
AVG			"AVG"
MIN			"MIN"
MAX			"MAX"
COUNT		"COUNT"
ALTER		"ALTER"
ADD			"ADD"
COLUMN		"COLUMN"
DROP		"DROP"
CHANGE		"CHANGE"
NULL		"NULL"
NOT			"NOT"
DEFAULT		"DEFAULT"
PRIMARY		"PRIMARY"
FOREIGN		"FOREIGN"
HAVING		"HAVING"
GROUP		"GROUP"
BY			"BY"
INNER		"INNER"
JOIN		"JOIN"
MAYORQUE	">"
MENORQUE	"<"
MAYORIGUAL	">="
MENORIGUAL	"<="
AS			"AS"
WHERE		"WHERE"
FROM		"FROM"
COMA		","
PUNTO		"."
PUNTOCOMA	";"
ON			"ON"


 
NUMBER      [0-9]+
WS          [ \r\n\t]*
 
%%
 
{WS}            { /* Skip blanks. */ }
{NUMBER}        { sscanf(yytext, "%d", &yylval->value); return TOKEN_NUMBER; }
 

{LPAREN}        { return TOKEN_LPAREN; }
{RPAREN}      { return TOKEN_RPAREN; }
{ENTRE}			{ return TOKEN_ENTRE;  }
{MENOS}			{ return TOKEN_MENOS;  }
{IGUAL}			{ return TOKEN_IGUAL;  }
{ASTERISCO}		{ return TOKEN_ASTERISCO;  }
{MAS}			{ return TOKEN_MAS;  }
{SELECT}		{ return TOKEN_SELECT;  }
{INSERT}		{ return TOKEN_INSERT;  }
{UPDATE}		{ return TOKEN_UPDATE;  }
{DELETE}		{ return TOKEN_DELETE;  }
{AND}			{ return TOKEN_ADD;  }
{OR}			{ return TOKEN_OR;  }
{SUM}			{ return TOKEN_SUM;  }
{AVG}			{ return TOKEN_AVG;  }
{MIN}			{ return TOKEN_MIN;  }
{MAX}			{ return TOKEN_MAX;  }
{COUNT}			{ return TOKEN_COUNT;  }
{ALTER}			{ return TOKEN_ALTER;  }
{ADD}			{ return TOKEN_ADD;  }
{COLUMN}		{ return TOKEN_COLUMN;  }
{DROP}			{ return TOKEN_DROP;  }
{CHANGE}		{ return TOKEN_CHANGE;  }
{NULL}			{ return TOKEN_NULL;  }
{NOT}			{ return TOKEN_NOT;  }
{DEFAULT}		{ return TOKEN_DEFAULT;  }
{PRIMARY}		{ return TOKEN_PRIMARY; }
{FOREIGN}		{ return TOKEN_FOREIGN; }
{HAVING}		{ return TOKEN_HAVING;  }
{GROUP}			{ return TOKEN_GROUP;   }
{BY}			{ return TOKEN_BY;   }
{INNER}			{ return TOKEN_INNER;   }
{JOIN}			{ return TOKEN_JOIN;  }
{MAYORQUE}		{ return TOKEN_MAYORQUE;  }
{MENORQUE}		{ return TOKEN_MENORQUE;  }
{MAYORIGUAL}	{ return TOKEN_MAYORIGUAL;  }
{MENORIGUAL}	{ return TOKEN_MENORIGUAL;  }
{AS}			{ return TOKEN_AS;  }
{WHERE}			{ return TOKEN_WHERE;   }
{FROM}			{ return TOKEN_FROM;  }
{COMA}			{ return TOKEN_COMA;   }
{PUNTO}			{ return TOKEN_PUNTO;  }
{PUNTOCOMA}		{ return TOKEN_PUNTOCOMA;  }
{ON}			{ return TOKEN_ON;  }



.               {  }
 
%%
 
int yyerror(const char *msg) {
    fprintf(stderr,"Error:%s\n",msg); return 0;
}