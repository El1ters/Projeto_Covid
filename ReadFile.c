#include "main.h"

Country *ReadFile(Country *listhead,char *line){
		char *token;
		char content[9][70] = {{0}};
		Country *NewCountry = NULL;
		int i = 0;

		token = strtok_costum(&line,',');
		/*Leitura de uma linha do ficheiro e analise dos dados*/
		while(*token != '\0'){
			strcpy(content[i],token);
			free(token);
			if(*line == ',' && *(line-1) == ','){
				i++;
				line++;
			}
			token = strtok_costum(&line,',');
			if(i != 8)
				i++;
		}
			free(token);


			if(CompareName(listhead,content[0]) == 0){
				NewCountry = CreateStruct();
			 	StoreContentCountry(content,NewCountry);			
			}
			else{
				/*verificar o resto do conteudo que pertence ao país*/
				return 0;
			}


	return NewCountry;	

}