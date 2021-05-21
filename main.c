#include "main.h"



int main(int argc,char *argv[]){

    CommandLine(argc, argv);

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

	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
		printf("===============Lista=================\n");
		printf("Name: %s\n",Aux->name);
		printf("Code: %s\n",Aux->country_code);
		printf("Continent: %s\n",Aux->continent);
		printf("Population: %d\n",Aux->population);
		for(AuxY = Aux->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
			printf("Ano: %d\n",AuxY->year);
			for(AuxW = AuxY->next_week; AuxW != NULL; AuxW = AuxW->next_week){
				printf("  Semana: %d\n",AuxW->week);
				printf("\tCasos:\n");
				printf("\t  weekly_count:%d\n",AuxW->weekly_count_cases);
				printf("\t  rate_14_day:%.3f\n",AuxW->rate_14_day_cases);
				printf("\t  comulative_count:%d\n",AuxW->comulative_count_cases);
				printf("\tMortes:\n");
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

	for(Aux = listhead;Aux != NULL; Aux = listhead){
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