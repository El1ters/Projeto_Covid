#include "main.h"


/*Função que permite acrescentar os nós criados para cada país à lista principal, encaminhando-os numa lista simplesmente ligada
-> esta função recebe como argumentos dois ponteiros para uma estrutura do tipo país (correspondetes à cabeça do primeiro nó da
lista principal e à cabeça do nó inserido imediatamente a seguir a esse, respetivamnte)*/
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

/*Esta função serve para mostrar todos os dados de forma organizada, dependendo das opções inseridas pelo utilizador
na linha de comandos, ou seja, consoante as opções que o utilizador inserir o programa irá dar print da informação do
ficheiro relativo a essas mesmas restrições. Basicamente esta função irá percorrer as três listas onde estão guardados
os dados do ficheiro e irá, ao mesmo, tempo verificar as restrições inseridas pelo utilizador e, consoante isso, irá dar print
da respetiva informção -> esta função recebe como argumentos um ponteiro para uma estrutura do tipo país (corresponde à cabeça
da lista principal), vários ponteiros do tipo char (correspondem às variávéis inicializadas na linha de comandos (que contém os
dados que o utilzador introduziu na linha de comandos relativamente ao -L, -D e -P)) e ainda dois vetores de inteiros
(que correspondem ao número total de semanas dos anos considerados no ficheiro )*/
void PrintLista(Country *listhead,char *L,char *D,char *P,int n,int year[2],int week[2], FILE *fp){

	Country *Aux;
	Year *AuxY;
	Week *AuxW;
	int date[2] = {0};
	int flag;

	/*Ao longo dos ciclos for's e das condições if's que se seguem o programa vai percorrendo as listas e verificando se alguma
    restrição se verifica, para saber os dados do ficheiro que terá de dar print*/
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
										if((CompareDates(week,year,AuxY,AuxW) == 1 && strcmp(P,"dates") == 0) || strcmp(P,"dates") != 0){
											if(flag == 0){
												fprintf(fp,"%s,",Aux->name);
												fprintf(fp,"%s,",Aux->country_code);
												fprintf(fp,"%s,",Aux->continent);
												fprintf(fp,"%d,",Aux->population);
												fprintf(fp,"cases,");
												fprintf(fp,"%d,",AuxW->weekly_count_cases);
												fprintf(fp,"%d-",AuxY->year);
												fprintf(fp,"%d,",AuxW->week);
												fprintf(fp,"%.3f,",AuxW->rate_14_day_cases);
												fprintf(fp,"%d\n",AuxW->comulative_count_cases);
											}else{
												fprintf(fp,"%s,",Aux->name);
												fprintf(fp,"%s,",Aux->country_code);
												fprintf(fp,"%s,",Aux->continent);
												fprintf(fp,"%d,",Aux->population);
												fprintf(fp,"deaths,");
												fprintf(fp,"%d,",AuxW->weekly_count_deaths);
												fprintf(fp,"%d-",AuxY->year);
												fprintf(fp,"%d,",AuxW->week);
												fprintf(fp,"%.3f,",AuxW->rate_14_day_deaths);
												fprintf(fp,"%d\n",AuxW->comulative_count_deaths);
											}
										}
									}
								}
								if(AuxW->week == date[1] && AuxY->year == date[0]){
									if((strcmp(P,"date") == 0  && AuxW->week == week[0]) || strcmp(P,"date") != 0 ){
										if((CompareDates(week,year,AuxY,AuxW) == 1 && strcmp(P,"dates") == 0) || strcmp(P,"dates") != 0){
											if((flag == 0 && strcmp(D,"dea") != 0 && strcmp(D,"raciodea") != 0) || (strcmp(D,"inf") == 0 && flag == 0) || (strcmp(D,"racioinf") == 0 && flag == 0)){
												fprintf(fp,"%s,",Aux->name);
												fprintf(fp,"%s,",Aux->country_code);
												fprintf(fp,"%s,",Aux->continent);
												fprintf(fp,"%d,",Aux->population);
												fprintf(fp,"cases,");
												fprintf(fp,"%d,",AuxW->weekly_count_cases);
												fprintf(fp,"%d-",AuxY->year);
												fprintf(fp,"%d,",AuxW->week);
												fprintf(fp,"%.3f,",AuxW->rate_14_day_cases);
												fprintf(fp,"%d\n",AuxW->comulative_count_cases);
											}else if((flag == 1 && strcmp(D,"inf") != 0 && strcmp(D,"racioinf") != 0)){
												fprintf(fp,"%s,",Aux->name);
												fprintf(fp,"%s,",Aux->country_code);
												fprintf(fp,"%s,",Aux->continent);
												fprintf(fp,"%d,",Aux->population);
												fprintf(fp,"deaths,");
												fprintf(fp,"%d,",AuxW->weekly_count_deaths);
												fprintf(fp,"%d-",AuxY->year);
												fprintf(fp,"%d,",AuxW->week);
												fprintf(fp,"%.3f,",AuxW->rate_14_day_deaths);
												fprintf(fp,"%d\n",AuxW->comulative_count_deaths);
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


/*A função abaixo serve para libertar o espaço que tinha sido alocado na memória para guardar os dados do ficheiro. Faz-se isto
para evitar que fique "lixo" na memória -> esta função recebe como argumentos um ponteiro para uma estrutura do tipo país
(corresponde à cabeça da nossa lista principal)*/
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