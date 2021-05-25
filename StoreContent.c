
#include "main.h"

/*A função void que se segue permite copiar os dados fixos do ficheiro para os nós da lista principal que vão ter o tipo
de estrutura Country*/
void StoreContentCountry(char content[9][70],Country *country){
		strcpy(country->name,content[0]);
		strcpy(country->country_code,content[1]);
		strcpy(country->continent,content[2]);
		country->population = atoi(content[3]);
}

/*A função void que se segue permite copiar os dados variáveis do ficheiro para os nós das listas secundária e terciária
sendo que, recorre-se a ciclos for's para, à medida que se vai avançando no ficheiro sempre que nos estivermos a referir
aos mesmos dados fixos retira-se do ficheiro apenas o conteúdo das colunas que não contém esses dados fixos; da mesma forma,
sempre que nos estivermos a referir a um mesmo ano retira-se do ficheiro apenas o conteúdo das colunas que vai variando
para o mesmo ano; e o mesmo para as semanas. -> Deste modo conseguimos extrair do ficheiro o conteúdo respetivo a cada
um dos nós da lista terciária, secundária e principal*/
void StoreContentWeek(Country *listhead,char *string,int year,int week,int content1,float content2,int content3){
	Country *AuxH;
	Year *AuxY;
	Week *AuxW;

	for(AuxH = listhead; AuxH != NULL; AuxH = AuxH->next_country){
		if(strcmp(AuxH->name,string) == 0){
			for(AuxY = AuxH->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
				if(AuxY->year == year){
					for(AuxW = AuxY->next_week;AuxW != NULL;AuxW =  AuxW->next_week){
						if(AuxW->week == week){
							AuxW->weekly_count_deaths = content1;
							AuxW->rate_14_day_deaths = content2;
							AuxW->comulative_count_deaths = content3;
						}

					}

				}

			}
		}

	}
}