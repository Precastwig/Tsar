COMPILER=g++

items:
	@$(COMPILER) -std=c++11 -c src/robot.cpp -Iheaders/ -lsfml-graphics -o bin/robot.o
	@echo "Built robot.o"

tile: items
	@$(COMPILER) -std=c++11 -c src/tiles/tile.cpp -Iheaders/ -lsfml-graphics -lsfml-window -o bin/tile.o
	@echo "Built tile.o"
	@$(COMPILER) -std=c++11 -c src/tiles/grass.cpp -Iheaders/ -lsfml-graphics -o bin/grass.o
	@echo "Built grass.o"

board: tile
	@$(COMPILER) -std=c++11 -c src/board.cpp -Iheaders/ -o bin/board.o -lsfml-graphics -lsfml-window -lsfml-system
	@echo "Built board.o"

main: board
	@$(COMPILER) -std=c++11 -c src/main.cpp -Iheaders/ -o bin/main.o -lsfml-graphics -lsfml-window -lsfml-system
	@echo "Built main.o"

all: main
	@$(COMPILER) -std=c++11 bin/tile.o bin/grass.o bin/robot.o bin/board.o bin/main.o -o tsar -lsfml-graphics -lsfml-window -lsfml-system
	@echo "Linked all into tsar executable"

clean:
	rm -rf bin/*
	rm -rf headers/*.gch
