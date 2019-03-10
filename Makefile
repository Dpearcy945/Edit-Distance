CC = g++ -c
GG = g++
POST = -Wall -Werror -ansi -pedantic
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CLIENTS = app_maker
OBJECTS = editDistance.o main.o

all: $(CLIENTS) $(OBJECTS)

main.o: main.cpp
	$(CC) main.cpp $(POST)

editDistance.o: editDistance.cpp editDistance.hpp
	$(CC) editDistance.cpp $(POST)

app_maker: $(OBJECTS)
	$(GG) $(OBJECTS) -o ED $(SFLAGS)

clean:
	rm $(OBJECTS) ED