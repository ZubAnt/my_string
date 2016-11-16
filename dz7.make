all: dz7

dz7: main.o my_string.o test.o
	g++ -std=c++11 main.o my_string.o test.o -o dz7.out
	rm -r *.o

main.o:
	g++ -std=c++11 -c main.cpp

my_string.o:
	g++ -std=c++11 -c ./lib/my_string.cpp

test.o:
	g++ -std=c++11 -c ./lib/test_my_string.cpp -o test.o
	
	
