all: itunes.o node.o basic.o
	gcc -o music itunes.o node.o basic.o
itunes.o: itunes.c
	gcc -c itunes.c
node.o: node.c
	gcc -c node.c
basic.o: basic.c
	gcc -c basic.c
clean:
	rm -f *~ *.o
run: all
	./music

