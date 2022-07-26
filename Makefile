#Makefile
all: Add-nbo

Add-nbo: main.o
	g++ -o Add-nbo main.o

main.o: main.cpp

clean:
	rm -f Add-nbo
	rm -f main.o
