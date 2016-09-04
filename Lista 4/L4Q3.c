#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Questao 3

int main()
{
    int valorLim, maiorNum, * lista, tamanho, i, j, h;


    lista = (int*) malloc (sizeof (int)); //lista com 1 espaco

    printf ("Numeros primos ate o valor desejado\n");
    printf("Digite um numero:\n");
    scanf ("%d", &valorLim); //coletar valor limite

    while (valorLim < 2){ //valor limite nao pode ser menor que 2
        printf ("numero invalido, digite novamente !");
        scanf ("%d", &valorLim);
    }

    maiorNum = (int) sqrt (valorLim); //ultimo numero a ser verificado

    tamanho = valorLim-2; //variavel pra controlar o tamanho do vetor
    lista = (int*) realloc (lista, tamanho*sizeof (int)); //definir o tamanho pro vetor


    for (i = 0, h = 2; h <= valorLim ; i++, h++){ //preencher o vetor de 2 ate o valor indicado
        lista[i] = h;
    }



    for (h = 0; lista [h] <= maiorNum; h++){
        for (i = lista[h], j=h+1; j <= tamanho ; j++){ //pegar o primeiro valor da lista e verificar os multiplos
            if (lista[j]%i == 0){
                lista [j] = 0; //multiplo do valor se torna 0
            }
        }

        for (j = h+1; j <= tamanho; j++){ //colocar os zeros pro final do vetor
            if (lista[j] == 0){
                for (i = j; i+1 <= tamanho ; i++){
                    lista[i] = lista[i+1];
                }
                tamanho--;
            }


        }
        lista = (int*) realloc (lista, tamanho*sizeof (int));//reallocar lista para o novo tamanho
    }

    for (i = 0; i <= tamanho; i++){ //imprimir a lista de numeros primos
        printf ("%d ", lista[i]);
    }

    free (lista);

    return 0;
}
