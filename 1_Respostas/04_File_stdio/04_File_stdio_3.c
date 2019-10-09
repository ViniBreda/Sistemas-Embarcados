#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char file_name[25];
	strcpy(file_name, argv[1]);
	strcat(file_name, ".txt");
	printf("%s\n", file_name);
	FILE * fp;
	fp = fopen(file_name, "w");
	fprintf(fp, "Nome: %s.\nIdade: %s anos.\n", argv[1], argv[2]);
	fclose(fp);
	return 0;
}
