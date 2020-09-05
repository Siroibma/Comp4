CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
OBJ = main.o PTree.o
SFML= -lsfml-graphics -lsfml-window -lsfml-system
#c11= -std=c++11
EXE = PTree 

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(SFML)
clean:
	rm *~ $(OBJ) $(EXE) *gch *.o

#tree: main.o PTree.o
#	$(CC) main.o PTree.o -o tree -lsfml-window -lsfml-graphics -lsfml-system $(c11) 
#main.o: main.cpp PTree.hpp
#	$(CC) main.cpp PTree.hpp -c $(CF)
#PTree.o: PTree.cpp PTree.hpp
#	$(CC) PTree.cpp PTree.hpp -c $(CF)
#clean:
#	rm *~
#	rm *.o
#	rm tree
#	rm *gch
