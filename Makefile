all: syntaxAnalyser.tab.c lex.yy.c compiler

########################### compiler ###########################
compiler: lex.yy.c syntaxAnalyser.tab.c hashtbl.o syntaxAnalyser.tab.h
			gcc syntaxAnalyser.tab.c lex.yy.c hashtbl.o -o compiler -lfl -lm

########################### lectical ###########################

lecticalAnalyser: 	lex.yy.c syntaxAnalyser.tab.h
			gcc lex.yy.c -o lecticalAnalyser -lfl -lm

########################### lex.yy.c ###########################

lex.yy.c:	lecticalAnalyser.l syntaxAnalyser.tab.h
			flex lecticalAnalyser.l

########################### syntax ###########################
syntaxAnalyser.tab.c: syntaxAnalyser.y
			bison -v -d syntaxAnalyser.y

########################### hashTable ###########################
hashtbl.o:	hashtbl.c hashtbl.h
			gcc -o hashtbl.o -Wall -g -c hashtbl.c