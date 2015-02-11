all: main.o sql_relation.o sql_tuple.o sql_attribute.o sql_error_manager.o jsoncpp.o jsonfunc.o
	g++ -std=c++11 \
	sql_relation.o \
	sql_tuple.o \
	sql_attribute.o \
	sql_error_manager.o \
	jsoncpp.o \
	jsonfunc.o \
	main.o -o main

sql_relation.o: sql_relation.cpp
	g++ -std=c++11 -c sql_relation.cpp
	
sql_tuple.o: sql_tuple.cpp
	g++ -std=c++11 -c sql_tuple.cpp
		
sql_attribute.o: sql_attribute.cpp
	g++ -std=c++11 -c sql_attribute.cpp
	
sql_error_manager.o: sql_error_manager.cpp
	g++ -std=c++11 -c sql_error_manager.cpp	

jsoncpp.o: jsoncpp.cpp	
	g++ -std=c++11 -c jsoncpp.cpp

jsonfunc.o: jsonfunc.cpp	
	g++ -std=c++11 -c jsonfunc.cpp	
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
clean:
	rm *.o main

