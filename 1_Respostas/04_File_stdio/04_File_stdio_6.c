#include <stdio.h>
#include <string.h>
#include "bib_arqs.h"

void main(int argc, char* argv[]){
	char cat[500] = {};
	strcpy(cat, le_arq_texto(argv[1]));
	printf("%s\n", cat);
}