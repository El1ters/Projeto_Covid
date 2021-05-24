#include "main.h"


/*Esta função serve para comparar duas strings, sendo essencial para que no "ReadFile.c" se saiba se se tem de criar um
novo nó da lista principal ou não pois, se já existir um nó respetivo a um país, ao serem percorridas as diferentes linhas
do ficheiro fornecido pelo professor quando se encontra outra vez dados fixos relativos ao mesmo país não deve ser criado um novo
nó, passando-se para a linha seguinte do ficheiro e fazendo a mesma verificação*/
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



/*Esta função serve para comparar duas strings, sendo essencial para que no "ReadFile.c" se saiba se se tem de criar um
novo nó da lista secundária ou não pois, se já existir um nó respetivo a um dado ano, ao serem percorridas as diferentes linhas
do ficheiro fornecido pelo professor quando se encontra outra vez dados variáveis desse mesmo ano não deve ser criado um novo
nó, passando-se para a linha seguinte do ficheiro e fazendo a mesma verificação*/
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



/*Esta função serve para comparar duas strings, sendo essencial para que no "ReadFile.c" se saiba se se tem de criar um
novo nó da lista terciária ou não pois, se já existir um nó respetivo a uma dada semana, ao serem percorridas as diferentes linhas
do ficheiro fornecido pelo professor quando se encontra outra vez dados variáveis dessa mesma semana não deve ser criado um novo
nó, passando-se para a linha seguinte do ficheiro e fazendo a mesma verificação*/
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


/*Esta função serve apenas para o programa saber o intervalo de semanas que é especificado pelo utilizador em certas opções
da linha de comandos, ou seja, através desta função o programa contabiliza o número total de semanas limitando a informação
entre aquelas que o utilizador definir como extremos*/
int CompareDates(int week[2],int year[2],Year *A,Week *B){
	int aux[2];
	int comp = A->year + B->week;
	aux[1] = year[1] + week[1];
	aux[0] = year[0] + week[0];
	if(A->year == 2021){
		comp += 53;
	}
	if(year[0] == 2021){
		aux[0] += 53;
	}
	if(year[1] == 2021){
		aux[1] += 53;
	}
	//printf("%d %d %d\n",aux[0], comp, aux[1]);
	if(comp >= aux[0]  && comp <= aux[1]){
		return 1;
	}else{
		return 0;
	}

}
