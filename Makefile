CC = gcc

PROG = sdl-ulam-spiral

SRCS = $(addprefix src/, main.c global.c is_prime.c)

OBJS = $(SRCS:.c=.o)

all: $(PROG)
# linking the program
$(PROG): ${OBJS}
		${CC} ${OBJS} -o ${PROG}

clean:
	rm $(PROG) $(OBJS)