#Makefile
LDFLAGS=-lncurses

cgol: main.o
	cc $(LDFLAGS) main.o -o cgol

main.o: main.c
	cc -c main.c -o main.o

clean:
	rm *.o cgol
