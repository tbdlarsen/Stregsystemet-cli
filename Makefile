CC = gcc

final: main.o endpoints.o
	$(CC) main.o endpoints.o -o program

endpoints.o: endpoints.c
	$(CC) -c endpoints.c

main.o: main.c 
	$(CC) -c main.c

