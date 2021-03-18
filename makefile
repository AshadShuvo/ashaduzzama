CFLAGS = -O

CC = gcc

NumTest:main.o getop.o stack.o getch.o
	$(CC) $(CFLAGS) -o Rafiul main.o getop.o stack.o getch.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

getop.o: getop.c
	$(CC) $(CFLAGS) -c getop.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

getch.o: getch.c
	$(CC) $(CFLAGS) -c getch.c


clean:
	rm -f core *.o
