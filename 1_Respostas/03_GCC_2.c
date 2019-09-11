#include <stdio.h>

void main (void){
	char nome[20] = {};
	printf("Digite o seu nome: ");
	scanf("%s", &nome);
	printf("Olá, %s!\n", nome);
}
