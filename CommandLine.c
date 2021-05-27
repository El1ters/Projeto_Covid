#include "main.h"

/*Em suma esta função contém a forma como todas as opções da linha de comandos são geradas -> recebe como argumentos de entrada
os parâmetros da linha de comandos*/
void CommandLine(int argc, char *argv[])
{
    /*Inicialização das variáveis do tipo char da linha de comandos */
    int opt=0;
    char L[10] = "all", S[10] = "alfa", D[10] = "none" , P[10] = "none", i[10] = "0", o[10] = "0";
    int year[2] = {0,0};
    int week[2] = {0,0};
    int flag;
    int date[2] = {0};
    char aux[10];
    int population = 0;

    while((opt = getopt(argc, argv,"hL:S:D:P:i:o: ")) != -1)
    {

        switch (opt)
        {
        /*Este "case" serve apenas para mostrar o menu ajuda da linha de coamandos sempre que o utilizador introduzir -h*/
        case 'h':
            CommandLineHelp();
            exit(0);
            break;
         /*Os "cases" que se seguem servem apenas para copiar os dados introduzidos pelo utilizador na linha de comandos para as
        variáveis do tipo char inicializadas acima para mais tarde o programa saber como reagir perante os dados inseridos*/
        case 'L':
            strcpy(L,optarg);
            break;

        case 'S':
            optind--;
            for(flag =0;optind < argc && (*argv[optind] != '-');optind++,flag++){
                switch(flag){
                    case 0:
                        strcpy(S,argv[optind]);
                        break;
                    case 1:
                        if(strcmp(S,"inf") == 0 || strcmp(S,"dea") == 0){
                            strcpy(aux,argv[optind]);
                            sscanf(aux,"%d-%d",&date[0],&date[1]);
                        }
                        break;
                }
            }
            break;

        case 'D':
            strcpy(D,optarg);
            break;

        case 'P':
            optind--;
            for(flag = 0;optind < argc && (*argv[optind] != '-');optind++,flag++){
                switch(flag){
                    case 0:
                        strcpy(P,argv[optind]);
                        break;
                    case 1:
                        if(strcmp(P,"date") == 0 || strcmp(P,"dates") == 0){
                            strcpy(aux,argv[optind]);
                            sscanf(aux,"%d-%d",&year[0],&week[0]);
                        }else if(strcmp(P,"min") == 0 || strcmp(P,"max") == 0){
                            population = atoi(argv[optind]);
                        }
                        break;
                    case 2:
                        if(strcmp(P,"date") == 0 || strcmp(P,"dates") == 0){
                            strcpy(aux,argv[optind]);
                            sscanf(aux,"%d-%d",&year[1],&week[1]);
                        }
                        break;
                }

            }


            break;

        case 'i':
            strcpy(i,optarg);
            break;

        case 'o':
            strcpy(o,optarg);
            break;
        }

    }
    Country *ListHead = NULL;
    /*Criação de um ponteiro que aponta para o tipo de estrutura Country - vai servir para
    criar novos nós da lista principal que, por sua vez, contém os diferentes países*/
    Country *newcountry;

    FILE *fp;
    /*Abertura para leitura do ficheiro criado que irá ter o título indicado*/
     if((fp = fopen(i,"r")) == NULL){
        printf("could not open the file");
        exit(EXIT_FAILURE);
     }

    char line[128];
    /*Usa-se um fgets para ignorar o cabeçalho*/
    fgets(line,128,fp);
    /*Este ciclo while que se segue vai percorrer linha a linha todo o ficheiro fornecido pelo professor e irá criar um
    novo nó da lista principal (a que contém os nomes dos países) sempre que encontarar uma linha com um nome de um
    país para o qual ainda não existe nó -> deste modo temos assim a nossa Lista principal criada*/
    while(fgets(line,128,fp) != NULL){
        if((newcountry = ReadFile(&ListHead,line)) != NULL){
            ListHead = CriaListaPorBaixo(ListHead,newcountry);
        }

    }
        fclose(fp);
    /*Estes if que se seguem indicam a forma como o programa reagirá perante as diferentes opções introduzidas
    pelo utilizador na linha de comandos -> esta diferentes opções podem ser consultadas mais abaixo na função
    "ComandLineHelp"*/
    if(strcmp(L,"all") == 0 ||
       strcmp(L,"Africa") == 0 ||
       strcmp(L,"Asia") == 0 ||
       strcmp(L,"Europe") == 0||
       strcmp(L,"Oceania") == 0 ||
       strcmp(L,"America") == 0){
        if (strcmp (S,"alfa") == 0 || strcmp (S,"pop") == 0){
            ListHead = BubbleSort(ListHead,S); //-S alfa -S pop
        }
        else if (strcmp (S,"inf") == 0 || strcmp (S,"dea") == 0){ 
            ListHead = SortTotal(ListHead,S,date); // -S inf date -S dea Date
        }
        else{
            printf("Erro: comando inserido inválido. \n");
            exit(0);
        }

        if((fp =fopen(o,"w")) == NULL){
            printf("could not open the file");
            exit(EXIT_FAILURE);
        }
        PrintLista(ListHead,L,D,P,population,year,week,fp);
        fclose(fp);
    }
    else{
        printf("Erro: comando inserido inválido. \n");
        CommandLineHelp();
        exit(0);
    }
    free_list(ListHead);
   

}

/*Função para a Linhas de Comandos - ajuda*/
void CommandLineHelp()
{
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
    printf("-i nome_do_ficheiro.dat -> Leitura de dados do ficheiro binário sendo que o nome_do_ficheiro é introduzido pelo utilizador.\n");
    printf("-o nome_do_ficheiro.csv -> Escrita de dados em ficheiro de texto sendo que o nome_do_ficheiro é introduzido pelo utilizador.\n");
    printf("-o nome_do_ficheiro.dat -> Escrita de dados em ficheiro binário sendo que o nome_do_ficheiro é introduzido pelo utilizador.\n");
}