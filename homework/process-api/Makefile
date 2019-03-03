all: \
	1_fork.exe\
	2_open_fork.exe\
	3_post_fork_order.exe\
	4_fork_exec.exe\
	5_wait.exe\
	6_waitpid.exe\
	7_close_stdout.exe\
	8_pipe.exe

1_fork.exe: 1_fork.c
	gcc -c 1_fork.c
	gcc -o 1_fork.exe 1_fork.o

2_open_fork.exe: 2_open_fork.c
	gcc -c 2_open_fork.c
	gcc -o 2_open_fork.exe 2_open_fork.o

3_post_fork_order.exe: 3_post_fork_order.c
	gcc -c 3_post_fork_order.c
	gcc -o 3_post_fork_order.exe 3_post_fork_order.o

4_fork_exec.exe: 4_fork_exec.c
	gcc -c 4_fork_exec.c
	gcc -o 4_fork_exec.exe 4_fork_exec.o

5_wait.exe: 5_wait.c
	gcc -c 5_wait.c
	gcc -o 5_wait.exe 5_wait.o

6_waitpid.exe: 6_waitpid.c
	gcc -c 6_waitpid.c
	gcc -o 6_waitpid.exe 6_waitpid.o

7_close_stdout.exe: 7_close_stdout.c
	gcc -c 7_close_stdout.c
	gcc -o 7_close_stdout.exe 7_close_stdout.o

8_pipe.exe: 8_pipe.c
	gcc -c 8_pipe.c
	gcc -o 8_pipe.exe -lreadline 8_pipe.o

clean:
	rm -f *.o *.exe *~ \#*#
