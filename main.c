#include "main.h"

int main(int argc,char *argv[]){

	/*Cabeça da lista*/
	Country *ListHead = NULL;
	Country *newcountry;

	FILE *fp;
	fp = fopen("covid19_w_t01.csv","r");

	char line[128]; 

	/*Usa-se um fgets para ignorar o cabeçalho*/
	fgets(line,128,fp);
	while(fgets(line,128,fp) != NULL){
		if((newcountry = ReadFile(ListHead,line)) != 0){
			ListHead = CriaListaPorBaixo(ListHead,newcountry);
		}
		
	}
	printLista(ListHead);
	free_list(ListHead);

	fclose(fp);
	return 0;
}


Country *CriaListaPorBaixo(Country *listhead,Country *country_inserted){
	Country *Aux;
	

	if(listhead == NULL){
		listhead = country_inserted;
	}
	else{
		for(Aux = listhead;Aux->next_country != NULL;Aux = Aux->next_country);
		country_inserted -> next_country = NULL;
		Aux->next_country = country_inserted;
	}

	return listhead;

}

void printLista(Country *listhead){
	Country *Aux;

	/*Aux no fim de cado ciclo aponta para a lista seguinte*/
	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
		printf("===============Lista=================\n");
		printf("Name: %s\n",Aux->name);
		printf("Code: %s\n",Aux->country_code);
		printf("Continent: %s\n",Aux->continent);
		printf("population: %d\n",Aux->population);
	}
	
}
void free_list(Country *listhead){
	Country *Aux;
	Aux = listhead;
	while(Aux != NULL){
		listhead = Aux->next_country;
		free(Aux);
		Aux = listhead;
	}
}

