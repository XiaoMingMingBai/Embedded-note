tem:=${wildcard *.c}
file:=${patsubst %.c, %.o, $(tem)}


main:$(file)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@

clear:
	rm *.o main