#include "main.h"

/*Função que permite a criação de um nó da lista principal -> nó este que contém os dados fixos de cada país*/
void StoreContentCountry(char content[9][70],Country *country){
		strcpy(country->name,content[0]);
		strcpy(country->country_code,content[1]);
		strcpy(country->continent,content[2]);
		country->population = atoi(content[3]);
}
