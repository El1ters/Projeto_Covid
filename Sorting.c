#include "main.h"

Country *SortPopulation(Country *listhead){
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
					/*if(right->population < right->next_country->population){
						left->next_country = SwitchNode(right,right->next_country);
						change = 1;
					}*/
					/*adicionar depois uma flag para escolher o de cima ou o de baixo*/
					if(strcmp(right->name,right->next_country->name) > 0){
						left->next_country = SwitchNode(right,right->next_country);
						change = 1;
					}
					left = right;
					if(right->next_country != NULL){
						right = right->next_country;
					}
				}

		}
	}

	/*saltar o "dummy" introduzido na lista*/
	right = head->next_country;
	return right;
}

Country *SwitchNode(Country *left,Country *right){
	left->next_country = right->next_country;
	right->next_country = left;
	return right;
}