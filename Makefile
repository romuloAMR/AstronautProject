all: main
	./main
	rm main

main: Objects/main.o Objects/astronaut.o Objects/spacecraft.o Objects/fakedb.o
	g++ -Wall -o main Objects/main.o Objects/astronaut.o Objects/spacecraft.o Objects/fakedb.o

Objects/main.o: main.cpp
	g++ -Wall -c main.cpp
	mv main.o Objects/

Objects/astronaut.o: Implementations/astronaut.cpp Headers/astronaut.h
	g++ -Wall -c Implementations/astronaut.cpp
	mv astronaut.o Objects/

Objects/spacecraft.o: Implementations/spacecraft.cpp Headers/spacecraft.h
	g++ -Wall -c Implementations/spacecraft.cpp
	mv spacecraft.o Objects/

Objects/fakedb.o: Implementations/fakedb.cpp Headers/fakedb.h
	g++ -Wall -c Implementations/fakedb.cpp
	mv fakedb.o Objects/