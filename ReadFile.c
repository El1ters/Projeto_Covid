#include "main.h"

void ReadFile(FILE *fp){
	char *token;
	const char virgula[] = ",";
	char line[128];
	char name[35];
	char code[4];
	char continent[15];
	int population;


	/*Usa-se um fgets para ignorar o cabeçalho*/
	fgets(line,128,fp);
	

	int i = 0;

	while(fgets(line,128,fp) != NULL){
		token = strtok(line,virgula);
		i=0;
		printf("=============PAÍS===============\n");

		/*Leitura de uma linha do ficheiro e analise dos dados*/
		while(token != NULL){
				if(i == 0){
					strcpy(name,token);
				}
				if(i == 1){
					strcpy(code,token);
				}
				if(i == 2){
					strcpy(continent,token);
				}
				if(i == 3){
					population = atoi(token);
				}

			token = strtok(NULL,virgula);
			i++;

		}
		printf("\n");
    	printf("%s\n",name);
		printf("%.3s\n",code);
		printf("%s\n",continent);
		printf("%d\n",population);

	}


}