%option case-insensitive
%option noyywrap
%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "tokens.h"

	int eof = 0;
	int lines = 1;
	int errors = 0;
	int error_type = -1;
	char str_buffer[MAX_SIZE];
	char line_buffer[MAX_LINE_SIZE];
	char *str_ptr;
	void yyerror(char* message);
	FILE* fd;
	FILE* fd_help;
	void error_line();
	
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
"]" 					{return T_RBRACK;}
[\n] 					{if(!eof){error_line();} lines++;}


<INITIAL><<EOF>> 				{return T_EOF;}

\"						{str_ptr = str_buffer; BEGIN(STRINGS);}
<STRINGS><<EOF>>			{yyerror("Unterminated string"); yyterminate();};
<STRINGS>\"				{BEGIN(INITIAL); *str_ptr = '\0'; printf("found:\"%s\"\n", str_buffer);}

<STRINGS>\n		 		yyerror("Newline in string");
<STRINGS>\\n			*str_ptr++ = '\n';
<STRINGS>\\t			*str_ptr++ = '\t';
<STRINGS>\\v			*str_ptr++ = '\v';
<STRINGS>\\f			*str_ptr++ = '\f';
<STRINGS>\\r			*str_ptr++ = '\r';
<STRINGS>\\b			*str_ptr++ = '\b';
<STRINGS>\\\n			{if(!eof){error_line();} lines++;}

<STRINGS>[^\\\"\n]+		{char *helper = yytext;
						while(*helper){
							*str_ptr++ = *helper++;
						}}
<STRINGS>[\\]. 			*str_ptr++ = yytext[1];


"{"	BEGIN(COMMENT);
<COMMENT><<EOF>>		{yyerror("Unterminated comment"); yyterminate();}
<COMMENT>[^}\n]* 		{return T_COMMENT;}
<COMMENT>\n 			{if(!eof){error_line();} lines++; return T_COMMENT;}

<COMMENT>"}"			BEGIN(INITIAL);

.						yyerror("Illegal token");

%%

void yyerror(char* message){
	errors++;
	printf("(#%d) errors \"%s\" at token  in line (%d): %s\n", errors, message, lines, line_buffer);
	if(errors == MAX_ERRORS){
		printf("MAX ERRORS detected!");
		exit(-1);
	}
}

void error_line(){
	char c;
	int i;

	for(i = 0; i < MAX_LINE_SIZE; i++){
		line_buffer[i] = '\0';
	}

	i = 0;
	while(1){
		c = fgetc(fd);
		if(feof(fd) || c == '\n'){
			break;
		}
		line_buffer[i] = c;
		i++;
	}



	if(feof(fd)){
		eof = 1;
	}

}

int main(int argc, char* argv[]){
	int token;

	if(argc < 2){
		printf("No file given!");
		return(0);
	}

	fd = fopen(argv[1], "r");
	
	if(fd == NULL){
		perror("fopen");
		return -1;
	}
	fd_help = fopen(argv[1], "r");
	if(fd_help == NULL){
		perror("fopen");
		return -1;
	}

	error_line();
	yyset_in(fd_help);
	do{	
		token = yylex();
		if(token != T_STRINGS){
			printf("yytext = %s and token = %d in line %d\n", yytext, token, lines);
		}
	} while(token != T_EOF);
	
	fclose(fd);
	fclose(fd_help);
	yyterminate();


	return(0);
}

