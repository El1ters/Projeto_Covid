#include "main.h"


/*Esta função serve para comparar duas strings, sendo essencial para que no ReadFile.c se saiba se se tem de criar um
novo nó da lista princiapl ou não, pois se já exisitir um nó respetivo a um país, ao serem percorridas as diferentes linhas
do ficheiro fornecido pelo professor quando se encontra outra vez dados fixos relativos ao mesmo país não deve ser cirado um novo
nó, passando-se para a linha seguinte e fazendo a mesma verificação*/
int CompareName(Country *listhead,char *string){
	Country *AuxH;
	if(listhead == NULL){
		return 0;
	}
	else{
		for(AuxH = listhead; AuxH != NULL; AuxH = AuxH->next_country){
			if(strcmp(AuxH->name,string) == 0){
				return 1;
			}
		}

	}
	return 0;
}

int CompareYear(Country *listhead,int year,char *string1){
	Country *AuxH;
	Year *AuxY;
	for(AuxH = listhead; AuxH != NULL; AuxH = AuxH->next_country){
		for(AuxY = AuxH->next_year; AuxY != NULL; AuxY = AuxY->next_year){
			    if(AuxY->year == year && strcmp(AuxH->name,string1) == 0){
					return 1;
				}
		}		
	}

	return 0;
}

int CompareWeek(Country *listhead,int year,int week,char *string){
	Country *AuxH;
	Year *AuxY;
	Week *AuxW;
	for(AuxH = listhead;AuxH != NULL; AuxH = AuxH->next_country){
		for(AuxY = AuxH->next_year;AuxY != NULL;AuxY = AuxY->next_year){
			for(AuxW = AuxY->next_week;AuxW != NULL; AuxW = AuxW->next_week){
				if(AuxW->week == week && AuxY->year == year && strcmp(AuxH->name,string) == 0){
					return 1;
				}
			}
		}
	}

	return 0;
}