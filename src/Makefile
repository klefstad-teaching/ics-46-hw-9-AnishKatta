CXX = g++
CXXFLAGS = -ggdb -std=c++20 -Wall -Wextra -Wfatal-errors -pedantic

all: dijkstras_main

dijkstras_main: dijkstras_main.cpp dijkstras.o
	$(CXX) $(CXXFLAGS) dijkstras_main.cpp dijkstras.o -o dijkstras_main

ladder_main:ladder_main.cpp ladder.o dijkstras.o
	$(CXX) $(CXXFLAGS) ladder_main.cpp ladder.o dijkstras.o -o ladder_main

dijkstras.o: dijkstras.cpp dijkstras.h
	$(CXX) $(CXXFLAGS) -c dijkstras.cpp dijkstras.o

ladder.o: ladder.cpp ladder.h
	$(CXX) $(CXXFLAGS) -c ladder.cpp ladder.o

clean:
	rm -f dijkstras_main ladder_main *.o
