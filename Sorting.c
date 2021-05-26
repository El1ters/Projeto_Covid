#include "main.h"

/*A função que se encontra abaixo serve para ordenar os dados do ficheiro por ordem decrescente do número de população de
países (no caso de o utilizador inserir -S pop na linha de comandos) ou por ordem alfabética de países (no caso de o
utilizador inserir -S alfa na linha de comandos) -> recebe como argumentos um ponteiro para uma estrutura do tipo País (vai
corresponder à cabeça da lista principal) e um ponteiro para a variável S inicializada na linha de comandos (que contém os
dados que o utilizador introduziu na linha de comandos relativamente ao -S), dando retorno no fim de tudo de "right" que será
a cabeça da nossa lista já ordenada*/
Country *BubbleSort(Country *listhead,char *S){
	int change = 1;
	Country *left, *right, *head, aux_struct;

	/*No tipo de ordenação Bubble Sort, comparam-se estruturas e, portanto, inserimos uma estrutura auxiliar vazia no
	inicio da lista para podermos efetuar a comparação com o primeiro elemento da lista*/
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

/*Esta função serve para inverter a ordem de dois nós consecutivos de uma dada lista, neste caso da lista principal ->
-> recebe como argumentos dois ponteiros para um estrutura do tipo country (corresponderão a dois nós consecutivos da lista
principal) e dá retorno de "righ" (que será a cabeça do nosso nó que agora ficou em primeiro lugar ao nível da ordenção efetuada)*/
Country *SwitchNode(Country *left,Country *right){
	left->next_country = right->next_country;
	right->next_country = left;
	return right;
}



/*Esta função serve para selecionar os dados relativos a uma dada semana, dependendo do input que o utilizador introduzir
na linha de comandos, ou seja, é a forma como o programa reage dependendo da palavra que o utilizador insere ao lado da opção
-D na linha de comandos (no caso de inserir) -> recebe como argumentos um ponteiro para uma estrutura do tipo Country (que será
a cabeça da nossa lista principal), um vetor do tipo inteiro (armazenará a semana selecionada pelo programa), um ponteiro do tipo
char (aponta para o nome do país em causa) e um ponteiro para a variável D inicializada na linha de comandos (que contém os
dados que o utilizador introduziu na linha de comandos relativamente ao -D)*/
void SelectData(Country *listhead,int date[2],char *name,char *D){
	Country *AuxH;
	Year *AuxY;
	Week *AuxW;
	int big = -10;
	float big1 = -10;

	for(AuxH = listhead;AuxH != NULL ; AuxH = AuxH->next_country){
	  	if(strcmp(AuxH->name,name) == 0){
			for(AuxY = AuxH->next_year; AuxY != NULL; AuxY = AuxY->next_year){
				for(AuxW = AuxY->next_week; AuxW!= NULL; AuxW =  AuxW->next_week){
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



/*A função que se encontra mais abaixo serve para restringir (em relação aos inputs -P min ou -P max) os dados do ficheiro
que o programa irá dar print, ou seja, se o utilizador inserir -P min o ficheiro ficará restrito apenas aos dados dos países
que contém uma população maior do que aquela inserida pelo utilizador ou se o utilizador inserir -P max o ficheiro ficará
restrito apenas aos dados dos países que contém uma população menor do que aquela inserida pelo utilizador -> esta função
recebe como argumentos um ponteiro para um estrutura do tipo país (corresponde à cabeça da lista principal), um ponteiro do tipo
char (corresponde ao nome do país em causa), um inteiro auxiliar (corresponderá ao número inserido pelo utilizador para a restrição)
e um ponteiro para a variável P inicializada na linha de comandos (que contém os dados que o utilizador introduziu na linha de
comandos relativamente ao -P), retornando 1 sempre que um país tiver uma população dentro da restrição pedida e 0 em caso contrário*/
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


/*A função que se encontra abaixo serve para ordenar os dados do ficheiro por ordem decrescente do número total de infetados
por países numa determinada data yyyy-ww ou por ordem decrescente do número total de mortes  por países numa determinada data
yyyy-ww (no caso de o utilizador inserir -S inf ou -S dea na linha de comandos, respetivamente) -> recebe como argumentos um
ponteiro para uma estrutura do tipo País (vai corresponder à cabeça da lista principal), um ponteiro para a variável S
inicializada na linha de  comandos (que contém os dados que o utilizador introduziu na linha de comandos relativamente ao -S)
e um vetor do tipo inteiro (que vai guardar a data introduzida pelo utilizador na linha de comandos), dando retorno no fim de
tudo de "right" que será a cabeça da nossa lista já ordenada*/
Country *SortTotal(Country *listhead,char *S, int date[2]){
	int change = 1;
	Country *head,*left,*right,aux_struct;
	Week *AuxW_R,*AuxW_RN;
	Year *AuxY_R,*AuxY_RN;
	int comulative_R = 0, comulative_RN = 0;



	head = &aux_struct;
	head->next_country = listhead;
	if(listhead != NULL && listhead->next_country != NULL){
		while(change){
			change = 0;
			left = head;
			right = head->next_country;
				while(right->next_country != NULL){
					for(AuxY_R = right->next_year; AuxY_R != NULL;AuxY_R = AuxY_R->next_year){
						if(AuxY_R->year == date[0]){
							for(AuxW_R = AuxY_R->next_week; AuxW_R != NULL; AuxW_R = AuxW_R->next_week){
								if(AuxW_R->week == date[1]){
									if(strcmp(S,"inf") == 0){
										comulative_R = AuxW_R->weekly_count_cases;
									}else{
										comulative_R = AuxW_R->weekly_count_deaths;
									}
								}
							}
						}
					}
					for(AuxY_RN = right->next_country->next_year; AuxY_RN != NULL;AuxY_RN = AuxY_RN->next_year){
						if(AuxY_RN->year == date[0]){
							for(AuxW_RN = AuxY_RN->next_week; AuxW_RN != NULL; AuxW_RN = AuxW_RN->next_week){
								if(AuxW_RN->week == date[1]){
									if(strcmp(S,"inf") == 0){
										comulative_RN = AuxW_RN->weekly_count_cases;
									}else{
										comulative_RN = AuxW_RN->weekly_count_deaths;
									}
								}
							}
						}
					}
					if(comulative_R < comulative_RN){
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
	/*Faz-se isto para saltarmos o "dummy" introduzido no início da lista de modo a que, quando fizermos retorno da cabeça
    da lista esta estar a apontar para a primeira estrutura com conteúdo da lista e não uma estrutura vazia auxiliar*/
	right = head->next_country;
	return right;
}
