%{
    #define YYSTYPE double
    #include <stdio.h>
    #include <math.h>
    #include "hashtbl.h"


    HASHTBL *hashtbl;
    int scope = 0;

    extern FILE* fd;
	extern FILE* fd_help;

    extern int yylex();
    // extern FILE *yyin;
    extern int yylineno;

    void yyerror(char* message);

%}

%union{
    int intval;
    double doubleval;
    char* strval;
}

// Starting symbol
%start program

//term symbol
%token  <strval> T_PROGRAM T_PROCEDURE T_CHAR T_ARRAY T_SET T_OF T_RECORD T_REAL T_READ T_VAR T_FORWARD T_FOR T_COMMENT
%token  <strval> T_FUNCTION T_INTEGER T_IF T_BOOLEAN T_BEGIN T_END T_ELSE T_TO T_THEN T_TYPE T_WHILE T_WITH T_WRITE
%token  <strval> T_DO T_DOWNTO T_CONST T_ID T_RELOP T_ADDOP T_OROP T_MULDIVANDOP T_NOTOP T_LPAREN T_RPAREN T_CCONST
%token  <strval> T_SEMI T_DOT T_DOTDOT T_COMMA T_EQU T_COLON T_ASSIGN T_LBRACK T_RBRACK T_EOF T_INOP T_BCONST T_STRINGS
%token  <intval> T_ICONST
%token  <doubleval> T_RCONST 

//  nonterm symbol
%type   <strval> header declarations subprograms comp_statement constdefs typedefs vardefs constant_defs expression
%type   <strval> variable constant setexpression elexpressions elexpression type_defs type_def dims limits limit
%type   <strval> typename standard_type fields field identifiers variable_defs subprogram sub_header formal_parameters
%type   <strval> parameter_list pass statements statement assignment if_statement while_statement for_statement
%type   <strval> iter_space with_statement subprogram_call io_statement read_list read_item write_list write_item expressions

// associativity
%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE
%nonassoc T_INOP T_RELOP T_EQU // '='
%left T_ADDOP T_OROP
%left T_MULDIVANDOP
%left T_DOT T_LBRACK T_RBRACK T_LPAREN T_RPAREN
%left fake
%%

program             :header declarations subprograms                                    {scope++;}
                    comp_statement                                                      {hashtbl_get(hashtbl, scope);}
                    T_DOT                                                               {scope--; printf("Program ended with T_DOT.\n");}
                    ;
header              :T_PROGRAM T_ID T_SEMI                                              {hashtbl_insert(hashtbl, $2, NULL, scope); printf("HEADER -> program id semi\n")}
                    ;
declarations        :constdefs typedefs vardefs                                         {printf("DECLARATIONS -> constdefs typedefs vardefs\n");}
                    ;
constdefs           :T_CONST constant_defs T_SEMI                                       {printf("CONSTDEFS -> T_CONST constant_defs T_SEMI\n");}
                    |/*empty*/                                                          {printf("constdefs -> empty\n");}
                    ;
constant_defs       :constant_defs T_SEMI T_ID                                          {hashtbl_insert(hashtbl, $3, NULL, scope); }
                    T_EQU expression                                                    {printf("CONSTANT_DEFS -> constant_defs T_SEMI T_ID T_EQU expression\n");}
                    |T_ID                                                               {hashtbl_insert(hashtbl, $1, NULL, scope); }
                    T_EQU expression                                                    {printf("CONSTANT_DEFS -> T_ID T_EQU expression\n");}             
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
                    |T_ID T_LPAREN                                                      {hashtbl_insert(hashtbl, $1, NULL, scope); }
                    expressions T_RPAREN                                                {printf("EXPRESSION -> T_LPAREN expression T_RPAREN\n");}             
                    |constant
                    |T_LPAREN expression T_RPAREN
                    |setexpression
                    ;
variable            :T_ID
                    |variable T_DOT T_ID
                    |variable T_LBRACK expressions T_RBRACK
                    ;
expressions         :expressions T_COMMA expression
                    |expression
                    ;
constant            :T_ICONST                                                           {printf("constant-> T_ICONST");}
                    |T_RCONST                                                           {printf("constant-> T_RCONST");}
                    |T_BCONST                                                           {printf("constant-> T_BCONST");}
                    |T_CCONST                                                           {printf("constant-> T_CCONST");}
                    ;
setexpression       :T_LBRACK elexpressions T_RBRACK
                    |T_LBRACK T_RBRACK
                    ;
elexpressions       :elexpressions T_COMMA elexpression
                    |elexpression
                    ;
elexpression        :expression T_DOTDOT expression
                    |expression
                    ;
typedefs            :T_TYPE type_defs T_SEMI
                    |/*empty*/                                                          {printf("typedefs -> empty\n");}
                    ;
type_defs           :type_defs T_SEMI T_ID T_EQU type_def
                    |T_ID T_EQU type_def
                    ;
type_def            :T_ARRAY T_LBRACK dims T_RBRACK T_OF typename
                    |T_SET T_OF typename
                    |T_RECORD fields T_END
                    |T_LPAREN identifiers T_RPAREN
                    |limit T_DOTDOT limit
                    ;
dims                :dims T_COMMA limits
                    |limits
                    ;
limits              :limit T_DOTDOT limit
                    |T_ID
                    ;
limit               :T_ADDOP T_ICONST
                    |T_ADDOP T_ID
                    |T_ICONST                                                           {printf("constant-> T_ICONST");}
                    |T_CCONST                                                           {printf("constant-> T_CCONST");}
                    |T_BCONST                                                           {printf("constant-> T_BCONST");}
                    |T_ID
                    ;
typename            :standard_type
                    |T_ID
                    ;
standard_type       :T_INTEGER
                    |T_REAL
                    |T_BOOLEAN
                    |T_CHAR
                    ;
fields              :fields T_SEMI field
                    |field
                    ;
field               :identifiers T_COLON typename
                    ;
identifiers         :identifiers T_COMMA T_ID
                    |T_ID
                    ;
vardefs             :T_VAR variable_defs T_SEMI
                    |/*empty*/                                                          {printf("vardefs -> empty\n");}
                    ;
variable_defs       :variable_defs T_SEMI identifiers T_COLON typename
                    |identifiers T_COLON typename
                    ;
subprograms         :subprograms subprogram T_SEMI
                    |/*empty*/                                                          {printf("subprograms -> empty\n");}
                    ;
subprogram          :sub_header T_SEMI T_FORWARD
                    |sub_header T_SEMI declarations subprograms comp_statement
                    ;
sub_header          :T_FUNCTION T_ID formal_parameters T_COLON standard_type
                    |T_PROCEDURE T_ID formal_parameters
                    |T_FUNCTION T_ID
                    ;
formal_parameters   :T_LPAREN parameter_list T_RPAREN
                    |/*empty*/                                                          {printf("formal_parameters -> empty\n");}
                    ;
parameter_list      :parameter_list T_SEMI pass identifiers T_COLON typename
                    |pass identifiers T_COLON typename
                    ;
pass                :T_VAR
                    |/*empty*/                                                          {printf("pass -> empty\n");}
                    ;
comp_statement      :T_BEGIN statements T_END
                    ;
statements          :statements T_SEMI statement
                    |statement
                    ;
statement           :assignment
                    |if_statement
                    |while_statement
                    |for_statement
                    |with_statement
                    |subprogram_call
                    |io_statement
                    |comp_statement
                    |/*empty*/                                                          {printf("statement -> empty\n");}
                    ;
assignment          :variable T_ASSIGN expression
                    |variable T_ASSIGN T_STRINGS
                    ;
                    
if_statement        :T_IF expression T_THEN statement T_ELSE statement
                    |T_IF expression T_THEN statement %prec LOWER_THAN_ELSE
                    ;

while_statement     :T_WHILE expression T_DO statement
                    ;
for_statement       :T_FOR T_ID T_ASSIGN iter_space T_DO statement
                    ;
iter_space          :expression T_TO expression
                    |expression T_DOWNTO expression
                    ;
with_statement      :T_WITH variable T_DO statement
                    ;
subprogram_call     :T_ID
                    |T_ID T_LPAREN expressions T_RPAREN
                    ;
io_statement        : T_READ T_LPAREN read_list T_RPAREN
                    |T_WRITE T_LPAREN write_list T_RPAREN
                    ;
read_list           :read_list T_COMMA read_item
                    |read_item
                    ;
read_item           :variable
                    ;
write_list          :write_list T_COMMA write_item
                    |write_item
                    ;
write_item          :expression
                    |T_STRINGS
                    ;
%%
                    
// Main function that opens the file(given as argument) and reads it until EOF or MAX_ERRORS.
int main(int argc, char* argv[]){

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
	

    hashtbl = hashtbl_create(5, NULL);
    if(hashtbl == NULL){
        fprintf(stderr, "HASHTBL CREATE ERROR\n");
        exit(-1);
    }

	yyparse();
    
    hashtbl_destroy(hashtbl);

	fclose(fd);
	fclose(fd_help);

	return(0);

}