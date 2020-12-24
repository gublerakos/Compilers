/*Flex file to implement lectical analyser for pasc500.*/
/*Authors: Mizaras Fokion(2574), Pantazi-Kypraiou Maria(2596), Poulianou Xaidw(2613)*/
/*Date: 25/11/2020 */

%option case-insensitive
%option noyywrap

/* Libraries, declaration of variables and functions' prototypes. */
%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <math.h>
	#define MAX_SIZE 100
	#define MAX_ERRORS 5
	#define MAX_LINE_SIZE 100
	// #include "tokens.h"

	#include "syntaxAnalyser.tab.h"

	// Flag for EOF. 
	int eof = 0;

	// Counter for lines.
	int lines = 1;

	// Counter for errors. When MAX_ERRORS (= 5) is reached program terminates.
	int errors = 0;

	// Buffer to store strings.
	char str_buffer[MAX_SIZE];
	char *str_ptr;

	// Buffer to store whole input line to print in case of error.
	char line_buffer[MAX_LINE_SIZE];

	void yyerror(char* message);
	
	// File descriptor to opening file.
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

/************* ICONST VALUES *************/
BICONST (0B)[1][01]*
HICONST (0H)[A-F1-9][A-F0-9]*
ICONST 0|[1-9][0-9]*

/************* RCONST VALUES *************/
BRCONST [0][B][1][01]*\.[01]*
HRCONST [0][H][A-F0-9]*\.[0-9A-F]*
RCONST_EXP 0|([1-9][0-9]*)?\.(0|[1-9]+[0-9]*)E(0|[-+]?(0|[1-9]+[0-9]*))|(0|[1-9][0-9]*)E(0|[-+]?(0|[1-9]+[0-9]*))
RCONST_NOEXP 0|[1-9][0-9]*\.0|[1-9]*\.[1-9]+[0-9]*


/************* CCONST VALUES *************/
CCONST \'.\'|\'\\[nfrtv]\'

%x COMMENT
%x STRINGS

/************* KEYWORD VALUES *************/
%%
"PROGRAM" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_PROGRAM, lines);
	                    yylval.strval = strdup(yytext); return T_PROGRAM;}
"PROCEDURE" 			{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_PROCEDURE, lines);
	                    yylval.strval = strdup(yytext); return T_PROCEDURE;}
"CONST" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_CONST, lines);
                    	yylval.strval = strdup(yytext); return T_CONST;}
"CHAR" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_CHAR, lines);
	                    yylval.strval = strdup(yytext); return T_CHAR;}
"ARRAY" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ARRAY, lines);
	                    yylval.strval = strdup(yytext); return T_ARRAY;}
"SET" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_SET, lines);
	                    yylval.strval = strdup(yytext); return T_SET;}
"OF" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_OF, lines);
	                    yylval.strval = strdup(yytext); return T_OF;}

"RECORD" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RECORD, lines);
	                    yylval.strval = strdup(yytext); return T_RECORD;}
"REAL" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_REAL, lines);
	                    yylval.strval = strdup(yytext); return T_REAL;}
"READ" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_READ, lines);
	                    yylval.strval = strdup(yytext); return T_READ;}
"VAR" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_VAR, lines);
	                    yylval.strval = strdup(yytext); return T_VAR;}
"FORWARD" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_FORWARD, lines);
	                    yylval.strval = strdup(yytext); return T_FORWARD;}
"FOR" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_FOR, lines);
	                    yylval.strval = strdup(yytext); return T_FOR;}
"FUNCTION" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_FUNCTION, lines);
	                    yylval.strval = strdup(yytext); return T_FUNCTION;}

"INTEGER" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_INTEGER, lines);
                    	yylval.strval = strdup(yytext); return T_INTEGER;}
"IF" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_IF, lines);
	                    yylval.strval = strdup(yytext); return T_IF;}
"BOOLEAN" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BOOLEAN, lines);
	                    yylval.strval = strdup(yytext); return T_BOOLEAN;}
"BEGIN" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BEGIN, lines);
	                    yylval.strval = strdup(yytext); return T_BEGIN;}
"END" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_END, lines);
	                    yylval.strval = strdup(yytext); return T_END;}
"ELSE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ELSE, lines);
	                    yylval.strval = strdup(yytext); return T_ELSE;}
"THEN"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_THEN, lines);
	                    yylval.strval = strdup(yytext); return T_THEN;}

"TO"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_TO, lines);
	                    yylval.strval = strdup(yytext); return T_TO;}
"TYPE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_TYPE, lines);
	                    yylval.strval = strdup(yytext); return T_TYPE;}
"WRITE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_WRITE, lines);
	                    yylval.strval = strdup(yytext); return T_WRITE;}
"WHILE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_WHILE, lines);
	                    yylval.strval = strdup(yytext); return T_WHILE;}
"WITH"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_WITH, lines);
	                    yylval.strval = strdup(yytext); return T_WITH;}
"DO"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DO, lines);
	                    yylval.strval = strdup(yytext); return T_DO;}
"DOWNTO"				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DOWNTO, lines);
	                    yylval.strval = strdup(yytext); return T_DOWNTO;}

"TRUE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BCONST, lines);
	                    yylval.strval = strdup(yytext); return T_BCONST;}
"FALSE"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_BCONST, lines);
	                    yylval.strval = strdup(yytext); return T_BCONST;}
"OR"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_OROP, lines);
	                    yylval.strval = strdup(yytext); return T_OROP;}
"NOT"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_NOTOP, lines);
	                    yylval.strval = strdup(yytext); return T_NOTOP;}
"DIV"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    yylval.strval = strdup(yytext); return T_MULDIVANDOP;}
"MOD"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    yylval.strval = strdup(yytext); return T_MULDIVANDOP;}
"AND"					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    yylval.strval = strdup(yytext); return T_MULDIVANDOP;}
"IN"				    {printf("yytext = %s  and token = %d in line %d\n", yytext,   T_INOP, lines);
	                    yylval.strval = strdup(yytext); return T_INOP;}

{ID}					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ID, lines);
	                    yylval.strval = strdup(yytext); return T_ID;}
{ICONST}				{printf("yytext = %s => %d and token = %d in line %d\n", yytext, dec_to_int(yytext) , T_ICONST, lines);
	                    yylval.intval = dec_to_int(yytext); return T_ICONST;}
{BICONST}				{printf("yytext = %s => %d and token = %d in line %d\n", yytext, bin_to_int(yytext) , T_ICONST, lines);
	                    yylval.intval = bin_to_int(yytext); return T_ICONST;}
{HICONST}				{printf("yytext = %s => %d and token = %d in line %d\n", yytext, hex_to_int(yytext) , T_ICONST, lines);
	                    yylval.intval = hex_to_int(yytext); return T_ICONST;}
{RCONST_EXP}			{printf("yytext = %s => %lf and token = %d in line %d\n", yytext, dec_to_real(yytext), T_RCONST, lines);
	                    yylval.doubleval = dec_to_real(yytext); return T_RCONST;}
{RCONST_NOEXP}			{printf("yytext = %s =>% lf and token = %d in line %d\n", yytext, dec_to_real(yytext), T_RCONST, lines);
	                    yylval.doubleval = dec_to_real(yytext); return T_RCONST;}
{BRCONST}				{printf("yytext = %s => %lf and token = %d in line %d\n", yytext, bin_to_real(yytext), T_RCONST, lines);
	                    yylval.doubleval = bin_to_real(yytext); return T_RCONST;}
{HRCONST}				{printf("yytext = %s => %lf and token = %d in line %d\n", yytext, hex_to_real(yytext), T_RCONST, lines);
	                    yylval.doubleval = hex_to_real(yytext); return T_RCONST;}
{CCONST}				{printf("yytext = %s and token = %d in line %d\n", yytext,   T_CCONST, lines);
	                    yylval.strval = strdup(yytext); return T_CCONST;}

 /************* OPERATOR VALUES *************/

"*"|"/" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_MULDIVANDOP, lines);
	                    yylval.strval = strdup(yytext); return T_MULDIVANDOP;}

">="|">"|"<"|"<="|"<>" 	{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RELOP, lines);
	                    yylval.strval = strdup(yytext); return T_RELOP;}
"-"|"+" 				{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ADDOP, lines);
	                    yylval.strval = strdup(yytext); return T_ADDOP;}

 /************* OTHER VERBAL UNITS VALUES *************/						

"(" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_LPAREN, lines);
	                    yylval.strval = strdup(yytext); return T_LPAREN;}
")" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RPAREN, lines);
	                    yylval.strval = strdup(yytext); return T_RPAREN;}
";" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_SEMI, lines);
	                    yylval.strval = strdup(yytext); return T_SEMI;}
".." 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DOTDOT, lines);
                        yylval.strval = strdup(yytext); return T_DOTDOT;}
"."						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_DOT, lines);
	                    yylval.strval = strdup(yytext); return T_DOT;}
","						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_COMMA, lines);
	                    yylval.strval = strdup(yytext); return T_COMMA;}
":="					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_ASSIGN, lines);
	                    yylval.strval = strdup(yytext); return T_ASSIGN;}
"="						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_EQU, lines);
	                    yylval.strval = strdup(yytext); return T_EQU;}
":"						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_COLON, lines);
	                    yylval.strval = strdup(yytext); return T_COLON;}
"["						{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_LBRACK, lines);
	                    yylval.strval = strdup(yytext); return T_LBRACK;}
"]" 					{printf("yytext = %s  and token = %d in line %d\n", yytext,   T_RBRACK, lines);
	                    yylval.strval = strdup(yytext); return T_RBRACK;}
[\n] 					{if(!eof){error_line();} lines++;}


<INITIAL><<EOF>> 		{printf("EOF FOUND with token = %d in line %d\n", T_EOF, lines);
	                    return T_EOF;}

 /************* STATE FOR STRINGS AND SUBCASES *************/
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


 /************* STATE FOR COMMENTS AND SUBCASES *************/
"{"	BEGIN(COMMENT);
<COMMENT><<EOF>>		{yyerror("Unterminated comment"); yyterminate();}
<COMMENT>[^}\n]* 		{return T_COMMENT;}
<COMMENT>\n 			{if(!eof){error_line();} lines++; return T_COMMENT;}

<COMMENT>"}"			BEGIN(INITIAL);

{WHITESPACE}            {}
.						yyerror("Illegal token");

%%

// Function to increase number of errors, when found, and print the corresponding line.
void yyerror(char* message){
	errors++;
	printf("(#%d) errors \"%s\" at token  in line (%d): %s\n", errors, message, lines, line_buffer);
	if(errors == MAX_ERRORS){
		printf("MAX ERRORS detected!");
		exit(-1);
	}
}

// Function to store most recent line in "line_buffer".
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

// Main function that opens the file(given as argument) and reads it until EOF or MAX_ERRORS.
// int main(int argc, char* argv[]){
// 	int token;

// 	if(argc < 2){
// 		printf("No file given!");
// 		return(0);
// 	}

// 	fd = fopen(argv[1], "r");
	
// 	if(fd == NULL){
// 		perror("fopen");
// 		return -1;
// 	}
// 	fd_help = fopen(argv[1], "r");
// 	if(fd_help == NULL){
// 		perror("fopen");
// 		return -1;
// 	}
// 	error_line();
// 	yyset_in(fd_help);
// 	do{	
// 	 	token = yylex();
// 	} while(token != T_EOF);
    
// 	fclose(fd);
// 	fclose(fd_help);
// 	yyterminate();


// 	return(0);
// }

