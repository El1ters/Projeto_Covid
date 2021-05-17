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
		for(AuxH = listhead; AuxH != NULL;AuxH = AuxH->next_country){
			if(strcmp(AuxH->name,string) == 0){
				return 1;
			}
		}
	}
	return 0;

}
