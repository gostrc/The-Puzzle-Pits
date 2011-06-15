LIBS=-lsfml-audio -lsfml-graphics
CPPFLAGS=-Wall -Wextra -pedantic

tppxx: main.cpp Mouse.o
	g++ -o tppxx main.cpp Mouse.o $(LIBS) $(CPPFLAGS)

Mouse.o: Mouse.cpp Mouse.hpp
	g++ -c -o Mouse.o Mouse.cpp $(LIBS) $(CPPFLAGS)
