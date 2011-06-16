LIBS=-lsfml-audio -lsfml-graphics
CPPFLAGS=-Wall -Wextra -pedantic

tppxx: main.cpp GameVars.o Mouse.o
	g++ -o tppxx main.cpp GameVars.o Mouse.o $(LIBS) $(CPPFLAGS)

GameVars.o: GameVars.cpp GameVars.hpp
	g++ -c -o GameVars.o GameVars.cpp $(LIBS) $(CPPFLAGS)

Mouse.o: Mouse.cpp Mouse.hpp
	g++ -c -o Mouse.o Mouse.cpp $(LIBS) $(CPPFLAGS)

clean:
	rm -f tppxx GameVars.o Mouse.o
