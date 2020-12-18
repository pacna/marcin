CC = gcc

PROG = sdl-ulam-spiral

SRCS = $(addprefix src/, main.c global.c utils.c spiral.c)

OBJS = $(SRCS:.c=.o)

all: $(PROG)
# linking the program
$(PROG): ${OBJS}
		${CC} ${OBJS} -o ${PROG}

clean:
	rm $(PROG) $(OBJS)