all: a.out

a.out: main.o contact.o file.o populate.o
	gcc -o a.out main.o contact.o file.o populate.o

main.o: main.c contact.h
	gcc -c main.c

contact.o: contact.c contact.h file.h populate.h
	gcc -c contact.c

file.o: file.c file.h
	gcc -c file.c

populate.o: populate.c populate.h contact.h
	gcc -c populate.c

run: a.out
	./a.out

clean:
	rm -f *.o a.out