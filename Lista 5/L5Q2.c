#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Questao 2

struct pagina{
    char http [51];
    char** tag;
    int numTag;
    int recomendar;
};
typedef struct pagina Pagina;

/*A funcao cria uma variavel do tipo pagina, inicializa e retorna a variavel*/
Pagina f_cadastro ()
{
    Pagina novaPagina;
    int i, j;

    void f_cadastrarTag (Pagina* novaPagina);//assinatura da funcao

    printf ("Digite o endereco da pagina:\n");
    fflush (stdin);
    scanf ("%50[^\n]", &novaPagina.http);//coletar endereco do site

    f_cadastrarTag (&novaPagina); //coletar as tags para o site

    novaPagina.recomendar = 0; //recomendacao do site inicia com 0

    return novaPagina; //retorna a nova pagina
}

/*A funcao cria dinamicamente um vetor de strings e armazena numa variavel do tipo pagina*/
void f_cadastrarTag (Pagina* nova)
{
    char tag[21]; //cada string tem no max. 20 caracteres
    int tamanho, i, j, cont;

    cont = 0; //contador de elementos no vetor de strings
    tamanho = 5; //tamanho do vetor de strings
    nova->tag = (char**) malloc (tamanho*sizeof(char*));
    for (i=0; i<tamanho; i++){
        nova->tag [i] = (char*) malloc (21*sizeof (char));
    }

    while (tag[0] != '0'){
        if (cont == (tamanho-1)){ //caso o vetor esteja cheio
            tamanho = tamanho+5;//realloca com mais 5 posicoes
            nova->tag = (char**) realloc (nova->tag, tamanho*sizeof (char*)); //reallocar para o vetor ter mais 5 posicoes
            for (j=0; (tamanho-j) != (tamanho-5); j++){
                nova->tag [tamanho-j-1] = (char*) malloc (21*sizeof (char)); //mallocar as ultimas 5 posicoes do vetor
            }
        }

        printf ("Digite a tag da pagina, 0 para finalizar\n");
        fflush (stdin);     //coletar tags
        scanf ("%20[^\n]", tag);

        printf ("\n");

        if (tag[0] != '0'){ //armazenar apenas se for diferente do caractere '0'
            for (j=0; tag[j] != '\0'; j++){ //copiar string para o vetor de string
                nova->tag[cont][j] = tag[j];
            }

            nova->tag[cont][j] = '\0'; //fechar string
            cont++; //mais um elemento no vetor
            }
    }

        nova->numTag = cont;
}


/*A funcao varre o vetor de paginas, procura se tem tags compativeis com a busca, se tiver,
armazena o indice da pagina em um vetor e pergunta ao usuario se ele deseja recomendar a pagina, caso queira,
e digitado o numero referente ao site e o site ganha um "nivel" de recomendacao*/
void f_busca (Pagina* web, int cont, int tamanhoPag){
    char pesquisa [21];
    int* vetor, compara, contVetor, tamanhoVetor;
    int menu, i, j;

    printf ("Busca:\n");
    fflush (stdin);
    scanf ("%20[^\n]", &pesquisa);

    vetor = (int*) malloc (sizeof (int)); //vetor para armazenar os indices das paginas recomendadas
    tamanhoVetor = 1;
    contVetor = 0;

    for (i=0; i<cont; i++){ //enquanto tiver paginas, verificar
        for (j=0; j<web[i].numTag; j++){ //enquanto tiver tags, verificar
            compara = strcmp (pesquisa, web[i].tag[j]); //compara as strings
            if (compara == 0){
                if (contVetor == tamanhoVetor-1){ //verifica se ha espaco no vetor
                    tamanhoVetor++;
                    vetor = (int*) realloc (vetor, tamanhoVetor);              //ERRO
                }
                vetor[contVetor] = i; //armazena o indice da pagina no vetor
                contVetor++; //mais um elemento no vetor
            }
        }
    }

    printf ("Digite o numero da pagina para recomendar, 0 para nao recomendar nenhuma\n\n");
    for (i=1, j=0; j<contVetor; i++, j++){
        printf ("%d.%s\n", i, web[vetor[j]].http);
    }
    scanf ("%d", &menu);

    while ((menu < 0) && (menu > (i-1))){ //verificar possibilidade
        printf ("Acao impossivel, digite novamente!\n");
        scanf ("%d", &menu);
    }

    if (menu != 0){
        web[vetor[menu-1]].recomendar++;
    }
    free (vetor);
}

/*A funcao procura no vetor de paginas a pagina mais recomendada e exibe*/
void f_melhorPagina (Pagina* web, int cont, int tamanhoPag)
{
    int melhor, aux, i, j;

    for (i = 0; i< cont; i++){ //laco para verificar a mais recomendada
        if (melhor < web[i].recomendar){
            melhor = web[i].recomendar;
            aux = i; //armazenar o indice da menos recomendada
        }
    }

    printf ("Melhor Pagina:%s\n", web[aux].http);

}

/*A funcao procura no vetor de paginas a pagina menos recomendada e exibe*/
void f_piorPagina (Pagina* web, int cont, int tamanhoPag)
{
    int melhor, aux, i, j;

    for (i = 0; i< cont; i++){ //laco para verificar a menor recomendacao
        if (melhor > web[i].recomendar){
            melhor = web[i].recomendar;
            aux = i; //armazenar o indice da menos recomendada
        }
    }

    printf ("Pior Pagina:%s\n", web[aux].http);

}


int main()
{
    Pagina* web;
    int menu, tamanhoPag, cont, i, j;

    cont = 0; //contador de elementos no vetor dinamico
    tamanhoPag = 5; //tamanho do vetor dinamico
    web = (Pagina*) malloc (tamanhoPag* sizeof (Pagina));

    while (menu != 5){ //o programa so finaliza quando o usuario desejar
        printf ("Menu:\n1.Cadastrar Pagina\n2.Buscar/Recomendar\n3.Melhor Pagina\n4.Pior Pagina\n5.Sair\n");
        scanf ("%d", &menu);

        while ((menu < 1) && (menu > 5)){ //verificar menu
            printf ("menu invalido, digite novamente!\n");
            printf ("Menu:\n1.Cadastrar Pagina\n2.Buscar/Recomendar\n3.Melhor Pagina\n4.Pior Pagina\n5.Sair\n");
            scanf ("%d", &menu);
        }

        switch (menu){
            case 1: if (cont == tamanhoPag){ //caso o vetor esteja cheio
    /*cadastro*/        tamanhoPag = tamanhoPag + 5;
                        web = (Pagina*) realloc (web, tamanhoPag*sizeof (Pagina));
                    }
                    web [cont] = f_cadastro (); //coletar nova pagina

                    printf ("%s\n", web[cont].http); //imprimir o endereco do site

                    for (i=0; i < web[cont].numTag; i++){ //imprimir as tags do site
                        printf ("tag:%s\n", web[cont].tag[i]);
                    }
                    cont++;

                    printf ("Site registrado com sucesso!\n");
                    break;

            case 2:f_busca (web, cont, tamanhoPag);
/*Recomendar Pagina*/break;

            case 3: f_melhorPagina (web, cont, tamanhoPag);
/*Melhor Pagina*/   break;

            case 4: f_piorPagina (web, cont, tamanhoPag);
/*Pior Pagina*/     break;

            case 5: menu = 5;
        /*Sair*/    break;

            default: printf ("Erro!\n");
                     break;
        }
    }

    free (web);
    return 0;
}
