#include "main.h"

Country *CreateStruct(int number_of_countries){

	Country *NewCountry;
	if((NewCountry = calloc(1,sizeof(Country))) == 0){
		printf("Could not complete the allocation");
		exit(EXIT_FAILURE);
	}
		NewCountry -> next = NULL;
	return NewCountry;
}