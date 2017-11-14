YACC = yacc -d
CFLAGS = -ll -o
CC = cc

parser: y.tab.c lex.yy.c stack.o
	$(CC) y.tab.c lex.yy.c $(CFLAGS) parser stack.o

y.tab.c: parser.y
	$(YACC) parser.y

lex.yy.c: scanner.l
	$(LEX) scanner.l

stack.o: stack.h stack.c
	$(CC) -c stack.c
