#include "main.h"



/*A função que se segue serve para aquando, da criação de um novo nó da lista secundária (criação essa que é chamada
no "ReadFile") o programa saber a qual nó da lista principal é que este novo nó pertence e desta forma conseguir encadear
a lista secundária ao nó correto da lista principal*/
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
a lista terciária ao nó correto da lista secundário*/
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