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
		newcountry = ReadFile(ListHead,line);

		if(ReadFile(ListHead,line) != 0){
			ListHead = CriaListaPeloTopo(ListHead,newcountry);
		}
		
	}
	printLista(ListHead);

	fclose(fp);
	return 0;
}


Country *CriaListaPeloTopo(Country *listhead,Country *country_inserted){		
	if(listhead == NULL){
		listhead = country_inserted;
	}
	else{
		country_inserted -> next_country = listhead;
		listhead = country_inserted;
	}

	return listhead;

}

void printLista(Country *listhead){
	Country *Aux;
	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
		printf("%s\n",Aux->name);
		printf("%s\n",Aux->country_code);
		printf("%s\n",Aux->continent);
		printf("%d\n",Aux->population);
	}
	
}

