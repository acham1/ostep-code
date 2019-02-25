all: \
	1_fork.exe\
	2_open_fork.exe\
	3_post_fork_order.exe

1_fork.exe: 1_fork.c
	gcc -c 1_fork.c
	gcc -o 1_fork.exe 1_fork.o

2_open_fork.exe: 2_open_fork.c
	gcc -c 2_open_fork.c
	gcc -o 2_open_fork.exe 2_open_fork.o

3_post_fork_order.exe: 3_post_fork_order.c
	gcc -c 3_post_fork_order.c
	gcc -o 3_post_fork_order.exe 3_post_fork_order.o

clean:
	rm -f *.o *.exe *~ \#*#
