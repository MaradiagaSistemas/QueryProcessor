/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 18 "Parser.y"

 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
 


/* Line 2058 of yacc.c  */
#line 56 "Parser.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_LPAREN = 258,
     TOKEN_RPAREN = 259,
     TOKEN_ENTRE = 260,
     TOKEN_MENOS = 261,
     TOKEN_IGUAL = 262,
     TOKEN_ASTERISCO = 263,
     TOKEN_MAS = 264,
     TOKEN_SELECT = 265,
     TOKEN_INSERT = 266,
     TOKEN_UPDATE = 267,
     TOKEN_DELETE = 268,
     TOKEN_AND = 269,
     TOKEN_OR = 270,
     TOKEN_SUM = 271,
     TOKEN_AVG = 272,
     TOKEN_MIN = 273,
     TOKEN_MAX = 274,
     TOKEN_COUNT = 275,
     TOKEN_ALTER = 276,
     TOKEN_ADD = 277,
     TOKEN_COLUMN = 278,
     TOKEN_DROP = 279,
     TOKEN_CHANGE = 280,
     TOKEN_NULL = 281,
     TOKEN_NOT = 282,
     TOKEN_DEFAULT = 283,
     TOKEN_PRIMARY = 284,
     TOKEN_FOREIGN = 285,
     TOKEN_KEY = 286,
     TOKEN_HAVING = 287,
     TOKEN_GROUP = 288,
     TOKEN_BY = 289,
     TOKEN_INNER = 290,
     TOKEN_JOIN = 291,
     TOKEN_MAYORQUE = 292,
     TOKEN_MENORQUE = 293,
     TOKEN_MAYORIGUAL = 294,
     TOKEN_MENORIGUAL = 295,
     TOKEN_AS = 296,
     TOKEN_WHERE = 297,
     TOKEN_FROM = 298,
     TOKEN_COMA = 299,
     TOKEN_PUNTO = 300,
     TOKEN_PUNTOCOMA = 301,
     TOKEN_ON = 302,
     TOKEN_NUMBER = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 35 "Parser.y"

    int value;
    SExpression *expression;


/* Line 2058 of yacc.c  */
#line 125 "Parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (SExpression **expression, yyscan_t scanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */
