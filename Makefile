GCC = g++
GXX = $(GCC)

STD = -std=c++11
FLAGS = -Wall
ifdef DEBUG
	FLAGS += -DDEBUG
endif

COMPILE = $(GXX) $(STD) $(FLAGS)

SRC = src
OBJ = obj
BUILDS = builds
TESTS = tests

all: main compile_tests

compile_tests: display_game

documentation:
	mkdir -p doc && cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

game_of_life.o: setup $(SRC)/game_of_life.h $(SRC)/game_of_life.cpp
	$(COMPILE) -c $(SRC)/game_of_life.cpp -o $(OBJ)/game_of_life.o

main: setup game_of_life.o labo_08_gachet_jean_gallay_david.cpp
	$(COMPILE) $(SRC)/game_of_life.h $(OBJ)/game_of_life.o labo_08_gachet_jean_gallay_david.cpp -o $(BUILDS)/labo08

# TESTS
display_game: $(TESTS)/display_game.cpp game_of_life.o
	$(COMPILE) src/game_of_life.h $(OBJ)/game_of_life.o $(TESTS)/display_game.cpp -o $(BUILDS)/display_game