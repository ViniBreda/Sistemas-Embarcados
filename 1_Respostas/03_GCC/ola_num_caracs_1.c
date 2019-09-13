#include <stdio.h>
#include "num_caracs.h"

void main(int argc, char *argv[]){
	for(int i = 1; i < argc; i++){
		printf("Argumento: %s| Numero de caracteres: %d\n", argv[i], Num_Caracs(argv[i]));
	}
}
