#include "main.h"


int main(int argc,char *argv[]){
	char L[10], S[10],D[10],P[10],i[10],o[10];
	CommandLine(argc,argv,L,S,D,P,i,o);
	/*Inicialização de um ponteiro que aponta para o tipo de estrutura Country -> este
    ponteiro corresponde à cabeça da lista principal (a que contém os nomes dos diferentes países*/
	Country *ListHead = NULL;
	/*Criação de um ponteiro que aponta para o tipo de estrutura Country - vai servir para
    criar novos nós da lista principal que, por sua vez, contém os diferentes países*/
	Country *newcountry;

	FILE *fp;
	/*Abertura para leitura do ficheiro criado que irá ter o título indicado*/
	if((fp = fopen("covid19_w_tf01.csv","r")) == NULL){
		printf("could not open the file\n");
		exit(EXIT_FAILURE);
	}

	char line[128]; 

	/*Usa-se um fgets para ignorar o cabeçalho*/
	fgets(line,128,fp);
	/*Este ciclo while que se segue vai percorrer linha a linha todo o ficheiro fornecido pelo professor e irá criar um
	novo nó da lista principal (a que contém os nomes dos países) sempre que encontarar uma linha com um nome de um
	país para o qual ainda não existe nó -> deste modo temos assim a nossa Lista principal criada*/
	while(fgets(line,128,fp) != NULL){
		if((newcountry = ReadFile(&ListHead,line)) != NULL){
			ListHead = CriaListaPorBaixo(ListHead,newcountry);
		}
		
	}
	printLista(ListHead);
	free_list(ListHead);

	fclose(fp);
	return 0;
}

/*Função que permite acrescentar os nós criados para cada país à lista principal, encaminhando-os numa lista
simplesmente ligada*/
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
	Year *AuxY;
	Week *AuxW;

	/*Aux no fim de cado ciclo aponta para a lista seguinte*/
	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
		printf("===============País=================\n");
		printf("Name: %s\n",Aux->name);
		printf("Code: %s\n",Aux->country_code);
		printf("Continent: %s\n",Aux->continent);
		printf("Population: %d\n",Aux->population);
		for(AuxY = Aux->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
			printf("Ano: %d\n",AuxY->year);
			for(AuxW = AuxY->next_week; AuxW != NULL; AuxW = AuxW->next_week){
				printf("\tSemana: %d\n",AuxW->week);
				//printf("\t Casos:\n");
				//printf("\t  weekly_count:%d\n",AuxW->weekly_count_cases);
				//printf("\t  rate_14_day:%.3f\n",AuxW->rate_14_day_cases);
				//printf("\t  comulative_count:%d\n",AuxW->comulative_count_cases);
				printf("\t Mortes:\n");
				printf("\t  weekly_count:%d\n",AuxW->weekly_count_deaths);
				printf("\t  rate_14_day:%.3f\n",AuxW->rate_14_day_deaths);
				printf("\t  comulative_count:%d\n",AuxW->comulative_count_deaths);

			}

		}
	}
	
}

void free_list(Country *listhead){
	Country *Aux;
	Year *AuxY;
	Week *AuxW;

	for(Aux = listhead;Aux != NULL;Aux = listhead){
		listhead = Aux->next_country;
		for(AuxY = Aux->next_year; AuxY != NULL;AuxY = Aux->next_year){	
			for(AuxW = AuxY->next_week;AuxW != NULL;AuxW = AuxY->next_week){
				AuxY->next_week = AuxW->next_week;
				free(AuxW);
			}
			Aux->next_year = AuxY->next_year;
			free(AuxY);
		}
		free(Aux);
	}

}