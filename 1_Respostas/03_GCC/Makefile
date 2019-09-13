ola_num_caracs_1: ola_num_caracs_1.o num_caracs.o
	echo onc1
	gcc -o ola_num_caracs_1 ola_num_caracs_1.o num_caracs.o

ola_num_caracs_1.o: ola_num_caracs_1.c num_caracs.h
	echo onc1.o
	gcc -o ola_num_caracs_1.o ola_num_caracs_1.c -c

num_caracs.o: num_caracs.c num_caracs.h
	echo nc.o
	gcc -o num_caracs.o num_caracs.c -c

clean:
	rm -f *.o ola_num_caracs_1
