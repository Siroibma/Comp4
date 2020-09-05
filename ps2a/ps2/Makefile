CC = g++
SFML= -lsfml-graphics -lsfml-window -lsfml-system
c11= -std=c++11
CF = -Wall -Werror -pedantic -Wextra 


tree: main.o
	$(CC) main.o -o tree -lsfml-window -lsfml-graphics -lsfml-system $(c11) 
main.o: main.cpp
	$(CC) main.cpp -c $(CF)
clean:
	rm *~
	rm *gch
