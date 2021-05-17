#include "main.h"

/*Função principal que será executada pelo programa*/
int main(int argc,char *argv[]){

	Country *ListHead = NULL; /*Inicialização de um ponteiro que aponta para o tipo de estrutura Country -> este
                                ponteiro corresponde à cabeça da lista principal (a que contém os nomes dos diferentes países*/
	Country *newcountry; /*Criação de um ponteiro que aponta para o tipo de estrutura Country - vai servir para
                           criar novos nós da lista principal que, por sua vez, contém os diferentes países*/

	FILE *fp; /*Criação de um ponteiro que aponta para um ficheiro onde irão ser escritos os dados, para ser lidos
                posteriormente pelo utilizador*/
	fp = fopen("covid19_w_t01.csv","r"); /*Abertura para leitura do ficheiro criado que irá ter o título indicado*/

	char line[128]; /*Vetor do tipo Char que vai guardar todo o conteúdo de cada uma das linhas
                    do ficheiro fornecido pelo professor*/


	fgets(line,128,fp); /*Utiliza-se um fgets para ignorar o cabeçalho*/

	/*Este ciclo while que se segue vai percorrer linha a linha todo o ficheiro fornecido pelo professor e irá criar um
	novo nó da lista principal (a que contém os nomes dos países) sempre que encontarar uma linha com um nome de um
	país para o qual ainda não existe nó -> deste modo temos assim a nossa Lista principal criada*/
	while(fgets(line,128,fp) != NULL){
		if((newcountry = ReadFile(ListHead,line)) != 0){
			ListHead = CriaListaPorBaixo(ListHead,newcountry); /*Acrescenta um nó à lista principal -> lista
                                                                 que contém os dados fixos dos países*/
		}

	}
	printLista(ListHead); /*Este print serve para o utilizador ver todos os dados relativos a um dado país*/
	free_list(ListHead); /*Libertam-se da memória esses dados*/

	fclose(fp); /*Encerra-se o ficheiro do qual o utilizador está a ler os dados*/
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



/*Função que permite dar print dos dados fixos de cada país*/
void printLista(Country *listhead){
	Country *Aux;

	/*Aux no fim de cado ciclo aponta para a lista seguinte*/
	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
		printf("===============Lista=================\n");
		printf("Name: %s\n",Aux->name);
		printf("Code: %s\n",Aux->country_code);
		printf("Continent: %s\n",Aux->continent);
		printf("population: %d\n",Aux->population);
	}

}



/*Função que permite libertar da memória os dados que foram lidos do ficheiro*/
void free_list(Country *listhead){
	Country *Aux;
	Aux = listhead;
	while(Aux != NULL){
		listhead = Aux->next_country;
		free(Aux);
		Aux = listhead;
	}
}
