CFLAGS = -Wall -Werror -ansi -pedantic
CC = g++
C11 = -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TEST = -lboost_unit_test_framework

new:
	make ps6
	make test
ps6: MModel.o Textgenerator.o
	$(CC) MModel.o Textgenerator.o -o ps6 $(C11)
test: test.o MModel.o
	$(CC) test.o MModel.o -o test $(C11) $(TEST)
MModel.o: MModel.cpp MModel.h
	$(CC) -c MModel.cpp -o MModel.o $(CFLAGS) $(C11)
test.o: test.cpp MModel.h 
	$(CC) -c test.cpp -o test.o  $(CFLAGS) $(C11)
Textgenerator.o: Textgenerator.cpp MModel.h
	$(CC) -c Textgenerator.cpp -o Textgenerator.o $(CFLAGS) $(C11)
clean:
	rm *~ *.o ps6 test
