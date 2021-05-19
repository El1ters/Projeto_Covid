#include "main.h"

void CommandLine(int argc, char *argv[], char *L, char *S, char *D, char *P, char *i, char *o){

    int opt=0;
	char L_aux[10], S_aux[10], D_aux[10], P_aux[10], i_aux[10], o_aux[10];

	//optind - index do próximo elemento a ser processado no argv, inicializado a 1
	//optopt - guarda o caracter da opção, quando a opcao nao é reconhecida
	//opterr - quando colocado a 0 evita a mensagem de erro
	//optarg - apontador para texto do mesmo argumento
	//optstring - string que contém a descrição das opções

	while((opt = getopt(argc, argv,"hL:S:D:P:i:o: ")) != -1){
	// -1 quando não há mais opções para processar
	// optstring : para indicar que a opção requer um parametro
	// optstring :: para indicar que o parametro da opção é opcional, o parametro deve estar junto à opção sem espaço
	// optstring - no começo quando se pretende processar os argumentos sem opção no loop while
	  switch (opt){

        case 'h':
            CommandLineHelp();
        break;

        case 'L':
            strcpy(L_aux,optarg);
        break;

        case 'S':
            strcpy(S_aux,optarg);
        break;

        case 'D':

        break;

        case 'P':

        break;

        case 'i':

        break;

        case 'o':

        break;
      }
      L=L_aux;
      S=S_aux;
      D=D_aux;
      P=P_aux;
      i=i_aux;
      o=o_aux;
	}
}



/*Função para a Linhas de Comandos - ajuda*/
void CommandLineHelp(){
    printf("-L all -> Lê o ficheiro todo.\n");
    printf("-L continente -> Lê dados relativos ao continente especificado indicado pelo utilizador.\n");
    printf("-S alfa -> Ordem alfabética de países.\n");
    printf("-S pop -> Ordem decrescente de população de países.\n");
    printf("-S inf -> Ordem decrescente do número total de infetados por países numa determinada data yyyy-ww indicada pelo utilizador.\n");
    printf("-S dea -> ordem decrescente do número total de mortes por países numa determinada data yyyy-ww indicada pelo utilizador.\n");
    printf("-D inf -> Selecionar para cada país a semana com mais infectados.\n");
    printf("-D dea -> Selecionar para cada país a semana com mais mortes.\n");
    printf("-D racioinf -> Selecionar para cada país a semana com maior rácio de infectados por 100000 habitantes.\n");
    printf("-D raciodea -> Selecionar para cada país a semana com maior rácio de mortes por milhão de habitantes.\n");
    printf("-P min -> Apenas dados de países com mais de n mil habitantes (sendo n um inteiro que é indicado pelo utilizador).\n");
    printf("-P max -> Apenas dados de países com menos de n mil habitantes (sendo n um inteiro que é indicado pelo utilizador).\n");
    printf("-P date -> Apenas dados relativos à semana indicada pelo utilizador no formato yyyy-ww.\n");
    printf("-P dates -> Apenas dados entre as semanas indicadas no formato yyyy-ww yyyy-ww (a ordem é irrelevante).\n");
    printf("-i nome_do_ficheiro.csv -> Leitura de dados do ficheiro de texto sendo que o nome_do_ficheiro é introduzido pelo utilizador.\n");
    printf("-i nome_do_ficheiro.data -> Leitura de dados do ficheiro binário sendo que o nome_do_ficheiro é introduzido pelo utilizador.\n");
    printf("-o nome_do_ficheiro.csv -> Escrita de dados em ficheiro de texto sendo que o nome_do_ficheiro é introduzido pelo utilizador.\n");
    printf("-o nome_do_ficheiro.data -> Escrita de dados em ficheiro binário sendo que o nome_do_ficheiro é introduzido pelo utilizador.\n");
}
