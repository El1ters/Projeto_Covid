#ifndef Covid19Proj
#define Covid19Proj


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Country{
	char country[30];
	char country_code[3];
	char continent[15];
	int population;
	struct _Country *next; 
	
}Country;


void ReadFile(FILE *fp);

#endif