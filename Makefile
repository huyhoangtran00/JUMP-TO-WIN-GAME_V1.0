all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp Game.cpp  Object.cpp Map.cpp  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf