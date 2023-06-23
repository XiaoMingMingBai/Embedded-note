file:=$(wildcard *.c)
rely:=$(patsubst %.c, %.o, $(file))

all:

main:$(rely)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@

clear:
	rm *.o