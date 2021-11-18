MINESWEEPER_GAME: main.o minesweeper.o
	g++ -std=c++17 main.o minesweeper.o -o MINESWEEPER_GAME

main.o: main.cpp
	g++ -c -std=c++17 main.cpp 

minesweeper.o: minesweeper.cpp
	g++ -c -std=c++17 minesweeper.cpp

clean:
	rm *.o 