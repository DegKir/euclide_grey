all: tests
tests: tests.o Formulas.o
	g++ tests.o Formulas.o -o tests
tests.o: tests.cpp
	g++ -c tests.cpp -o tests.o
Formulas.o: Formulas.cpp
	g++ -c Formulas.cpp -o Formulas.o
clean:
	rm -rf tests. *.0
