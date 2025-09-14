CC = gcc

final: main.o endpoints.o call_api.o
	$(CC) main.o endpoints.o call_api.o -o program -lcurl

endpoints.o: endpoints.c
	$(CC) -c endpoints.c

main.o: main.c 
	$(CC) -c main.c

call_api.o: call_api.c
	$(CC) -c call_api.c