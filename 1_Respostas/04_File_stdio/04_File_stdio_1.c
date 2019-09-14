#include <stdio.h>

int main(){
	FILE * fp;

	fp = fopen("ola_mundo.txt", "w");
	fprintf(fp, "%s %s\n", "Ola", "mundo!");
	fclose(fp);
	return 0;
}
