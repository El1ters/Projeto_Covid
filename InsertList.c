#include "main.h"

/*A função que se segue serve para aquando, da criação de um novo nó da lista secundária (criação essa que é chamada
no "ReadFile") o programa saber a qual nó da lista principal é que este novo nó pertence e desta forma conseguir encadear
a lista secundária ao nó correto da lista principal -> esta função recebe como argumentos um ponteiro para uma estrutura do
tipo país (corresponde à cabeça da lista principal), um ponteiro para uma string (que permitirá fazer comparações) e um ponteiro
para uma estrutura do tipo Ano (corresponde ao ponteiro que faz a ligação da lista principal com a lista secundária), retornando
a cabeça da lista principal*/
Country *InsertSubList(Country *listhead,char *string,Year *NewYear){
	Country *AuxH;
	Year *AuxY;
	for(AuxH = listhead; AuxH != NULL; AuxH = AuxH->next_country){
		if(strcmp(AuxH->name,string) == 0){

			AuxY = AuxH->next_year;
			while(AuxY->next_year != NULL){
				AuxY = AuxY->next_year;
			}
				AuxY->next_year = NewYear;
		}
	}

	return listhead;
}



/*A função que se segue serve para aquando, da criação de um novo nó da lista terciária (criação essa que é chamada
no "ReadFile") o programa saber a qual nó da lista secundária é que este novo nó pertence e desta forma conseguir encadear
a lista terciária ao nó correto da lista secundária -> esta função recebe como argumentos um ponteiro para uma estrutura do
tipo país (corresponde à cabeça da lista principal), um ponteiro para uma string (que permitirá fazer comparações),um ponteiro
para uma estrutura do tipo semana (corresponde ao ponteiro que faz a ligação da lista secundária com a lista terciária) e ainda
um inteiro (para sabermos a qual ano nos estamos a referir )retornando a cabeça da lista principal*/
Country *InsertThirdList(Country *listhead,Week *NewWeek,char *string,int year){

	Country *AuxH;
	Year *AuxY;
	for(AuxH = listhead; AuxH != NULL; AuxH = AuxH->next_country){
		if(strcmp(AuxH->name,string) == 0){
			for(AuxY = AuxH->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
				if(AuxY->year == year){
						NewWeek->next_week = AuxY->next_week;
						AuxY->next_week = NewWeek;


				}
			}
		}
	}

	return listhead;
}
