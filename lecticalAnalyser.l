%option case-insensitive
%option noyywrap
%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "tokens.h"

	int lines = 1;
	char str_buffer[MAX_SIZE];
	char *str_ptr;

	
%}
ID \_?[A-Z][A-Z0-9\_]*[A-Z0-9]|\_?[A-Z]
ICONST 0|[1-9][0-9]*|[0][H][A-F1-9][A-F0-9]*|[0][B][1][01]*
RCONST [0-9]*\.0|[0-9]*\.[1-9]+[0-9]*|[0-9]*\.[1-9]+[0-9]*E?[-+]?[1-9]+[0-9]*|[0-9]*\.[1-9]+[0-9]*E0|(0|[1-9][0-9]*)E[-+]*[-+]?[1-9]+[0-9]*|[0][H][A-F0-9]*\.[0-9A-F]*|[0][B][1][01]*.[01]*
CCONST \'.\'|\'\\[nfrtv]\'
%x COMMENT
%x STRINGS

%%
"PROGRAM" {return T_PROGRAM;}
"PROCEDURE" {return T_PROCEDURE;}
"CONST" {return T_CONST;}
"CHAR" {return T_CHAR;}
"ARRAY" {return T_ARRAY;}
"SET" {return T_SET;}
"OF" {return T_OF;}

"RECORD" {return T_RECORD;}
"REAL" {return T_REAL;}
"READ" {return T_READ;}
"VAR" {return T_VAR;}
"FORWARD" {return T_FORWARD;}
"FOR" {return T_FOR;}
"FUNCTION" {return T_FUNCTION;}

"INTEGER" {return T_INTEGER;}
"IF" {return T_IF;}
"BOOLEAN" {return T_BOOLEAN;}
"BEGIN" {return T_BEGIN;}
"END" {return T_END;}
"ELSE" {return T_ELSE;}
"THEN" {return T_THEN;}

"TO" {return T_TO;}
"TYPE" {return T_TYPE;}
"WRITE" {return T_WRITE;}
"WHILE" {return T_WHILE;}
"WITH" {return T_WITH;}
"DO" {return T_DO;}
"DOWNTO" {return T_DOWNTO;}

"TRUE" {return T_BCONST;}
"FALSE" {return T_BCONST;}
"OR" {return T_OROP;}
"NOT" {return T_NOTOP;}
"DIV" { return T_MULDIVANDOP;}
"MOD" { return T_MULDIVANDOP;}
"AND" { return T_MULDIVANDOP;}
"IN" { return T_INOP;}

{ID} {return T_ID;}
{ICONST} {return T_ICONST;}
{RCONST} {return T_RCONST;}
{CCONST} {return T_CCONST;}

"*"|"/" { return T_MULDIVANDOP;}

">="|">"|"<"|"<="|"<>" {return T_RELOP;}
"-"|"+" {return T_ADDOP;}

"(" {return T_LPAREN;}
")" {return T_RPAREN;}
";" {return T_SEMI;}
".." {return T_DOTDOT;}
"." {return T_DOT;}
"," {return T_COMMA;}
":=" {return T_ASSIGN;}
"=" {return T_EQU;}
":" {return T_COLON;}
"[" {return T_LBRACK;}
"]" {return T_RBRACK;}
[\n] {lines++;}


<<EOF>> {return T_EOF;}

\" {str_ptr = str_buffer; BEGIN(STRINGS);}
<STRINGS>\"		{BEGIN(INITIAL); *str_ptr = '\0'; printf("found:\"%s\"\n", str_buffer);}

<STRINGS>\n		{printf("error");}
<STRINGS>\\n	*str_ptr++ = '\n';
<STRINGS>\\t	*str_ptr++ = '\t';
<STRINGS>\\v	*str_ptr++ = '\v';
<STRINGS>\\f	*str_ptr++ = '\f';
<STRINGS>\\r	*str_ptr++ = '\r';
<STRINGS>\\b	*str_ptr++ = '\b';
<STRINGS>\\\n	lines++;

<STRINGS>[^\\\"\n]+		{char *helper = yytext;
						while(*helper){
							*str_ptr++ = *helper++;
						}}
<STRINGS>[\\]. 	*str_ptr++ = yytext[1];




"{"	BEGIN(COMMENT);
<COMMENT>[^}\n]* 	{return T_COMMENT;}
<COMMENT>\n 	{lines++; return T_COMMENT;}
<COMMENT>"}"	BEGIN(INITIAL);

%%

int main(int argc, char* argv[]){
	int token;

	do{
		token = yylex();
		if(token != T_STRINGS){
			printf("yytext = %s and token = %d in line %d\n", yytext, token, lines);
		}
	} while(token != T_EOF);

	printf("lines = %d\n", lines);

	return(0);
}

