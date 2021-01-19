%{
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtbl.h"
#include "data_types.h"
#include "ast.h"
#define MAX_STR_CONST 	200
#define MAX_LINE_SIZE	200
#define MAX_ERRORS		5

HASHTBL *hashtbl;

FILE *yyin2;

extern int yylex();
extern char *yytext;
//yyin, giati auto einai to default fd apo opou paei na diavasei h yylex
//gia allo onoma, to yyparse kollaei atermona, giati de ginetai linking me to yylex
extern FILE *yyin;
extern void error_line();

extern int errors;
char line_buffer[MAX_LINE_SIZE];
extern int lines;

extern char string_buf[MAX_STR_CONST];
extern char *str_ptr;
int scope = 1;

void yyerror(const char *message);
%}
%define parse.error verbose
%union{
    as_node* astval;
    s_node* sval;
    int intval;
    double doubleval;
    char* strval;
    bool boolval;
    char charval;
    Type typeval;
    operators opval;
    // data_t dataval;
    List* listval;
}
%start program

//term symbol
%token  <strval> T_PROGRAM T_PROCEDURE T_CHAR T_ARRAY T_SET T_OF T_RECORD T_REAL T_READ T_VAR T_FORWARD T_FOR T_COMMENT
%token  <strval> T_FUNCTION T_INTEGER T_IF T_BOOLEAN T_BEGIN T_END T_ELSE T_TO T_THEN T_TYPE T_WHILE T_WITH T_WRITE
%token  <strval> T_DO T_DOWNTO T_CONST T_ID T_RELOP T_ADDOP T_OROP T_MULDIVANDOP T_NOTOP T_LPAREN T_RPAREN T_CCONST
%token  <strval> T_SEMI T_DOT T_DOTDOT T_COMMA T_EQU T_COLON T_ASSIGN T_LBRACK T_RBRACK T_EOF T_INOP T_BCONST T_STRINGS
%token  <intval> T_ICONST
%token  <doubleval> T_RCONST 


// %type   <strval> header declarations subprograms comp_statement constdefs typedefs vardefs constant_defs expression
// %type   <strval> variable constant setexpression elexpressions elexpression type_defs type_def dims limits limit
// %type   <strval> typename standard_type fields field identifiers variable_defs subprogram sub_header formal_parameters
// %type   <strval> parameter_list pass statements statement assignment if_statement while_statement for_statement
// %type   <strval> iter_space with_statement subprogram_call io_statement read_list read_item write_list write_item expressions

//  nonterm symbol
%type   <strval> program header constdefs constant_defs typedefs subprograms subprogram formal_parameters pass 
%type   <strval> comp_statement iter_space
%type   <listval> declarations vardefs variable_defs parameter_list statements read_list write_list
%type   <astval> expression variable expressions constant elexpressions elexpression setexpression limits limit
%type   <astval> typename identifiers statement assignment if_statement while_statement for_statement read_item 
%type   <astval> io_statement write_item with_statement subprogram_call if_tail
%type   <typeval> standard_type
%type   <sval> type_defs type_def dims fields field sub_header 

// associativity
%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE
%nonassoc T_INOP T_RELOP T_EQU
%left T_ADDOP T_OROP
%left T_MULDIVANDOP
%left T_DOT T_LBRACK T_RBRACK T_LPAREN T_RPAREN
%left fake
%%

program             :header declarations subprograms                                    
                    comp_statement                                                      {hashtbl_get(hashtbl, scope);}
                    T_DOT                                                               {scope--;  hashtbl_get(hashtbl, scope);printf("Program ended with T_DOT.\n");}
                    ;
header              :T_PROGRAM T_ID T_SEMI                                              {printf("HEADER -> T_PROGRAM T_ID T_SEMI\n"); hashtbl_insert(hashtbl, $2, NULL, scope);}
                    |T_PROGRAM T_ID error                                               {hashtbl_insert(hashtbl, $2, NULL, scope); printf("HEADER -> T_PROGRAM T_ID\n"); printf("MISSING SEMI in header!\n"); }
                    ;
declarations        :constdefs typedefs vardefs                                         {printf("DECLARATIONS -> constdefs typedefs vardefs\n");}
                    ;
constdefs           :T_CONST constant_defs T_SEMI                                       {printf("CONSTDEFS -> T_CONST constant_defs T_SEMI\n");}
                    |T_CONST constant_defs error                                        {printf("CONSTDEFS -> T_CONST constant_defs\n"); printf("MISSING SEMI in constdefs!\n"); }
                    |/*empty*/                                                          {printf("constdefs -> empty\n");}
                    ;
constant_defs       :constant_defs T_SEMI T_ID                                          {hashtbl_insert(hashtbl, $3, NULL, scope); }
                    T_EQU expression                                                    {printf("CONSTANT_DEFS -> constant_defs T_SEMI T_ID T_EQU expression\n");}
                    |T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope);}
                    T_EQU expression                                                    {printf("CONSTANT_DEFS -> T_ID T_EQU expression\n");}             
                    |constant_defs error T_ID T_EQU expression                          {printf("MISSING SEMI in constant_defs!\n"); }
                    ;
expression          :expression T_RELOP expression                                      {printf("EXPRESSION -> expression T_RELOP expression\n");}                                          
                    |expression T_EQU expression                                        {printf("EXPRESSION -> expression T_EQU expression\n");}             
                    |expression T_INOP expression                                       {printf("EXPRESSION -> expression T_INOP expression\n");}             
                    |expression T_OROP expression                                       {printf("EXPRESSION -> expression T_OROP expression\n");}             
                    |expression T_ADDOP expression                                      {printf("EXPRESSION -> expression T_ADDOP expression\n");}             
                    |expression T_MULDIVANDOP expression                                {printf("EXPRESSION -> expression T_MULDIVANDOP expression\n");}             
                    |T_ADDOP expression                                                 {printf("EXPRESSION -> T_ADDOP expression\n");}             
                    |T_NOTOP expression %prec fake                                      {printf("EXPRESSION -> T_NOTOP expression\n");}             
                    |variable                                                           {printf("EXPRESSION -> variable\n");}             
                    |T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope); }
                    T_LPAREN expressions T_RPAREN                                       {printf("EXPRESSION -> T_LPAREN expressions T_RPAREN\n");}             
                    |constant                                                           {printf("EXPRESSION -> variable\n");}
                    |T_LPAREN expression T_RPAREN                                       {printf("EXPRESSION -> T_LPAREN expression T_RPAREN\n");}  
                    |setexpression                                                      {printf("EXPRESSION -> setexpression\n");}
                    |T_LPAREN expression error                                          {printf("EXPRESSION -> T_LPAREN expression\n"); printf("MISSING RPAREN in expression!\n"); }           
                    ;   
variable            :T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope); }
                    |variable T_DOT T_ID                                                {hashtbl_insert(hashtbl, $3, NULL, scope); printf("VARIABLE -> variable T_DOT T_ID\n");}
                    |variable T_LBRACK expressions T_RBRACK                             {printf("VARIABLE -> variable T_LBRACK expressions T_RBRACK\n");}
                    |variable T_LBRACK expressions error                                {printf("VARIABLE -> variable T_LBRACK expressions\n"); printf("MISSING RPAREN in variable!\n"); }
                    ;
expressions         :expressions T_COMMA expression                                     {printf("EXPRESSIONS -> expression T_COMMA expression\n");}
                    |expression                                                         {printf("EXPRESSIONS -> expression\n");}
                    ;
constant            :T_ICONST                                                           {printf("CONSTANT-> T_ICONST\n");}
                    |T_RCONST                                                           {printf("CONSTANT-> T_RCONST\n");}
                    |T_BCONST                                                           {printf("CONSTANT-> T_BCONST\n");}
                    |T_CCONST                                                           {printf("CONSTANT-> T_CCONST\n");}
                    ;
setexpression       :T_LBRACK elexpressions T_RBRACK                                    {printf("SETEXPRESSION -> T_LBRACK elexpressions T_RBRACK\n");}
                    |T_LBRACK error T_RBRACK                                            {printf("SETEXPRESSION -> T_LBRACK T_RBRACK\n"); printf("EMPTY BRACKETS BLOCK in setexpression!\n"); }
                    ;
elexpressions       :elexpressions T_COMMA elexpression                                 {printf("ELEXPRESSIONS -> elexpressions T_COMMA elexpression\n");}
                    |elexpression                                                       {printf("ELEXPRESSIONS -> elexpression\n");}
                    ;
elexpression        :expression T_DOTDOT expression                                     {printf("ELEXPRESSION -> expression T_DOTDOT expression\n");}
                    |expression                                                         {printf("ELEXPRESSION -> expression\n");}
                    ;
typedefs            :T_TYPE type_defs T_SEMI                                            {printf("TYPEDEFS -> T_TYPE type_defs T_SEMI\n");}
                    |T_TYPE type_defs error                                             {printf("TYPEDEFS -> T_TYPE type_defs\n"); printf("MISSING SEMI in typedefs!\n"); }
                    |/*empty*/                                                          {printf("typedefs -> empty\n");}
                    ;
type_defs           :type_defs T_SEMI T_ID                                              {hashtbl_insert(hashtbl, $3, NULL, scope); printf("TYPE_DEFS -> type_defs T_SEMI T_ID\n");}
                    T_EQU type_def                                                      {printf("TYPE_DEFS -> type_defs T_SEMI T_ID T_EQU type_def\n");}
                    |T_ID T_EQU type_def                                                {hashtbl_insert(hashtbl, $1, NULL, scope); printf("TYPE_DEFS -> T_ID T_EQU type_def\n");}
                    |type_defs error T_ID T_EQU type_def                                {printf("MISSING SEMI in type_defs!\n"); }
                    ;
type_def            :T_ARRAY T_LBRACK dims T_RBRACK T_OF typename                       {printf("TYPE_DEF -> T_ARRAY T_LBRACK dims T_RBRACK T_OF typename\n");}
                    |T_SET T_OF typename                                                {printf("TYPE_DEF -> T_SET T_OF typename\n");}
                    |T_RECORD fields T_END                                              {printf("TYPE_DEF -> T_RECORD fields T_END\n");}
                    |T_LPAREN identifiers T_RPAREN                                      {printf("TYPE_DEF -> T_LPAREN identifiers T_RPAREN\n");}
                    |limit T_DOTDOT limit                                               {printf("TYPE_DEF -> limit T_DOTDOT limit\n");}
                    |T_LPAREN identifiers error                                         {printf("TYPE_DEF -> T_LPAREN identifiers\n"); printf("MISSING RPAREN in type_def!\n"); }
                    |T_LPAREN error T_RPAREN                                            {printf("TYPE_DEF -> T_LPAREN T_RPAREN\n"); printf("EMPTY BRACKETS BLOCK in type_def!\n"); }                
                    ;
dims                :dims T_COMMA limits                                                {printf("DIMS -> dims T_COMMA limits\n");}
                    |limits                                                             {printf("DIMS -> limits\n");}
                    ;
limits              :limit T_DOTDOT limit                                               {printf("LIMITS -> limit T_DOTDOT limit\n");}
                    |T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope); printf("LIMITS -> T_ID\n");}
                    ;
limit               :T_ADDOP T_ICONST
                    |T_ADDOP T_ID
                    |T_ICONST                                                           {printf("CONSTANT -> T_ICONST\n");}
                    |T_CCONST                                                           {printf("CONSTANT -> T_CCONST\n");}
                    |T_BCONST                                                           {printf("CONSTANT -> T_BCONST\n");}
                    |T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope); printf("LIMIT -> T_ID\n");}
                    ;
typename            :standard_type                                                      {printf("TYPENAME -> standard_type\n");}
                    |T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope); printf("TYPENAME -> T_ID\n");}
                    ;
standard_type       :T_INTEGER                                                          {printf("STANDARD_TYPE -> T_INTEGER\n");}
                    |T_REAL                                                             {printf("STANDARD_TYPE -> T_REAL\n");}
                    |T_BOOLEAN                                                          {printf("STANDARD_TYPE -> T_BOOLEAN\n");}
                    |T_CHAR                                                             {printf("STANDARD_TYPE -> T_CHAR\n");}
                    ;
fields              :fields T_SEMI field                                                {printf("FIELDS -> fields T_SEMI field\n");}
                    |field                                                              {printf("FIELDS -> field\n");}
                    |fields error field                                                 {printf("MISSING SEMI in fields!\n"); }
                    ;
field               :identifiers T_COLON typename                                       {printf("FIELD -> identifiers T_COLON typename\n");}
                    ;
identifiers         :identifiers T_COMMA T_ID                                           {hashtbl_insert(hashtbl, $3, NULL, scope); printf("IDENTIFIERS -> identifiers T_COMMA T_ID\n");}
                    |T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope); printf("IDENTIFIERS -> T_ID\n");}
                    ;
vardefs             :T_VAR variable_defs T_SEMI                                         {printf("VARDEFS -> T_VAR variable_defs T_SEMI\n");}
                    |T_VAR variable_defs error                                          {printf("VARDEFS -> T_VAR variable_defs\n"); printf("MISSING SEMI in vardefs!\n"); }  
                    |/*empty*/                                                          {printf("VARDEFS -> empty\n");}
                    ;
variable_defs       :variable_defs T_SEMI identifiers T_COLON typename                  {printf("VARIABLE_DEFS -> variable_defs T_SEMI identifiers T_COLON typename\n");}
                    |variable_defs error identifiers T_COLON typename                   {printf("VARIABLE_DEFS -> variable_defs identifiers T_COLON typename\n"); printf("MISSING SEMI in variable_defs!\n"); }
                    |identifiers T_COLON typename                                       {printf("VARIABLE_DEFS -> identifiers T_COLON typename\n");}
                    ;
subprograms         :subprograms subprogram T_SEMI                                      {printf("SUBPROGRAMS -> subprograms subprogram T_SEMI\n");}
                    |/*empty*/                                                          {printf("SUBPROGRAMS -> empty\n");}
                    |subprograms subprogram error                                       {printf("SUBPROGRAMS -> subprograms subprogram\n"); printf("MISSING SEMI in subprograms!\n"); }
                    ;
subprogram          :sub_header T_SEMI T_FORWARD                                        {printf("SUBPROGRAM -> sub_header T_SEMI T_FORWARD\n"); hashtbl_get(hashtbl, scope); scope--;}
                    |sub_header T_SEMI declarations subprograms comp_statement          {printf("SUBPROGRAM -> sub_header T_SEMI declarations subprograms comp_statement\n");hashtbl_get(hashtbl, scope); scope--;}
                    |sub_header error T_FORWARD                                         {printf("SUBPROGRAM -> sub_header T_FORWARD\n"); hashtbl_get(hashtbl, scope); scope--; printf("MISSING SEMI in subprogram!\n"); }
                    |sub_header error declarations subprograms comp_statement           {printf("SUBPROGRAM -> sub_header declarations subprograms comp_statement\n"); printf("MISSING SEMI in subprogram!\n"); }
                    ;
sub_header          :T_FUNCTION T_ID                                                    {scope++; hashtbl_insert(hashtbl, $2, NULL, scope);}
                    formal_parameters T_COLON standard_type                             {printf("SUB_HEADER -> T_FUNCTION T_ID formal_parameters T_COLON standard_type\n");}
                    |T_PROCEDURE T_ID                                                   {scope++; hashtbl_insert(hashtbl, $2, NULL, scope);}
                    formal_parameters                                                   {printf("SUB_HEADER -> T_PROCEDURE T_ID formal_parameters\n");}
                    |T_FUNCTION T_ID                                                    {scope++; hashtbl_insert(hashtbl, $2, NULL, scope); printf("SUB_HEADER -> T_FUNCTION T_ID\n");}
                    ;
formal_parameters   :T_LPAREN parameter_list T_RPAREN                                   {printf("FORMAL_PARAMETERS -> T_LPAREN parameter_list T_RPAREN\n");}
                    |T_LPAREN error T_RPAREN                                            {printf("FORMAL_PARAMETERS -> T_LPAREN T_RPAREN\n"); printf("EMPTY BRACKETS BLOCK in formal_parameters!\n"); }
                    |/*empty*/                                                          {printf("FORMAL_PARAMETERS -> empty\n");}
                    ;
parameter_list      :parameter_list T_SEMI pass identifiers T_COLON typename            {printf("PARAMETER_LIST -> parameter_list T_SEMI pass identifiers T_COLON typename\n");}
                    |parameter_list error pass identifiers T_COLON typename             {printf("PARAMETER_LIST -> parameter_list pass identifiers T_COLON typename\n"); printf("MISSING SEMI in parameter_list!\n"); }
                    |pass identifiers T_COLON typename                                  {printf("PARAMETER_LIST -> pass identifiers T_COLON typename\n");}
                    ;
pass                :T_VAR                                                              {printf("PASS -> T_VAR\n");}
                    |/*empty*/                                                          {printf("PASS -> empty\n");}
                    ;
comp_statement      :T_BEGIN                                                            {scope++;}
                    statements T_END                                                    {hashtbl_get(hashtbl, scope); printf("COMP_STATEMENT -> T_BEGIN statements T_END\n"); scope--;}
                    ;
statements          :statements T_SEMI statement                                        {printf("STATEMENTS -> statements T_SEMI statement\n");}
                    |statement                                                          {printf("STATEMENTS -> statement\n");}
                    |statements error statement                                         {printf("STATEMENTS -> statements statement\n"); printf("MISSING SEMI in statements!\n"); }
                    ;
statement           :assignment                                                         {printf("STATEMENT -> assignment\n");}
                    |if_statement                                                       {printf("STATEMENT -> if_statement\n");}
                    |while_statement                                                    {printf("STATEMENT -> while_statement\n");}
                    |for_statement                                                      {printf("STATEMENT -> for_statement\n");}
                    |with_statement                                                     {printf("STATEMENT -> with_statement\n");}
                    |subprogram_call                                                    {printf("STATEMENT -> subprogram_call\n");}
                    |io_statement                                                       {printf("STATEMENT -> io_statement\n");}
                    |comp_statement                                                     {printf("STATEMENT -> comp_statement\n");}
                    |/*empty*/                                                          {printf("statement -> empty\n");}
                    ;
assignment          :variable T_ASSIGN expression                                       {printf("ASSIGNMENT -> variable T_ASSIGN expression\n");}
                    |variable T_ASSIGN T_STRINGS                                        {printf("ASSIGNMENT -> variable T_ASSIGN T_STRINGS\n");}
                    ;
                    
if_statement        :T_IF expression T_THEN statement if_tail                           {printf("IF_STATEMENT -> T_IF expression T_THEN statement if_tail\n");}
                    |T_IF expression error statement if_tail                            {printf("IF WITHOUT THEN!\n"); }
                    ;
if_tail             :T_ELSE statement                                                   {printf("IF_TAIL -> T_ELSE statement\n");}
                    |%prec LOWER_THAN_ELSE                                              {printf("IF_TAIL -> empty\n");}
                    ;
while_statement     :T_WHILE expression T_DO statement                                  {printf("WHILE_STATEMENT -> T_WHILE expression T_DO statement\n");}
                    ;
for_statement       :T_FOR                                                              
                    T_ID                                                                {hashtbl_insert(hashtbl, $1, NULL, scope);}
                    T_ASSIGN iter_space T_DO statement                                  {printf("FOR_STATEMENT -> T_FOR T_ID T_ASSIGN iter_space T_DO statement\n");}
                    ;
iter_space          :expression T_TO expression                                         {printf("ITER_SPACE -> expression T_TO expression\n");}
                    |expression T_DOWNTO expression                                     {printf("ITER_SPACE -> expression T_DOWNTO expression\n");}
                    ;
with_statement      :T_WITH variable T_DO statement                                     {printf("WITH_STATEMENT -> T_WITH variable T_DO statement\n");}
                    ;
subprogram_call     :T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope);}
                    |T_ID T_LPAREN                                                      {hashtbl_insert(hashtbl, $1, NULL, scope);}
                    expressions T_RPAREN                                                {printf("SUBPROGRAM_CALL -> T_ID T_LPAREN expressions T_RPAREN\n");}
                    ;  
io_statement        :T_READ T_LPAREN read_list T_RPAREN                                 {printf("IO_STATEMENT -> T_READ T_LPAREN read_list T_RPAREN\n");}
                    |T_WRITE T_LPAREN write_list T_RPAREN                               {printf("IO_STATEMENT -> T_WRITE T_LPAREN write_list T_RPAREN\n");}
                    |T_READ T_LPAREN read_list error                                    {printf("MISSING RPAREN in io_statement!\n"); }
                    |T_WRITE T_LPAREN write_list error                                  {printf("MISSING RPAREN in io_statement!\n"); }
                    ;
read_list           :read_list T_COMMA read_item                                        {printf("READ_LIST -> read_list T_COMMA read_item\n");}
                    |read_item                                                          {printf("READ_LIST -> read_item\n");}
                    ;
read_item           :variable                                                           {printf("READ_ITEM -> variable\n");}
                    ;
write_list          :write_list T_COMMA write_item                                      {printf("WRITE_LIST -> write_list T_COMMA write_item\n");}
                    |write_item                                                         {printf("WRITE_LIST -> write_item\n");}
                    ;
write_item          :expression                                                         {printf("WRITE_ITEM -> expression\n");}
                    |T_STRINGS                                                          {printf("WRITE_ITEM -> T_STRINGS\n");}
                    ;
%%

// Function to increase number of errors, when found, and print the corresponding line.
void yyerror(const char* message){
	errors++;
    
	printf("(#%d) errors \"%s\" in line (%d): %s<-\n", errors, message, lines-1, line_buffer);
	if(errors == MAX_ERRORS){
		printf("MAX ERRORS detected!");
		exit(-1);
	}
}


                    
// Main function that opens the file(given as argument) and reads it until EOF or MAX_ERRORS.
int main(int argc, char* argv[]){

	if(argc < 2){
		printf("No file given!");
		return(0);
	}

	yyin = fopen(argv[1], "r");
	
	if(yyin == NULL){
		perror("fopen");
		return -1;
	}
	yyin2 = fopen(argv[1], "r");
	if(yyin2 == NULL){
		perror("fopen");
		return -1;
	}
	

    hashtbl = hashtbl_create(5, NULL);
    if(hashtbl == NULL){
        fprintf(stderr, "HASHTBL CREATE ERROR\n");
        exit(-1);
    }

	yyparse();
    
    hashtbl_destroy(hashtbl);

	fclose(yyin);
	fclose(yyin2);

	return(0);

}



