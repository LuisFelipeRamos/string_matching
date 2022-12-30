CC = gcc
CFLAGS = -Wall -Werror

tgt: functions.o main.o
	${CC} -o tgt functions.o main.o

functions.o: functions.h functions.c
	${CC} ${CFLAGS} functions.c -c -o functions.o

main.o: main.c
	${CC} ${CFLAGS} main.c -c -o main.o

clean:
	rm main.o functions.o tgt