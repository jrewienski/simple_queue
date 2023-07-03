CFLAGS = --coverage -Wall -fprofile-arcs -ftest-coverage -g

test : main.o simple_queue.o
		cc -o test.out $(CFLAGS) main.o simple_queue.o

main.o : main.c simple_queue.h
		cc $(CFLAGS) -c main.c

simple_queue.o : simple_queue.c simple_queue.h
		cc $(CFLAGS) -c simple_queue.c

coverage :
	gcov main.c simple_queue.c

clean :
		rm test.out main.o simple_queue.o *.gcno *.gcda *.gcov 