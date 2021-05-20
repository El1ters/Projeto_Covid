#include "main.h"


void StoreContentCountry(char content[9][70],Country *country){
		strcpy(country->name,content[0]);
		strcpy(country->country_code,content[1]);
		strcpy(country->continent,content[2]);			
		country->population = atoi(content[3]);
}

void StoreContentWeek(Country *listhead,char *string,int year,int week,int content1,float content2,int content3){
	Country *AuxH;
	Year *AuxY;
	Week *AuxW;

	for(AuxH = listhead; AuxH != NULL; AuxH = AuxH->next_country){
		if(strcmp(AuxH->name,string) == 0){
			for(AuxY = AuxH->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
				if(AuxY->year == year){
					for(AuxW = AuxY->next_week;AuxW != NULL;AuxW =  AuxW->next_week){
						if(AuxW->week == week){
							AuxW->weekly_count_deaths = content1;
							AuxW->rate_14_day_deaths = content2;
							AuxW->comulative_count_deaths = content3;
						}
						
					}
					
				}
				
			}
		}
		
	}
}