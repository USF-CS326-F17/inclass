PROGS = sish listtest

all : ${PROGS}

sish : sish.c
	gcc -o sish sish.c

listtest : listtest.c list.c list.h
	gcc -o listtest listtest.c list.c

clean :
	rm ${PROGS}

