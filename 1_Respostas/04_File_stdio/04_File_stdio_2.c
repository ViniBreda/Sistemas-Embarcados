#include <stdio.h>
#include <string.h>

int main()
{
	char name[20];
	unsigned short int age;
	printf("Digite o seu name: ");
	scanf(" %s", name);
	printf("Digite a sua idade: ");
	scanf("%hu", &age);
	char file_name[25];
	strcpy(file_name, name);
	strcat(file_name, ".txt");
	printf("%s\n", file_name);
	FILE * fp;
	fp = fopen(file_name, "w");
	fprintf(fp, "Nome: %s.\nIdade: %hu anos.\n", name, age);
	fclose(fp);
	return 0;
}
