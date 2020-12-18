%{
    #include <stdio.h>
%}

%union{
    int intval;
    double doubleval;
    char* strval;
}

// Starting symbol
%start <strval> program

//term symbol
%token  <strval> T_PROGRAM T_PROCEDURE T_CHAR T_ARRAY T_SET T_OF T_RECORD T_REAL T_READ T_VAR T_FORWARD T_FOR T_COMMENT
%token  <strval> T_FUNCTION T_INTEGER T_IF T_BOOLEAN T_BEGIN T_END T_ELSE T_TO T_THEN T_TYPE T_WHILE T_WITH T_WRITE
%token  <strval> T_DO T_DOWNTO T_CONST T_ID T_RELOP T_ADDOP T_OROP T_MULDIVANDOP T_NOTOP T_LPAREN T_RPAREN T_CCONST
%token  <strval> T_SEMI T_DOT T_DOTDOT T_COMMA T_EQU T_COLON T_ASSIGN T_LBRACK T_RBRACK T_EOF T_INOP T_BCONST T_STRINGS
%token  <intval> T_ICONST
%token  <doubleval> T_RCONST 

//  nonterm symbol
%type   <strval> header declarations subprograms comp_statement constdefs typedefs vardefs constant_defs expression
%type   <strval> variable constant setexpression elexpressions elexpression type_defs type_def dims limits limits
%type   <strval> typename standard_type fields field identifiers variable_defs subprogram sub_header formal_parameters
%type   <strval> parameter_list pass statements statement assignment if_statement if_tail while_statement for_statement
%type   <strval> iter_space with_statement subprogram_call io_statement read_list read_item write_list write_item

// associativity
%nonassoc T_INOP T_RELOP T_EQU // '='
%left T_ADDOP T_OROP
%left T_MULDIVANDOP
%left '.' '[]' '()'

