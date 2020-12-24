/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAXANALYSER_TAB_H_INCLUDED
# define YY_YY_SYNTAXANALYSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_PROGRAM = 258,               /* T_PROGRAM  */
    T_PROCEDURE = 259,             /* T_PROCEDURE  */
    T_CHAR = 260,                  /* T_CHAR  */
    T_ARRAY = 261,                 /* T_ARRAY  */
    T_SET = 262,                   /* T_SET  */
    T_OF = 263,                    /* T_OF  */
    T_RECORD = 264,                /* T_RECORD  */
    T_REAL = 265,                  /* T_REAL  */
    T_READ = 266,                  /* T_READ  */
    T_VAR = 267,                   /* T_VAR  */
    T_FORWARD = 268,               /* T_FORWARD  */
    T_FOR = 269,                   /* T_FOR  */
    T_COMMENT = 270,               /* T_COMMENT  */
    T_FUNCTION = 271,              /* T_FUNCTION  */
    T_INTEGER = 272,               /* T_INTEGER  */
    T_IF = 273,                    /* T_IF  */
    T_BOOLEAN = 274,               /* T_BOOLEAN  */
    T_BEGIN = 275,                 /* T_BEGIN  */
    T_END = 276,                   /* T_END  */
    T_ELSE = 277,                  /* T_ELSE  */
    T_TO = 278,                    /* T_TO  */
    T_THEN = 279,                  /* T_THEN  */
    T_TYPE = 280,                  /* T_TYPE  */
    T_WHILE = 281,                 /* T_WHILE  */
    T_WITH = 282,                  /* T_WITH  */
    T_WRITE = 283,                 /* T_WRITE  */
    T_DO = 284,                    /* T_DO  */
    T_DOWNTO = 285,                /* T_DOWNTO  */
    T_CONST = 286,                 /* T_CONST  */
    T_ID = 287,                    /* T_ID  */
    T_RELOP = 288,                 /* T_RELOP  */
    T_ADDOP = 289,                 /* T_ADDOP  */
    T_OROP = 290,                  /* T_OROP  */
    T_MULDIVANDOP = 291,           /* T_MULDIVANDOP  */
    T_NOTOP = 292,                 /* T_NOTOP  */
    T_LPAREN = 293,                /* T_LPAREN  */
    T_RPAREN = 294,                /* T_RPAREN  */
    T_CCONST = 295,                /* T_CCONST  */
    T_SEMI = 296,                  /* T_SEMI  */
    T_DOT = 297,                   /* T_DOT  */
    T_DOTDOT = 298,                /* T_DOTDOT  */
    T_COMMA = 299,                 /* T_COMMA  */
    T_EQU = 300,                   /* T_EQU  */
    T_COLON = 301,                 /* T_COLON  */
    T_ASSIGN = 302,                /* T_ASSIGN  */
    T_LBRACK = 303,                /* T_LBRACK  */
    T_RBRACK = 304,                /* T_RBRACK  */
    T_EOF = 305,                   /* T_EOF  */
    T_INOP = 306,                  /* T_INOP  */
    T_BCONST = 307,                /* T_BCONST  */
    T_STRINGS = 308,               /* T_STRINGS  */
    T_ICONST = 309,                /* T_ICONST  */
    T_RCONST = 310,                /* T_RCONST  */
    LOWER_THAN_ELSE = 311,         /* LOWER_THAN_ELSE  */
    fake = 312                     /* fake  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "syntaxAnalyser.y"

    int intval;
    double doubleval;
    char* strval;

#line 127 "syntaxAnalyser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAXANALYSER_TAB_H_INCLUDED  */
