ola_num_caracs_2: ola_num_caracs_2.o num_caracs.o
	gcc -o ola_num_caracs_2 ola_num_caracs_2.o num_caracs.o

ola_num_caracs_2.o: ola_num_caracs_2.c num_caracs.h
	gcc -o ola_num_caracs_2.o ola_num_caracs_2.c -c

num_caracs.o: num_caracs.c num_caracs.h
	gcc -o num_caracs.o num_caracs.c -c

clean:
	rm -f *.o ola_num_caracs_2
