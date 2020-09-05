CC = g++
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CFLAGS = -Wall -pedantic -ansi 
C11 = -std=c++11

new:
	make ED
ED: main.o ED.o
	$(CC) main.o ED.o -o ED $(CFLAGS) $(C11) $(SFML)
main.o: main.cpp ED.hpp
	$(CC) -c main.cpp -o main.o $(CFLAGS) $(C11)
ED.o:	ED.cpp ED.hpp
	$(CC) -c ED.cpp -o ED.o $(CFLAGS) $(C11)
clean:
	rm *.o
	rm *~
	rm ED
