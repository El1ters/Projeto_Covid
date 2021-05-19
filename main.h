#ifndef Covid19Proj
#define Covid19Proj


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Estrutura de uma lista terciária*/
typedef struct _Week{
	int week;
	int indicator_cases;  /*1 se fo for caso 0 se não for*/
	int indicator_deaths; /*1 se for mortes 0 se não for*/
	int weekly_count_cases;
	int weekly_count_deaths;
	float rate_14_day_cases;
	float rate_14_day_deaths;
	int comulative_count_cases;
	int comulative_count_deaths;
	struct _Week *next_week;
}Week;


/*Estrutura de uma lista secundária*/
typedef struct _Year{	
	int year;
	struct _Year *next_year;
	Week *next_week;

}Year;


/*Estrutura da lista principal*/
typedef struct _Country{
	char name[30];
	char country_code[4];
	char continent[15];
	int population;
	struct _Country *next_country;
	Year *next_year; 
	
}Country;

/*Declaração de Funçoes*/
Country *ReadFile(Country **listhead,char *line);
char *strtok_costum(char **string,char const remove);
Country *CreateCountryStruct();
Year *CreateYearStruct();
Week *CreateWeekStruct();
void StoreContentCountry(char content[9][70],Country *country);
Country *CriaListaPorBaixo(Country *listhead,Country *country_inserted);
void printLista(Country *listhead);
int CompareName(Country *listhead,char *string);
int CompareYear(Country *listhead,int year,char *string1);
int CompareWeek(Country *listhead,int year,int week,char *string2);
void free_list(Country *listhead);
Country *InsertSubList(Country *listhead,char *name,Year *NewYear);
Country *InsertThirdList(Country *listhead,Week *NewWeek,char *string,int year);
#endif