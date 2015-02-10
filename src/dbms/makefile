all: main.o sql_relation.o
	g++ -std=c++11 sql_relation.o main.o -o main

sql_relation.o: sql_relation.cpp
	g++ -std=c++11 -c sql_relation.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
clean:
	rm *.o main

