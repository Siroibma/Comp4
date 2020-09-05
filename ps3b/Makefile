]CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
GFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
c11 = -std=c++11

new:	
	make NBody
NBody: particle.o main.o 
	g++ particle.o main.o -o NBody $(GFLAGS) $(c11)
particle.o: particle.cpp particle.hpp 
	g++ -c particle.cpp -o particle.o $(CFLAGS) $(c11)
main.o: main.cpp particle.hpp Universe.hpp
	g++ -c main.cpp -o main.o $(CFLAGS) $(c11)
clean:
	rm *.o *NBody *~
