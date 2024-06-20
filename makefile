CC=g++
IDIR=src/header

all: main.out

main.out: src/main.cpp binaryGenes.o genes.o utils.o
	$(CC) -I $(IDIR) -o main.out $^


%.o: src/%.cpp
	$(CC) -I $(IDIR) -c -o $*.o $<

clean:
	rm *{.o,.out}

