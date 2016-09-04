#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct corredor{
    char nome [21];
    int voltas;
    struct corredor* prox;
}Corredor;

/*A funcao vai criar uma lista encadeada e vai inicializar os corredores com o nome (strNome)
 e o numero de voltas (voltasCorrida)*/
Corredor* f_cria_corredor (int voltasCorrida, char strNome [21], Corredor* inicio)
{
    Corredor* novo;
    Corredor* cpyLista;

    novo = (Corredor*) malloc (sizeof (Corredor));

    strcpy (novo->nome, strNome); //inicializa o nome do corredor
    novo->voltas = voltasCorrida; //inicializa o numero de voltas na corrida
    novo->prox = NULL;

    if (inicio == NULL){
        inicio = novo;
    }

    else{
        cpyLista = inicio; //localizar o final da lista encadeada

        while (cpyLista->prox != NULL){
            cpyLista = cpyLista->prox;
        }
        cpyLista->prox = novo; //adiciona o novo corredor ao final da lista encadeada
    }

    return inicio;
}

/*A funcao imprime a lista encadeada circular*/
void f_imprime_status (Corredor* inicio)
{
    Corredor* p, *h;

    p = inicio, h= inicio; //lista encadeada circular

    if (p != NULL){
    do{

        printf ("Nome:%s\nVoltas:%d\n--------\n", p->nome, p->voltas);
        p = p->prox;


        }while (p != h); //imprimir todos os corredores
    }
}


/*A funcao completa (diminui) 1 volta do corredor que estier mais proximo da largada*/
Corredor* f_volta (Corredor* largada)
{
    if (largada->voltas == 0){
        printf("Impossivel completar volta\n");
    }
    else{
        largada->voltas--; //numero de voltas e subtraído
        largada = largada->prox; //o corredor mais proximo da largada e o proximo
    }
    return largada;
}


/*A funcao vai fazer uma ultrapassagem entre dois corredores, dados os nomes*/
Corredor* f_ultrapassagem (Corredor* inicio, Corredor* largada, char* corredor1, char* corredor2)
{
    Corredor *p, *u, *q;
    int comp;

    comp = 1;
    comp = strcmp (inicio->nome, corredor1);

    if (comp == 0){ //caso o primeiro seja ultrapassado
        p = inicio;
        inicio = inicio->prox;
        p->prox = inicio->prox;
        inicio->prox = p;

        printf ("Lider = %s\n------\n", inicio->nome); //exibir lider
    }

    else{
        p = inicio;
        while (comp != 0){ //localizar o carro que sera ultrapassado
            comp = strcmp (p->nome, corredor1);
            if (comp != 0){
                p = p->prox;
            }
        }

        if (p == largada){

            for (u = inicio; u->prox != p; u = u->prox){ //localizar 'u' na posicao anterior ao corredor q sera ultrapassado
            }
            largada = p->prox;
            p->prox = largada->prox;
            largada->prox = p;
            u->prox = largada;
        }

        else{

            for (u = inicio; u->prox != p; u = u->prox){
            }

            q = p->prox;
            p->prox = q->prox;
            q->prox = p;
            u->prox = q;
        }
    }


    return inicio;
}


/*A funcao reconhece o comando do arquivo e  */
void f_comando (FILE* fp, Corredor* inicio, Corredor* largada, Corredor* quebrou)
{
    char str1 [21], str2[21], str3[21];
    Corredor* p;
    int i, fim;
    FILE* fa;

    fa = fopen ("L6Q3.out", "w");

    for (fim = 0;fim != EOF ; ){  //ate o ultimo corredor passar pela chegada ou quebrar
        fim = fscanf (fp, "%s", str1); //coleta comando

        i=1;
        i = strcmp (str1, "Lider");

        if (i == 0){ //comando de "lider"
            fprintf (fa, "Lider = %s\n\n", inicio->nome); //gravar no arquivo de saida
            printf ("Lider = %s\n------\n", inicio->nome); //exibir
        }

        else{
            i = strcmp (str1, "Volta");
            if (i == 0){ //comando de "volta"
                largada = f_volta(largada);


            }

            else{
                fim = fscanf (fp, "%s", str2);

                i = strcmp (str2, "Passou");
                if (i == 0){ //comando de "ultrapassagem"
                    fim = fscanf (fp, "%s", str3);
                    inicio = f_ultrapassagem(inicio, largada, str1, str3);


                }

                else{ //comando "quebrou"
                    //f_quebra (inicio, largada, quebrou, str1);
                }
            }
        }
    }

    p = inicio;
    i = 1;

    do{

    fprintf (fa, "%d.", i); //gerar o arquivo de saida
    fprintf (fa, "%s\n", p->nome);

    i++;
    p = p->prox;
    }while (p!= inicio);


    p = quebrou;
    i = 1;
    while (p != NULL){
        fprintf (fa, "Quebrou %d", i); //carros quebrados
        fprintf (fa, "%s\n", p->nome);

        i++;
        p = p->prox;
    }



}


/*A funcao recebe como parametro a lista encadeada circular de carros na corrida, a lista de carros quebrados e o nome do corredor que quebrou,
retira o corredor da corrida e coloca na lista de corredores quebrados*/
void f_quebra (Corredor* inicio, Corredor* largada, Corredor* quebrou, char* str1)
{
    Corredor *novo, *d;
    int compara;

    compara = 1;
    for (novo = inicio; novo != inicio; ){ //achar o corredor que quebrou
        compara = strcmp (novo->nome, str1); //-----------------------------------------> Erro ! nao captura string composta
        if (compara != 0){
            novo = novo->prox;
        }
    }


    if (novo == inicio){ //caso o primeiro colocado quebre
        inicio = inicio->prox; //o primeiro colocado é o proximo

        for (d = inicio; d->prox != novo; d=d->prox){ //achar o corredor anterior ao que quebrou (lista encadeada)
        }

        d->prox = inicio;
        novo->prox = NULL;
    }

    else if (novo == largada){ //caso o corredor mais proximo da largada quebre
        largada = largada->prox; //o corredor mais proximo da largada é o proximo

        for (d = inicio; d->prox != novo; d=d->prox){ //achar o corredor anterior ao que quebrou
        }

        d->prox = largada;
        novo->prox = NULL;
    }


    if (quebrou == NULL){ //se a lista de carros quebrados estiver vazia
        quebrou = novo;
    }

    else{

        for (d = quebrou; d->prox != NULL; d = d->prox){ //se nao estiver vazia, localiza a ultima posicao
        }

        d->prox = novo; //adiciona o novo carro quebrado a lista;
    }
}



int main()
{
    FILE* fp;
    int voltasCorrida, nCorredores, i;
    char str1 [21];
    Corredor* inicio, *largada, *quebrou, *p;

    inicio = NULL;
    quebrou = NULL;

    fp = fopen ("L6Q3.in", "r"); //abrir o arquivo de modo leitura

    if (fp == NULL){ //verifica se o arquivo foi aberto corretamente
        printf ("Erro ao abrir o arquivo");
        exit (1);
    }

    fscanf (fp, "%d", &nCorredores); //le do arquivo o numero de voltas da corrida
    fscanf(fp, "%d", &voltasCorrida); //le do arquivo o numero de corredores

    printf ("Numero de corredores:%d\n", nCorredores);
    printf ("Numero de voltas:%d\n\n", voltasCorrida);

    for (i=0 ; i < nCorredores; i++) //inicializar todos os corredores
    {
        fscanf (fp, " %[^\n]s", str1); //coleta o nome do corredor no arquivo
        inicio = f_cria_corredor(voltasCorrida, str1, inicio); //cria o corredor com o numero de voltas
    }

    p = inicio; //p é um "cursor"
    while (p->prox != NULL){ //localizar no final da lista encadeada
        p = p->prox;
    }
    p->prox = inicio; //lista encadeada circular

    largada = inicio; //inicio é o primeiro na corrida, largada é o corredor mais proximo à linha de chegada

    f_imprime_status(inicio);

    f_comando (fp, inicio, largada, quebrou);


    f_imprime_status(inicio);

    f_imprime_status(quebrou);

    fclose (fp); //fechar arquivo

    return 0;
}
