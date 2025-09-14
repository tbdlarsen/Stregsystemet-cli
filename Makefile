CC = gcc

final: main.o endpoints.o call_api.o overwrite_id.o
	$(CC) main.o endpoints.o call_api.o overwrite_id.o -o program -lcurl && rm *.o

endpoints.o: endpoints.c
	$(CC) -c endpoints.c

main.o: main.c 
	$(CC) -c main.c

call_api.o: call_api.c
	$(CC) -c call_api.c

overwrite_id.o: overwrite_id.c
	$(CC) -c overwrite_id.c