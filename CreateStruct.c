#include "main.h"

/*Esta função serve apenas para alocar memória suficiente para criar uma estrutura do
tipo Country necessária à criação dos nós da lista principal*/
Country *CreateStruct(){
	Country *NewCountry;

	if((NewCountry = calloc(1,sizeof(Country))) == NULL){
		printf("could not allocate memory");
		exit(EXIT_FAILURE);
	}

	return NewCountry;
}
