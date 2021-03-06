#include "main.h"


/*Esta Função irá servir para lermos os dados do ficheiro fornecido pelo professor -> vai receber como argumentos
um ponteiro que aponta para um vetor de ponteiros (onde cada um deles aponta para uma estrutura do tipo da dos Países
e que irá permitir encadear os nós da lista principal) e um ponteiro do tipo char que apontará para a linha do ficheiro
da qual estamos a retirar a informção; no fim da função será retornado um nó da lista principal já com todos os dados variáveis
correspondentes.*/
Country *ReadFile(Country **listhead,char *line){
		char *token;
		char content[9][70] = {{0}};
		/*Inicialização de um ponteiro que aponta para uma estrutura do tipo Country que, por
        sua vez, irá conter a informação referente a um nó da lista principal -> o valor para
        o qual este ponteiro aponta será o valor retornado pela função*/
		Country *NewCountry = NULL;
		/*Inicialização de um ponteiro que aponta para uma estrutura do tipo Year que, por
        sua vez, irá conter a informação referente a um novo nó da lista secundária*/
		Year *NewYear = NULL;
		/*Inicialização de um ponteiro que aponta para uma estrutura do tipo Week que, por
        sua vez, irá conter a informação referente a um novo nó da lista terciária*/
		Week *NewWeek = NULL;
		int year;
		int week;
		int i = 0;

		token = strtok(line,",");
		/*O ciclo while que se segue permite percorrer todos os dados referentes a cada linha do ficheiro fornecido
		copiando-os para uma variável auxiliar denominada de "content"*/
		while(token != NULL){
			strcpy(content[i],token);
			token = strtok(NULL,",");
				i++;
		}
            /*Este if serve para resolver o problema de aparecerem duas vírgulas seguidas em algumas linhas do ficheiro*/
			if(i == 8){
				strcpy(content[8],content[7]);
				strcpy(content[7],"\0");
			}
			strtok(content[8],"\n");
			sscanf(content[6],"%d-%d",&year,&week);

			/*Este if que se segue irá fazer a comparação com o conteúdo retirado acima das linhas do ficheiro de modo
        	a verificar se já existe ou não um nó referente a um dado país. Se não existir, então será criado um*/
			if(CompareName(*listhead,content[0]) == 0){
				NewCountry = CreateCountryStruct();
			 	StoreContentCountry(content,NewCountry);

			 	/*Este segundo if que se segue irá fazer a comparação com o conteúdo retirado acima das linhas do ficheiro
                de modo a verificar se já existe ou não um nó referente à lista secundária. Se não existir, então será criado um*/
			 	if(CompareYear(*listhead,year,content[0]) == 0){
			 		NewYear = CreateYearStruct();
			 		NewCountry->next_year = NewYear;
			 		NewYear->year = year;
			 	}
			 	/*Este terceiro if que se segue irá fazer a comparação com o conteúdo retirado acima das linhas do ficheiro
                de modo a verificar se já existe ou não um nó referente à lista terciária. Se não existir, então será criado um*/
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