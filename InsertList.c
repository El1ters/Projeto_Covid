#include "main.h"

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

