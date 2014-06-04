
CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS= -lsfml-graphics -lsfml-window -lsfml-system 
SOURCES=main.cpp Planet.cpp Ship.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=Sol

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS)  -o $@
	rm $(OBJECTS)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
