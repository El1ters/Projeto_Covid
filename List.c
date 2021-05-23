#include "main.h"


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



/*Esta função que se segue serve para mostrar todos os dados do ficheiro de forma organizada*/
void printLista(Country *listhead,char *D){
	Country *Aux;
	Year *AuxY;
	Week *AuxW;
	int date[2];

	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
		printf("===============País=================\n");
		printf("Name: %s\n",Aux->name);
		printf("Code: %s\n",Aux->country_code);
		printf("Continent: %s\n",Aux->continent);
		printf("Population: %d\n",Aux->population);
		for(AuxY = Aux->next_year; AuxY != NULL ;AuxY = AuxY->next_year){	
			if(strcmp(D,"none") != 0){
				SelectData(listhead,date,Aux->name,D);
			}
			if(strcmp(D,"none") == 0){
				printf("Ano: %d\n",AuxY->year);
			}else if(AuxY->year == date[0]){
				printf("Ano: %d\n",AuxY->year);
			}
			for(AuxW = AuxY->next_week; AuxW != NULL; AuxW = AuxW->next_week){
				if(strcmp(D,"none") == 0){
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
				if(AuxW->week == date[1] && AuxY->year == date[0]){
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

}



/*Esta função serve para mostrar todos os dados de forma organizada relativos a um só continente,
continente esse escolhido pelo utilizador pelo utilizador*/
void PrintContinentOnly(Country *listhead,char *L,char *D){

	Country *Aux;
	Year *AuxY;
	Week *AuxW;
	int date[2];

	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
		if(strcmp(Aux->continent,L) == 0){
			printf("===============País=================\n");
			printf("Name: %s\n",Aux->name);
			printf("Code: %s\n",Aux->country_code);
			printf("Continent: %s\n",Aux->continent);
			printf("Population: %d\n",Aux->population);
			for(AuxY = Aux->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
				if(strcmp(D,"none") != 0){
					SelectData(listhead,date,Aux->name,D);
				}
				if(strcmp(D,"none") == 0){
					printf("Ano: %d\n",AuxY->year);
				}else if(AuxY->year == date[0]){
					printf("Ano: %d\n",AuxY->year);
				}
				for(AuxW = AuxY->next_week; AuxW != NULL; AuxW = AuxW->next_week){
					if(strcmp(D,"none") == 0){
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
					if(AuxW->week == date[1] && AuxY->year == date[0]){
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
	}
}



/*A função abaixo serve para libertar o espaço que tinha sido alocado na memória para guardar os dados do ficheiro.
Faz-se isto para evitar que fique "lixo" na memória*/
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