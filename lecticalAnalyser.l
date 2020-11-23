%option case-insensitive
%option noyywrap
%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <math.h>
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

	// yytext conversion from string to int
	int dec_to_int(char* str);
	int hex_to_int(char* str);
	int bin_to_int(char*str);

	// yytext conversion from string to int
	double dec_to_real(char* str);
	double hex_to_real(char* str);
	double bin_to_real(char*str);
%}
WHITESPACE [ \t]*
ID \_?[A-Z][A-Z0-9\_]*[A-Z0-9]|\_?[A-Z]
/******         ICONST VALUES ******************/

BICONST (0B)[1][01]*
HICONST (0H)[A-F1-9][A-F0-9]*
ICONST 0|[1-9][0-9]*
/******         RCONST VALUES ******************/
BRCONST [0][B][1][01]*\.[01]*
HRCONST [0][H][A-F0-9]*\.[0-9A-F]*
RCONST_EXP 0|([1-9][0-9]*)?\.(0|[1-9]+[0-9]*)E(0|[-+]?(0|[1-9]+[0-9]*))|(0|[1-9][0-9]*)E(0|[-+]?(0|[1-9]+[0-9]*))
RCONST_NOEXP 0|[1-9][0-9]*\.0|[1-9]*\.[1-9]+[0-9]*



CCONST \'.\'|\'\\[nfrtv]\'
%x COMMENT
%x STRINGS

%%
"PROGRAM" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_PROGRAM, lines);
	                    return T_PROGRAM;}
"PROCEDURE" 			{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_PROCEDURE, lines);
	                    return T_PROCEDURE;}
"CONST" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_CONST, lines);
                    	return T_CONST;}
"CHAR" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_CHAR, lines);
	                    return T_CHAR;}
"ARRAY" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ARRAY, lines);
	                    return T_ARRAY;}
"SET" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_SET, lines);
	                    return T_SET;}
"OF" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_OF, lines);
	                    return T_OF;}

"RECORD" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RECORD, lines);
	                    return T_RECORD;}
"REAL" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_REAL, lines);
	                    return T_REAL;}
"READ" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_READ, lines);
	                    return T_READ;}
"VAR" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_VAR, lines);
	                    return T_VAR;}
"FORWARD" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_FORWARD, lines);
	                    return T_FORWARD;}
"FOR" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_FOR, lines);
	                    return T_FOR;}
"FUNCTION" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_FUNCTION, lines);
	                    return T_FUNCTION;}

"INTEGER" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_INTEGER, lines);
                    	return T_INTEGER;}
"IF" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_IF, lines);
	                    return T_IF;}
"BOOLEAN" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BOOLEAN, lines);
	                    return T_BOOLEAN;}
"BEGIN" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BEGIN, lines);
	                    return T_BEGIN;}
"END" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_END, lines);
	                    return T_END;}
"ELSE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ELSE, lines);
	                    return T_ELSE;}
"THEN"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_THEN, lines);
	                    return T_THEN;}

"TO"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_TO, lines);
	                    return T_TO;}
"TYPE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_TYPE, lines);
	                    return T_TYPE;}
"WRITE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_WRITE, lines);
	                    return T_WRITE;}
"WHILE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_WHILE, lines);
	                    return T_WHILE;}
"WITH"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_WITH, lines);
	                    return T_WITH;}
"DO"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DO, lines);
	                    return T_DO;}
"DOWNTO"				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DOWNTO, lines);
	                    return T_DOWNTO;}

"TRUE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BCONST, lines);
	                    return T_BCONST;}
"FALSE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BCONST, lines);
	                    return T_BCONST;}
"OR"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_OROP, lines);
	                    return T_OROP;}
"NOT"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_NOTOP, lines);
	                    return T_NOTOP;}
"DIV"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    return T_MULDIVANDOP;}
"MOD"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    return T_MULDIVANDOP;}
"AND"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    return T_MULDIVANDOP;}
"IN"				    {printf("yytext = %s  and token = %d in line %d\n", yytext,   T_INOP, lines);
	                    return T_INOP;}

{ID}					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ID, lines);
	                    return T_ID;}
{ICONST}				{printf("yytext = %s => %d and token = %d in line %d\n", yytext, dec_to_int(yytext) , T_ICONST, lines);
	                    return T_ICONST;}
{BICONST}				{printf("yytext = %s => %d and token = %d in line %d\n", yytext, bin_to_int(yytext) , T_ICONST, lines);
	                    return T_ICONST;}
{HICONST}				{printf("yytext = %s => %d and token = %d in line %d\n", yytext, hex_to_int(yytext) , T_ICONST, lines);
	                    return T_ICONST;}
{RCONST_EXP}				{printf("yytext = %s => %lf and token = %d in line %d\n", yytext, dec_to_real(yytext), T_RCONST, lines);
	                    return T_RCONST;}
{RCONST_NOEXP}				{printf("yytext = %s =>% lf and token = %d in line %d\n", yytext, dec_to_real(yytext), T_RCONST, lines);
	                    return T_RCONST;}
{BRCONST}				{printf("yytext = %s => %lf and token = %d in line %d\n", yytext, bin_to_real(yytext), T_RCONST, lines);
	                    return T_RCONST;}
{HRCONST}				{printf("yytext = %s => %lf and token = %d in line %d\n", yytext, hex_to_real(yytext), T_RCONST, lines);
	                    return T_RCONST;}
{CCONST}				{printf("yytext = %s and token = %d in line %d\n", yytext,   T_CCONST, lines);
	                    return T_CCONST;}

"*"|"/" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    return T_MULDIVANDOP;}

">="|">"|"<"|"<="|"<>" 	{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RELOP, lines);
	                    return T_RELOP;}
"-"|"+" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ADDOP, lines);
	                    return T_ADDOP;}

"(" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_LPAREN, lines);
	                    return T_LPAREN;}
")" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RPAREN, lines);
	                    return T_RPAREN;}
";" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_SEMI, lines);
	                    return T_SEMI;}
".." 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DOTDOT, lines);
                        return T_DOTDOT;}
"."						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DOT, lines);
	                    return T_DOT;}
","						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_COMMA, lines);
	                    return T_COMMA;}
":="					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ASSIGN, lines);
	                    return T_ASSIGN;}
"="						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_EQU, lines);
	                    return T_EQU;}
":"						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_COLON, lines);
	                    return T_COLON;}
"["						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_LBRACK, lines);
	                    return T_LBRACK;}
"]" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RBRACK, lines);
	                    return T_RBRACK;}
[\n] 					{if(!eof){error_line();} lines++;}


<INITIAL><<EOF>> 		{printf("EOF FOUND with token = %d in line %d\n", T_EOF, lines);
	                    return T_EOF;}

\"						{str_ptr = str_buffer; BEGIN(STRINGS);}
<STRINGS><<EOF>>		{yyerror("Unterminated string"); yyterminate();}
<STRINGS>\"				{BEGIN(INITIAL); *str_ptr = '\0'; 
                        printf("String = %s  and token = %d in line %d\n", str_buffer,  T_STRINGS, lines);}
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

{WHITESPACE}            {}
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

// INT
int dec_to_int(char* str){
	return(atoi(str));
}
int hex_to_int(char* str){
	return((int)strtol(&str[2], NULL, 16));
}
int bin_to_int(char* str){
	return((int)strtol(&str[2], NULL, 2));
}

// REAL
double dec_to_real(char* str){
  return atof(str);
}
double hex_to_real(char* str){
	double res;
	int i, length_real;
	char* c;
	
	c = strchr(str, '.');
	length_real = strlen(c) - 1;
	res = (int)strtol(&str[2], &c, 16);

	for(i = 1; i <= length_real; i++){
		if(c[i] > '9' && c[i] < 'G')
			res = (c[i] - 'A')*(1/pow(16, i)) + res;
		else
			res = (c[i] - '0')*(1/pow(16, i)) + res;
	}

	return(res);
}
double bin_to_real(char* str){
	double res;
	int i, length_real;
	char *c;
	
	c = strchr(str, '.');
    length_real = strlen(c) - 1;
	res = (int)strtol(&str[2],  &c, 2);
	for(i = 1; i <= length_real; i++){
		res = (c[i] - '0')*(1/pow(2, i)) + res;
	}

	return(res);
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
	} while(token != T_EOF);
    
	//token = yylex();
    //token = yylex();
    //printf("%s, %d, %d", yytext, bin_to_int(yytext), token);
	fclose(fd);
	fclose(fd_help);
	yyterminate();


	return(0);
}

