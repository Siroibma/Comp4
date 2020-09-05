CFLAGS = -Wall -Werror -ansi -pedantic
CC = g++
C11 = -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TEST = -lboost_unit_test_framework

new:
	make ps4a
ps4a: RingBuffer.o main.o
	$(CC) RingBuffer.o main.o -o ps4a $(C11) $(SFML)
main.o: main.cpp RingBuffer.h
	$(CC) -c main.cpp -o main.o $(C4F)
RingBuffer.o: RingBuffer.cpp RingBuffer.h
	$(CC) -c RingBuffer.cpp -o RingBuffer.o $(CFLAGS) $(C11)
StringSound.o: StringSound.cpp StringSound.h RingBuffer.h
	$(CC) -c StringSound.cpp -o StringSound.o  $(CFLAGS) $(C11)
clean:
	rm *~ *.o ps4a
