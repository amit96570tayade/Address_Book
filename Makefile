addressbook: main.o contact.o file.o populate.o
	gcc main.o contact.o file.o populate.o -o addressbook

main.o: main.c contact.h
	gcc -c main.c

contact.o: contact.c contact.h file.h
	gcc -c contact.c

file.o: file.c file.h
	gcc -c file.c

populate.o: populate.c populate.h contact.h
	gcc -c populate.c

run: addressbook
	./addressbook

clean:
	rm -f *.o addressbook