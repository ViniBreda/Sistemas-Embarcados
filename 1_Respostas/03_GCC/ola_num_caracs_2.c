#include <stdio.h>
#include "num_caracs.h"

void main(int argc, char *argv[]){
	int n = 0;
	for(int i = 0; i < argc; i++){
		n += Num_Caracs(argv[i]);
	}
	printf("Total de caracteres de entrada: %d\n", n);
}
