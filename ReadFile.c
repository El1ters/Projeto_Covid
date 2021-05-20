#include "main.h"


/*Esta Função irá servir para lermos os dados do ficheiro fornecido pelo professor -> vai receber como argumentos
um ponteiro que aponta para uma estrutura do tipo da dos Países e que irá permitir encadear os nós da lista principal
e um ponteiro do tipo Char que apontará para a linha do ficheiro da qual estamos a retirar a informção*/
Country *ReadFile(Country **listhead,char *line){
		char *token;
		char content[9][70] = {{0}};
		/*Inicialização de um ponteiro que aponta para uma estrutura do tipo Country que, por
        sua vez conterá a informação referente a um nó da lista principal -> o valor para
        o qual este ponteiro aponta será o valor retornado pela função*/
		Country *NewCountry = NULL;
		Year *NewYear = NULL;
		Week *NewWeek = NULL;
		int year;
		int week;
		int i = 0;

		token = strtok(line,",");
		/*O ciclo while que se segue permite percorrer todos os dados referentes a cada linha do ficheiro fornecido
		copiando-os para uma variável auxiliar denominada de "content" */
		while(token != NULL){
			strcpy(content[i],token);
			token = strtok(NULL,",");
				i++;
		}
			if(i == 8){
				strcpy(content[8],content[7]);
				strcpy(content[7],"\0");
			}
			strtok(content[8],"\n");
			sscanf(content[6],"%d-%d",&year,&week);
			/*Este ciclo if que se segue irá fazer a comparação com o conteúdo retirado acima das linhas do ficheiro de modo
        	a verificar se já existe ou não um nó referente a um dado país. Se não existir, então será criado um*/
			if(CompareName(*listhead,content[0]) == 0){
				NewCountry = CreateCountryStruct();
			 	StoreContentCountry(content,NewCountry);
			 	

			 	if(CompareYear(*listhead,year,content[0]) == 0){
			 		NewYear = CreateYearStruct();
			 		NewCountry->next_year = NewYear; 
			 		NewYear->year = year;	
			 	}
			 	if(CompareWeek(*listhead,year,week,content[0]) == 0){
						NewWeek = CreateWeekStruct();

						NewWeek->week = week;
						if(strcmp(content[4],"cases") == 0){
							NewWeek->weekly_count_cases = atoi(content[5]);
							NewWeek->rate_14_day_cases = atof(content[7]);
							NewWeek->comulative_count_cases = atoi(content[8]);
						}
					
						NewYear->next_week = NewWeek;
			 	}
			}else{
				if(CompareYear(*listhead,year,content[0]) == 0){
					NewYear = CreateYearStruct();
					NewYear->year = year;
					*listhead = InsertSubList(*listhead,content[0],NewYear);
				}

				if(CompareWeek(*listhead,year,week,content[0]) == 0){
					NewWeek = CreateWeekStruct();
					NewWeek->week = week;
					if(strcmp(content[4],"cases") == 0){
							NewWeek->weekly_count_cases = atoi(content[5]);
							NewWeek->rate_14_day_cases = atof(content[7]);
							NewWeek->comulative_count_cases = atoi(content[8]);
					}
					*listhead = InsertThirdList(*listhead,NewWeek,content[0],year);
				}else{
					StoreContentWeek(*listhead,content[0],year,week,atoi(content[5]),atof(content[7]),atoi(content[8]));
				}
				
					
				return NULL;
			}


	return NewCountry;	
}