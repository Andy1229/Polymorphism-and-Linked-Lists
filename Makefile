
# driver is made by linking object files together
all: main.o BinaryNode.o Individual.o Rearrange.o BitFlip.o
	g++ main.o BinaryNode.o Individual.o Rearrange.o BitFlip.o -o main

# make separated class files to *.o

BinaryNode.o : BinaryNode.cpp BinaryNode.h
	g++ -c BinaryNode.cpp -o BinaryNode.o

Individual.o : Individual.cpp Individual.h
	g++ -c Individual.cpp -o Individual.o


Rearrange.o : Rearrange.cpp Rearrange.h
	g++ -c Rearrange.cpp -o Rearrange.o

BitFlip.o : BitFlip.cpp BitFlip.h
	g++ -c BitFlip.cpp -o BitFlip.o

# make driver (main) file to *.o with class files
main.o: main.cpp BinaryNode.h Individual.h Rearrange.h BitFlip.h
	g++ -c main.cpp -o main.o

# clean removes all object files and the compiled executable
clean:
	rm -f *.o driver
