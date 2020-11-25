all: lex.yy.c compiler

########################### compiler ###########################

compiler: 	lex.yy.c tokens.h
			gcc lex.yy.c -o compiler -lfl -lm

########################### lex.yy.c ###########################

lex.yy.c:	lecticalAnalyser.l tokens.h
			flex lecticalAnalyser.l