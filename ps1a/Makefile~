CC  = g++
C4F = -Wall -Werror -pedantic -Werror
SFML = -lsfml-graphics -lsfml-window -lsfml-system
bst = -lboost_unit_test_framework
c11 = -std=c++11

all: ps1a
ps1a: FibLSFR.o test.o
	$(CC) FibLSFR.o test.o -o ps1a $(bst)
test.o: test.cpp FibLSFR.hpp
	$(CC) -c test.cpp FibLSFR.hpp $(C4F)
FibLSFR.o: FibLSFR.cpp FibLSFR.hpp
	$(CC) -c FibLSFR.cpp $(C4F)

clean:
	rm *.o *~ *gch ps1a
