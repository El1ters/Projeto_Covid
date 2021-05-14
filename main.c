#include "main.h"

int main(){

	/*Cabeça da lista*/
	Country *ListHead = NULL;

	FILE *fp;
	char line[128];

	fp = fopen("covid19_w_t01.csv","r");

	//fgets(line,128,fp);
	ReadFile(fp);


	fclose(fp);
	return 0;
}