PROGS = redirect2 pipe pipe_bad pipe_exec pipe_pcc fork_many mish nish read

all : ${PROGS}

redirect2 : redirect2.c
	gcc -o redirect2 redirect2.c

pipe : pipe.c
	gcc -o pipe pipe.c

pipe_bad : pipe_bad.c
	gcc -o pipe_bad pipe_bad.c

pipe_exec : pipe_exec.c
	gcc -o pipe_exec pipe_exec.c

pipe_pcc : pipe_pcc.c
	gcc -o pipe_pcc pipe_pcc.c

fork_many : fork_many.c
	gcc -o fork_many fork_many.c

mish : mish.c
	gcc -o mish mish.c

nish : nish.c prompt.h prompt.c parse.h parse.c commands.h commands.c
	gcc -o nish nish.c prompt.c parse.c commands.c

read : read.c
	gcc -o read read.c

clean :
	rm -rf ${PROGS}
