all: lex.yy.c lecticalAnalyser

########################### compiler ###########################

lecticalAnalyser: 	lex.yy.c tokens.h
			gcc lex.yy.c -o lecticalAnalyser -lfl -lm

########################### lex.yy.c ###########################

lex.yy.c:	lecticalAnalyser.l tokens.h
			flex lecticalAnalyser.l