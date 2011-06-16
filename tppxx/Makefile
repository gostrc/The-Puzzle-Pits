LIBS=-lsfml-audio -lsfml-graphics
CPPFLAGS=-Wall -Wextra -pedantic -std=c++0x

tppxx: main.cpp GameVars.cpp GameVars.hpp Mouse.cpp Mouse.hpp common.cpp common.hpp
	g++ -o tppxx main.cpp GameVars.cpp Mouse.cpp common.cpp $(LIBS) $(CPPFLAGS)

clean:
	rm -f tppxx
