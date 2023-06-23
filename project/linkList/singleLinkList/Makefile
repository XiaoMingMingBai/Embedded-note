
file:=$(wildcard *.c)
rely:=$(patsubst %.c, %.o, $(file))

all:

list:$(rely)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@

clear:
	rm *.o list








all: