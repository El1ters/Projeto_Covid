#include "main.h"



/*A função que se encontra abaixo serve para ordenar os dados do ficheiro por ordem decrescente do número de
população de países*/
Country *BubbleSort(Country *listhead,char *S){
	int change = 1;
	Country *left, *right, *head, aux_struct;

	/*No tipo de ordenação Bubble Sort comparam-se estruturas, portanto inserimos uma estrutura auxiliar vazia no inicio da lista
	para podermos efetuar a comparação com o primeiro elemento da lista*/
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

	/*Faz-se isto para saltarmos o "dummy" introduzido no início da lista de modo a que, quando fizermos retorno da cabeça
    da lista esta estar a apontar para a primeira estrutura com conteúdo da lista e não uma estrutura vazia auxiliar*/
	right = head->next_country;
	return right;
}

/*Esta função serve para inverter a ordem de dois nós consecutivos de uma dada lista, neste caso da lista principal*/
Country *SwitchNode(Country *left,Country *right){
	left->next_country = right->next_country;
	right->next_country = left;
	return right;
}
