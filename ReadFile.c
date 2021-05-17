#include "main.h"

/*Esta Função irá servir para lermos os dados do ficheiro fornecido pelo professor -> vai receber como argumentos
um ponteiro que aponta para uma estrutura do tipo da dos Países e que irá permitir encadear os nós da lista principal
e um ponteiro do tipo Char que apontará para a linha do ficheiro da qual estamos a retirar a informção*/
Country *ReadFile(Country *listhead,char *line){

		char *token; /*Ponteiro do tipo Char que irá servir para guardar os dados das colunas*/
		char content[9][70] = {{0}}; /*Criação de um vetor do tipo Char que contém espaço para cada uma das 9 colunas
                                       presentes no ficheiro do professor, sendo que cada uma delas tem capacidade para guardar
                                       no máximo dados com 70 caracteres*/
		Country *NewCountry = NULL; /*Inicialização de um ponteiro que aponta para uma estrutura do tipo Country que, por
                                      sua vez conterá a informação referente a um nó da lista principal -> o valor para
                                      o qual este ponteiro aponta será o valor retornado pela função*/
		int i = 0; /*Inicialização de uma variável auxiliar*/

		token = strtok_costum(&line,','); /*Permite passar para a posição de memória, para a qual o ponteiro
		token está a apontar, os dados de uma linha do ficheiro fornecido pelo professor, ignorando as vírgulas
		que estão a separar o conteúdo das diferentes colunas*/

		/*O ciclo while que se segue permite percorrer todos os dados referentes a cada linha do ficheiro fornecido
		copiando-os para uma variável auxiliar denominada de "content" */
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

        /*Este ciclo if que se segue irá fazer a comparação com o conteúdo retirado acima das linhas do ficheiro de modo
        a verificar se já existe ou não um nó referente a um dado país. Se não existir, então será criado um*/
        if(CompareName(listhead,content[0]) == 0){
            NewCountry = CreateStruct();
            StoreContentCountry(content,NewCountry);
        }
        else{
            return 0;  /*Verificar o resto do conteúdo que pertence ao país*/
        }


	return NewCountry;

}
