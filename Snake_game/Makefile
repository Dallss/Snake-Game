all: compile link run
	
compile:
	g++ -I"c:\Program Files (x86)\SFML\include" -c main.cpp functions.cpp

link:
	g++ main.o functions.o -o main -L"c:\Program Files (x86)\SFML\bin" -lsfml-graphics-2 -lsfml-window-2 -lsfml-system-2 -lsfml-audio-2

run:
	./main.exe
