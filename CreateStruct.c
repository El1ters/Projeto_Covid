#include "main.h"

Country *CreateStruct(){
	Country *NewCountry;

	if((NewCountry = calloc(1,sizeof(Country))) == NULL){
		printf("could not allocate memory");
		exit(EXIT_FAILURE);
	}

	return NewCountry;
}