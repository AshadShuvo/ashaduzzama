#include<iostream>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
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
