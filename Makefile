GCC = g++
GXX = $(GCC)

STD = -std=c++11
FLAGS = -Wall
ifdef DEBUG
	FLAGS += -DDEBUG
endif

SFML = -lsfml-graphics -lsfml-window -lsfml-system

COMPILE = $(GXX) $(STD) $(FLAGS)

SRC = src
OBJ = obj
BUILDS = builds
TESTS = tests

all: labo08 compile_tests

main: labo08

compile_tests: display_game compute_multiple_gens

documentation:
	mkdir -p doc && cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

game_of_life.o: setup $(SRC)/game_of_life.h $(SRC)/game_of_life.cpp
	$(COMPILE) -c $(SRC)/game_of_life.cpp -o $(OBJ)/game_of_life.o

labo08.o: setup game_of_life.o labo_08_gachet_jean_gallay_david.cpp
	$(COMPILE) -c labo_08_gachet_jean_gallay_david.cpp -o $(OBJ)/labo08.o

labo08: setup game_of_life.o labo08.o
	$(COMPILE) $(SRC)/game_of_life.h $(OBJ)/game_of_life.o $(OBJ)/labo08.o -o $(BUILDS)/labo08

# TESTS
display_game: $(TESTS)/display_game.cpp game_of_life.o
	$(COMPILE) src/game_of_life.h $(OBJ)/game_of_life.o $(TESTS)/display_game.cpp -o $(BUILDS)/display_game

compute_multiple_gens: $(TESTS)/compute_multiple_gens.cpp game_of_life.o
	$(COMPILE) src/game_of_life.h $(OBJ)/game_of_life.o $(TESTS)/compute_multiple_gens.cpp -o $(BUILDS)/compute_multiple_gens

# EXTRA

sfml.o: extra/sfml.cpp
	$(COMPILE) -c extra/sfml.cpp -o $(OBJ)/sfml.o

sfml: setup game_of_life.o sfml.o
	$(COMPILE) $(SRC)/game_of_life.h $(OBJ)/game_of_life.o $(OBJ)/sfml.o -o $(BUILDS)/sfml $(SFML)