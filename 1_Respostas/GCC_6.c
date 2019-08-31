#include <stdio.h>

void main (int argc, char *argv[]){
	printf("Olá, ");
	for(int i = 1; i < argc; i++){
		if(i < (argc - 1)){
			printf("%s ", argv[i]);
		}else{
			printf("%s!\n",argv[i]);
		}
	}
	printf("Número de argumentos: %d\n", argc);
}
