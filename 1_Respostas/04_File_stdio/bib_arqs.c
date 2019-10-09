#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo){
	int sz;
	FILE * fp;
	fp = fopen(nome_arquivo, "r");
	fseek(fp, 0L, SEEK_END);
	fseek(fp, 0, SEEK_SET);
	return sz = ftell(fp);
}

char* le_arq_texto(char *nome_arquivo){
	//printf("le_arq_texto\n");
	char* string;
	FILE *fp;
	fp = fopen(nome_arquivo, "r");
	int i = 0;
	while(!feof(fp)){
		string[i] = fgetc(fp);
		//printf("%d", i);
		//printf("%c", string[i]);
		i++;
	}
	//printf("\nool:%d\n", i);
	string[i-1] = '\0'; // colocando o EoS na string capturada
	char* str_to_ret = malloc(sizeof (char) * sizeof(string));
	strcpy(str_to_ret, string);
	//printf("%s\n", str_to_ret);
	return str_to_ret;
}