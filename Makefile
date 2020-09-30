CC = gcc

PROG = sdl-ulam-spiral

OBJS = main.o

all: $(PROG)

$(PROG): ${OBJS}
		${CC} ${OBJS} -o ${PROG}

clean:
	rm ${PROG} *.o