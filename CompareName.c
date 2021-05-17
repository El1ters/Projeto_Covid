#include "main.h"

int CompareName(Country *listhead,char *string){
	Country *AuxH;

	if(listhead == NULL){
		return 0;
	}
	else{
		for(AuxH = listhead; AuxH != NULL;AuxH = AuxH->next_country){
			if(strcmp(AuxH->name,string) == 0){
				return 1;
			}
		}
	}
	return 0;

}