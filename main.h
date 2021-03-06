#ifndef Covid19Proj
#define Covid19Proj


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
	typedef struct _DatAux{
		char name[30];
		char country_code[4];
		char continent[15];
		int population;
		char indicator[7];
		int weekly_count;
		int year;
		int week;
		float rate_14_day;
		int comulative_count;
	}DatAux;

/*Estrutura de uma lista terciária -> Lista esta que irá conter todas as semanas e, respetivamente, os seus dados*/
typedef struct _Week{
	int week; /*Semana em causa*/
	int weekly_count_cases; /*Número total de casos da semana em questão*/
	int weekly_count_deaths; /*Número total de mortes da semana em questão*/
	float rate_14_day_cases; /*Rácio de casos num período de 14 dias*/
	float rate_14_day_deaths; /*Rácio de mortes num período de 14 dias*/
	int comulative_count_cases; /*Número total de casos até à data em questão*/
	int comulative_count_deaths; /*Número total de mortes até à data em questão*/
	struct _Week *next_week; /*Ponteiro que permite encadear a lista passando para o próximo nó da lista*/
}Week;


/*Estrutura de uma lista secundária -> Lista esta que irá conter todos os anos e,respetivamente, os seus dados*/
typedef struct _Year{
	int year; /*Ano em causa*/
	struct _Year *next_year; /*Ponteiro que permite encadear a lista passando para o próximo nó da lista*/
	Week *next_week; /*Ponteiro que permite fazer a ligação de um nó da lista secundária para a lista terciária respetiva*/

}Year;


/*Estrutura de uma lista principal -> Lista esta que irá conter todos os dados fixos de cada país, e cada um dos
nós desta lista irá conter, respetivamente, uma lista secundária que por sua vez se subdividirá numa lista terciária*/
typedef struct _Country{
	char name[30]; /*Nome do país*/
	char country_code[4]; /*Código do País*/
	char continent[15]; /*Nome do Continente*/
	int population; /*Número da População*/
	struct _Country *next_country; /*Ponteiro que permite encadear a lista passando para o próximo nó da lista*/
	Year *next_year; /*Ponteiro que permite fazer a ligação de um nó da lista principal para a lista secundária respetiva*/

}Country;

/*Declaração de Funções*/
Country *ReadFile(Country **listhead,char *line);
Country *CreateCountryStruct();
Year *CreateYearStruct();
Week *CreateWeekStruct();
void StoreContentCountry(char content[9][70],Country *country);
void StoreContentWeek(Country *listhead,char *string,int year,int week,int content1,float content2,int content3);
Country *CriaListaPorBaixo(Country *listhead,Country *country_inserted);
void PrintLista(Country *listhead,char *L,char *D,char *P,int n,int year[2],int week[2], FILE *fp,char *type_o);
int CompareName(Country *listhead,char *string);
int CompareYear(Country *listhead,int year,char *string1);
int CompareWeek(Country *listhead,int year,int week,char *string2);
int CompareDates(int week[2],int year[2],Year *A,Week *B);
Country *RemoveContinent(Country *listhead,char string[10]);
void free_list(Country *listhead);
Country *InsertSubList(Country *listhead,char *name,Year *NewYear);
Country *InsertThirdList(Country *listhead,Week *NewWeek,char *string,int year);
void CommandLine(int argc, char *argv[]);
void CommandLineHelp();
Country *BubbleSort(Country *listhead,char *S);
Country *SwitchNode(Country *left,Country *right);
void SelectData(Country *listhead,int date[2],char *name,char *D);
int Restrict(Country *listhead,char *name, int n, char *P);
Country *SortTotal(Country *listhead,char *S, int date[2]);
#endif