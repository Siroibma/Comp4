CFLAGS = -Wall -Werror -ansi -pedantic
GFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CC = g++
C11 = -std=c++11
TEST = -lboost_unit_test_framework

new:
	make KSGuitarSim
KSGuitarSim: RingBuffer.o StringSound.o KSGuitarSim.o
	$(CC) RingBuffer.o StringSound.o KSGuitarSim.o -o KSGuitarSim $(GFLAGS) $(C11)
RingBuffer.o: RingBuffer.cpp RingBuffer.h
	$(CC) -c RingBuffer.cpp -o RingBuffer.o $(CFLAGS) $(C11)
StringSound.o: StringSound.cpp StringSound.h RingBuffer.h
	$(CC) -c StringSound.cpp -o StringSound.o  $(CFLAGS) $(C11)
KSGuitarSim.o: KSGuitarSim.cpp StringSound.h RingBuffer.h
	$(CC) -c KSGuitarSim.cpp -o KSGuitarSim.o  $(CFLAGS) $(C11)
clean:
	rm *.o ps4b
