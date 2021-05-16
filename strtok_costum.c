#include "main.h"

char *strtok_costum(char **string,char const remove){
	char *result = calloc(75,sizeof(char));
	int i=0;

	/*iterar n vezes até encontrar o caracter que desejamos remover*/
	for(i = 0; **string != remove;i++, (*string)++){
		if(**string == '\0'){
			return result;
		}
		result[i] = **string;		
	}
	/*aumentar a posiçao do ponteiro para saltar a o caracter nao desejado na string*/
	(*string)++;
	

	return result;
}

