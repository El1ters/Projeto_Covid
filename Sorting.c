#include "main.h"

/*A função que se encontra abaixo serve para ordenar os dados do ficheiro por ordem decrescente do número de
população de países*/
Country *BubbleSort(Country *listhead,char *S){
	int change = 1;
	Country *left, *right, *head, aux_struct;

	/*No tipo de ordenação Bubble Sort, compara-se structs, inserimos uma struct sem nada no inicio da lista
	para poder-mos efetuar a comparação com o primeiro elemento da lista*/
	head = &aux_struct;
	head->next_country = listhead;

	if((listhead != NULL) && (listhead->next_country != NULL)){
		while(change){
			change = 0;
			left = head;
			right = head->next_country;
				while(right->next_country != NULL){

					if(strcmp(S,"pop") == 0){
						if(right->population < right->next_country->population){
							left->next_country = SwitchNode(right,right->next_country);
							change = 1;
						}
					}
					if(strcmp(S,"alfa") == 0){
						if(strcmp(right->name,right->next_country->name) > 0){
							left->next_country = SwitchNode(right,right->next_country);
							change = 1;
						}
					}
					left = right;
					if(right->next_country != NULL){
						right = right->next_country;
					}
				}

		}
	}

	/*Faz-se isto para saltarmos o "dummy" introduzido no início da lista de modo a que,
	quando fizermos retorno da cabeça da lista esta estar a apontar para a primeira estrutura com conteúdo da lista
	e não uma estrutura vazia auxiliar*/
	right = head->next_country;
	return right;
}

/*Esta função serve para inverter a ordem de dois nós consecutivos de uma dada lista, neste caso da lista principal*/
Country *SwitchNode(Country *left,Country *right){
	left->next_country = right->next_country;
	right->next_country = left;
	return right;
}


void SelectData(Country *listhead,int date[2],char *name,char *D){
	Country *AuxH;
	Year *AuxY;
	Week *AuxW;
	int big = -10;
	float big1 = -10;

	for(AuxH = listhead;AuxH != NULL ; AuxH = AuxH->next_country){
	  	if(strcmp(AuxH->name,name) == 0){	
			for(AuxY = AuxH->next_year; AuxY != NULL; AuxY = AuxY->next_year){
				for(AuxW = AuxY->next_week; AuxW->next_week != NULL; AuxW =  AuxW->next_week){
					if(big < AuxW->weekly_count_cases && strcmp(D,"inf") == 0){
						big = AuxW->weekly_count_cases;
						date[0] = AuxY->year;
						date[1] = AuxW->week;
					}
					if(big < AuxW->weekly_count_deaths && strcmp(D,"dea") == 0){
						big = AuxW->weekly_count_deaths;
						date[0] = AuxY->year;
						date[1] = AuxW->week;
					}
					if(big1 < AuxW->rate_14_day_cases && strcmp(D,"racioinf") == 0){
						big1 = AuxW->rate_14_day_cases;
						date[0] = AuxY->year;
						date[1] = AuxW->week;
					}
					if(big1 < AuxW->rate_14_day_deaths && strcmp(D,"raciodea") == 0){
						big1 = AuxW->rate_14_day_deaths;
						date[0] = AuxY->year;
						date[1] = AuxW->week;
					}
				}
	 		}
		}
	}
}


int Restrict(Country *listhead,char *name, int n, char *P){
	Country *Aux;
	for(Aux = listhead;Aux != NULL; Aux = Aux->next_country){
		if(strcmp(Aux->name,name) == 0 && Aux->population <= n*1000 && strcmp(P,"min") == 0){
			return 1;
		}
		if(strcmp(Aux->name,name) == 0 && Aux->population >= n*1000 && strcmp(P,"max") == 0){
			return 1;
		}
	}
	return 0;
}