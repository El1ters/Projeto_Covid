#include "main.h"


/*Esta função serve apenas para alocar memória suficiente para criar uma estrutura do
tipo Country necessária à criação dos nós da lista principal*/
Country *CreateCountryStruct(){
	Country *NewCountry;

	if((NewCountry = calloc(1,sizeof(Country))) == NULL){
		printf("could not allocate memory");
		exit(EXIT_FAILURE);
	}

	return NewCountry;
}



/*Esta função serve apenas para alocar memória suficiente para criar uma estrutura do
tipo Year necessária à criação dos nós da lista secundária*/
Year *CreateYearStruct(){

	Year *NewYear;
	if((NewYear = calloc(1,sizeof(Year))) == NULL){
		printf("could not allocate memory");
		exit(EXIT_FAILURE);

	}

	return NewYear;
}



/*Esta função serve apenas para alocar memória suficiente para criar uma estrutura do
tipo Week necessária à criação dos nós da lista terciária*/
Week *CreateWeekStruct(){

	Week *NewWeek;
	if((NewWeek = calloc(1,sizeof(Week)))== NULL){
		printf("could not allocate memory");
		exit(EXIT_FAILURE);
	}

	return NewWeek;
}