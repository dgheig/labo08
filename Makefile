GCC = g++
GXX = $(GCC)

STD = -std=c++11
WARNING = -Wall

COMPILE = $(GXX) $(STD) $(WARNING)

OBJ = obj
BUILDS = builds
TESTS = tests

all: main compile_tests

compile_tests:

documentation:
	mkdir -p doc && cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

# delta_date.o: setup utilities.o src/constants.h src/delta_date.h src/delta_date.cpp
# 	$(COMPILE) -c src/delta_date.cpp -o $(OBJ)/delta_date.o

main: labo_08_gachet_jean_gallay_david.cpp
	$(COMPILE) labo_08_gachet_jean_gallay_david.cpp -o $(BUILDS)/labo08

# is_date_valid: $(TESTS)/is_date_valid.cpp utilities.o
# 	$(COMPILE) src/utilities.h $(OBJ)/utilities.o $(TESTS)/is_date_valid.cpp -o $(BUILDS)/is_date_valid