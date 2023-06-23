tem:=${wildcard *.c}
file:=${patsubst %.c, %.o, $(tem)}

main:$(file)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@

creat:
	touch head.c head.h main.c

clear:
	rm main *.o