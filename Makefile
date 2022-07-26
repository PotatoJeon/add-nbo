#Makefile
all: hexAdd

hexAdd: main.o
	g++ -o hexAdd main.o

main.o: main.cpp

clean:
	rm -f hexAdd
	rm -f main.o
