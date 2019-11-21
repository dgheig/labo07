GCC = g++
GXX = $(GCC)

STD = -std=c++11
WARNING = -Wall

COMPILE = $(GXX) $(STD) $(WARNING)

OBJ = obj
BUILDS = builds
TESTS = tests

all: main compile_tests

compile_tests: is_date_valid is_leap_year check_date_order days_between_dates

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

interface.o: setup src/interface.h src/interface.cpp
	$(COMPILE) -c src/interface.cpp -o $(OBJ)/interface.o

utilities.o: setup src/utilities.h src/utilities.cpp src/constants.h
	$(COMPILE) -c src/utilities.cpp -o $(OBJ)/utilities.o

delta_date.o: setup utilities.o src/constants.h src/delta_date.h src/delta_date.cpp
	$(COMPILE) -c src/delta_date.cpp -o $(OBJ)/delta_date.o

main: labo_07_schaufelberger_yannick_gallay_david.cpp utilities.o delta_date.o interface.o
	$(COMPILE) src/delta_date.h src/utilities.h src/interface.h $(OBJ)/utilities.o $(OBJ)/delta_date.o $(OBJ)/interface.o labo_07_schaufelberger_yannick_gallay_david.cpp -o $(BUILDS)/labo07

is_date_valid: $(TESTS)/is_date_valid.cpp utilities.o
	$(COMPILE) src/utilities.h $(OBJ)/utilities.o $(TESTS)/is_date_valid.cpp -o $(BUILDS)/is_date_valid

is_leap_year: $(TESTS)/is_leap_year.cpp utilities.o
	$(COMPILE) src/utilities.h $(OBJ)/utilities.o $(TESTS)/is_leap_year.cpp -o $(BUILDS)/is_leap_year

check_date_order: $(TESTS)/check_date_order.cpp utilities.o
	$(COMPILE) src/utilities.h $(OBJ)/utilities.o $(TESTS)/check_date_order.cpp -o $(BUILDS)/check_date_order

days_between_dates: $(TESTS)/days_between_dates.cpp utilities.o
	$(COMPILE) src/utilities.h $(OBJ)/utilities.o $(TESTS)/days_between_dates.cpp -o $(BUILDS)/days_between_dates