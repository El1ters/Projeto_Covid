#include "main.h"

/*Função que permite retirar do ficheiro fornecido pelo professor,em forma de string, os dados entre as vírgulas*/
char *strtok_costum(char **string,char const remove){

	char *result = calloc(75,sizeof(char));/*Alocação de memória*/
	int i=0;

	/*Iterar n vezes até encontrar o caractér não desejado, dando retorno em forma de string de todos os caracteres encontrados
	até ao não desejado*/
	for(i = 0; **string != remove;i++, (*string)++){
		if(**string == '\0'){
			return result;
		}
		result[i] = **string;
	}

	(*string)++; /*Incrementar a posição do ponteiro para saltar o caractér não desejado na string*/

	return result;
}
