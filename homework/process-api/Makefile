all: 1_fork.exe 2_open_fork.exe

1_fork.exe: 1_fork.c
	gcc -c 1_fork.c
	gcc -o 1_fork.exe 1_fork.o

2_open_fork.exe: 2_open_fork.c
	gcc -c 2_open_fork.c
	gcc -o 2_open_fork.exe 2_open_fork.o

clean:
	rm -f *.o *.exe *~
