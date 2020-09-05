CC  = g++
C4F = -Wall -Werror -pedantic -Werror
SFML = -lsfml-graphics -lsfml-window -lsfml-system
c11 = -std=c++11

all: ps1b

ps1b: FibLSFR.o photomagic.o
	$(CC) FibLSFR.o photomagic.o -o ps1b $(SFML) $(c11)

photomagic.o: photomagic.cpp FibLSFR.hpp
	$(CC) -c photomagic.cpp FibLSFR.hpp $(C4F) 

FibLSFR.o: FibLSFR.cpp FibLSFR.hpp
	$(CC) -c FibLSFR.cpp FibLSFR.hpp $(C4F)

clean:
	rm *.o *~ *gch ps1b
	rm result.png
