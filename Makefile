CC = g++
CCFLAGSOBJ = -Wall -c
CCFLAGSEXEC = -Wall -static-libgcc -static-libstdc++
INCLUDE = -Ilibraries/include
SFML = -Llibraries/lib/SFML -lsfml-graphics -lsfml-window -lsfml-system -Llibraries/lib/Box2D -lBox2D

BUILDDIR = build

all: main.o Game.o Player.o GameObject.o
	$(CC) -o $(BUILDDIR)/GravityBox $(CCFLAGSEXEC) $? $(SFML)

main.o: main.cpp
	$(CC) $(CCFLAGSOBJ) $(INCLUDE) $^

Game.o: Game.cpp Game.hpp
	$(CC) $(CCFLAGSOBJ) $(INCLUDE) $^

Player.o: Player.cpp Player.hpp
	$(CC) $(CCFLAGSOBJ) $(INCLUDE) $^

GameObject.o: GameObject.cpp GameObject.hpp
	$(CC) $(CCFLAGSOBJ) $(INCLUDE) $^

.PHONY: clean
clean:
	rm *.o *.gch $(BUILDDIR)/GravityBox.exe