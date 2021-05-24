#include "main.h"


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



/*Esta função que se segue serve para mostrar todos os dados do ficheiro de forma organizada*/
/*void printLista(Country *listhead,char *D,char *P,int n,int year[2],int week[2]){
	Country *Aux;
	Year *AuxY;
	Week *AuxW;
	int date[2];
	int flag;

	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
	  	if(strcmp(P,"none") == 0 || Restrict(listhead,Aux->name,n,P) == 0){
	  	  	for(flag = 0;flag <= 1;flag++){	
				for(AuxY = Aux->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
			  		if((strcmp(P,"date") == 0  && AuxY->year == year[0]) || (strcmp(P,"date") != 0 && strcmp(P,"dates") != 0) ||
			  			(strcmp(P,"dates") == 0 && AuxY->year >= year[0] && AuxY->year <= year[1])){		
						if(strcmp(D,"none") != 0){
							SelectData(listhead,date,Aux->name,D);
						}
						for(AuxW = AuxY->next_week; AuxW != NULL; AuxW = AuxW->next_week){
							if(strcmp(D,"none") == 0){
								if((strcmp(P,"date") == 0  && AuxW->week == week[0]) || strcmp(P,"date") != 0 ){
									if((CompareDates(week,year,AuxY,AuxW) == 1 && strcmp(P,"dates") == 0) || strcmp(P,"dates") != 0){
										if(flag == 0){
											printf("%s,",Aux->name);
											printf("%s,",Aux->country_code);
											printf("%s,",Aux->continent);
											printf("%d,",Aux->population);
											printf("%d,",AuxY->year);
											printf("%d,",AuxW->week);
											printf("Casos:");
											printf("%d,",AuxW->weekly_count_cases);
											printf("%.3f,",AuxW->rate_14_day_cases);
											printf("%d\n\n",AuxW->comulative_count_cases);
										}else{
											printf("%s,",Aux->name);
											printf("%s,",Aux->country_code);
											printf("%s,",Aux->continent);
											printf("%d,",Aux->population);
											printf("%d,",AuxY->year);
											printf("%d,",AuxW->week);
											printf("Mortes:");
											printf("%d,",AuxW->weekly_count_deaths);
											printf("%.3f,",AuxW->rate_14_day_deaths);
											printf("%d\n\n",AuxW->comulative_count_deaths);
										}
							    	}
								}
							}
							if(AuxW->week == date[1] && AuxY->year == date[0]){
								if((strcmp(P,"date") == 0  && AuxW->week == week[0]) || strcmp(P,"date") != 0 ){
									if((CompareDates(week,year,AuxY,AuxW) == 1 && strcmp(P,"dates") == 0) || strcmp(P,"dates") != 0){
										if((flag == 0 && strcmp(D,"dea") != 0 && strcmp(D,"raciodea") != 0) || strcmp(D,"inf") == 0 || strcmp(D,"racioinf") == 0){
											printf("%s,",Aux->name);
											printf("%s,",Aux->country_code);
											printf("%s,",Aux->continent);
											printf("%d,",Aux->population);
											printf("%d,",AuxY->year);
											printf("%d,",AuxW->week);
											printf("Casos:");
											printf("%d,",AuxW->weekly_count_cases);
											printf("%.3f,",AuxW->rate_14_day_cases);
											printf("%d\n\n",AuxW->comulative_count_cases);
										}else{
											printf("%s,",Aux->name);
											printf("%s,",Aux->country_code);
											printf("%s,",Aux->continent);
											printf("%d,",Aux->population);
											printf("%d,",AuxY->year);
											printf("%d,",AuxW->week);
											printf("Mortes:");
											printf("%d,",AuxW->weekly_count_deaths);
											printf("%.3f,",AuxW->rate_14_day_deaths);
											printf("%d\n\n",AuxW->comulative_count_deaths);
										}
									}
								}
							}
						}
				  	}
				}
		    }	
		}
	}
}*/

/*Esta função serve para mostrar todos os dados de forma organizada relativos a um só continente,
continente esse escolhido pelo utilizador pelo utilizador*/
void PrintLista(Country *listhead,char *L,char *D,char *P,int n,int year[2],int week[2]){

	Country *Aux;
	Year *AuxY;
	Week *AuxW;
	int date[2] = {0};
	int flag;

	for(Aux = listhead; Aux != NULL; Aux = Aux->next_country){
	  	if(strcmp(P,"none") == 0 || Restrict(listhead,Aux->name,n,P) == 0){
			if(strcmp(Aux->continent,L) == 0 || strcmp(L,"all") == 0){
			    for(flag = 0;flag <= 1;flag++){	
					for(AuxY = Aux->next_year; AuxY != NULL ;AuxY = AuxY->next_year){
						if((strcmp(P,"date") == 0  && AuxY->year == year[0]) || (strcmp(P,"date") != 0 && strcmp(P,"dates") != 0) ||
			  				(strcmp(P,"dates") == 0 && AuxY->year >= year[0] && AuxY->year <= year[1])){
							if(strcmp(D,"none") != 0){
								SelectData(listhead,date,Aux->name,D);
							}

							for(AuxW = AuxY->next_week; AuxW != NULL; AuxW = AuxW->next_week){

								if(strcmp(D,"none") == 0){

									if((strcmp(P,"date") == 0  && AuxW->week == week[0]) || strcmp(P,"date") != 0 ){
										//printf("%d\n",CompareDates(week,year,AuxY,AuxW));
										if((CompareDates(week,year,AuxY,AuxW) == 1 && strcmp(P,"dates") == 0) || strcmp(P,"dates") != 0){
											if(flag == 0){
												printf("%s,",Aux->name);
												printf("%s,",Aux->country_code);
												printf("%s,",Aux->continent);
												printf("%d,",Aux->population);
												printf("%d,",AuxY->year);
												printf("%d,",AuxW->week);
												printf("Casos:");
												printf("%d,",AuxW->weekly_count_cases);
												printf("%.3f,",AuxW->rate_14_day_cases);
												printf("%d\n\n",AuxW->comulative_count_cases);
											}else{
												printf("%s,",Aux->name);
												printf("%s,",Aux->country_code);
												printf("%s,",Aux->continent);
												printf("%d,",Aux->population);
												printf("%d,",AuxY->year);
												printf("%d,",AuxW->week);
												printf("Mortes:");
												printf("%d,",AuxW->weekly_count_deaths);
												printf("%.3f,",AuxW->rate_14_day_deaths);
												printf("%d\n\n",AuxW->comulative_count_deaths);
											}
										}
									}
								}
								if(AuxW->week == date[1] && AuxY->year == date[0]){
									if((strcmp(P,"date") == 0  && AuxW->week == week[0]) || strcmp(P,"date") != 0 ){
										if((CompareDates(week,year,AuxY,AuxW) == 1 && strcmp(P,"dates") == 0) || strcmp(P,"dates") != 0){
											if((flag == 0 && strcmp(D,"dea") != 0 && strcmp(D,"raciodea") != 0) || (strcmp(D,"inf") == 0 && flag == 0) || (strcmp(D,"racioinf") == 0 && flag == 0)){
												printf("%s,",Aux->name);
												printf("%s,",Aux->country_code);
												printf("%s,",Aux->continent);
												printf("%d,",Aux->population);
												printf("%d,",AuxY->year);
												printf("%d,",AuxW->week);
												printf("Casos:");
												printf("%d,",AuxW->weekly_count_cases);
												printf("%.3f,",AuxW->rate_14_day_cases);
												printf("%d\n\n",AuxW->comulative_count_cases);
											}else if((flag == 1 && strcmp(D,"inf") != 0 && strcmp(D,"racioinf") != 0)){
												printf("%s,",Aux->name);
												printf("%s,",Aux->country_code);
												printf("%s,",Aux->continent);
												printf("%d,",Aux->population);
												printf("%d,",AuxY->year);
												printf("%d,",AuxW->week);
												printf("Mortes:");
												printf("%d,",AuxW->weekly_count_deaths);
												printf("%.3f,",AuxW->rate_14_day_deaths);
												printf("%d\n\n",AuxW->comulative_count_deaths);
											}
										}
									}
								}
							}  
						}
					}
			  	}	
			}
		}	
	}
}


/*A função abaixo serve para libertar o espaço que tinha sido alocado na memória para guardar os dados do ficheiro.
Faz-se isto para evitar que fique "lixo" na memória*/
void free_list(Country *listhead){
	Country *Aux;
	Year *AuxY;
	Week *AuxW;

	for(Aux = listhead;Aux != NULL; Aux = listhead){
		listhead = Aux->next_country;
		for(AuxY = Aux->next_year; AuxY != NULL;AuxY = Aux->next_year){
			for(AuxW = AuxY->next_week;AuxW != NULL;AuxW = AuxY->next_week){
				AuxY->next_week = AuxW->next_week;
				free(AuxW);
			}
			Aux->next_year = AuxY->next_year;
			free(AuxY);
		}
		free(Aux);
	}

}