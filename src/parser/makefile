# Makefile: compiles the SQLParser. run with ./test or ./test < fillname
default:
	bison SQLParser.y
	flex SQLParser.l
	g++ -o test SQLParser.tab.c lex.yy.c
	
clean:
	rm -f *.o *~ SQLParser.c SQLParser.h SQLParser.c SQLParser.h test