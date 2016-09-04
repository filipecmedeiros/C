#include <stdio.h>
#include <stdlib.h>


/*Funcao separa o tamanho para um ponteiro*/
void f_vagao (int** vetor, int* tamanho)
{
    int** vetor2, i;

    vetor2 = (int**) malloc (sizeof (int*));
    vetor2 [0] = (int*) malloc (2*sizeof (int));

    *tamanho++;

    vetor [0][*tamanho] = &vetor[0][0];
}


int main ()
{
    int numero, ** vetor, destino, tamanho, i, j, validar;

    vetor = (int**) malloc (sizeof (int*));
    vetor [0] = (int*) malloc (2*sizeof (int));


    tamanho = 1; //tamanho do vetor


    printf ("Digite o numero de vagoes do trem: (   1<= N <= 15   ) \n");
    scanf ("%d", &numero);

    while ((numero < 1) || (numero > 15)){ //verificacao para o numero de vagoes
        printf ("numero invalido, digite novamente!\n");
        scanf ("%d", &numero);
    }

    for (i = 0; i < numero; i++){ //alocar espaco pros vetores
        f_vagao (vetor, &tamanho);
    }


    for (i = (numero-1); i >= 0; i--){ //coletar id dos vagoes

        printf ("Digite o ID do vagao %d:\n", i+1); //coletar o id de tras pra frente
        scanf ("%d", &vetor [0][i]);

        while ((vetor[0][i] > 99) || (vetor [0][i] < 1)){ //id do vagao nao pode ser menor que 1 ou maior que 99
            printf ("ID invalido, digite novamente!\n");
            scanf ("%d", &vetor[0][i]);
        }

        while (validar != 0){
            for (j = (numero-1); j > i; j--){
                if (vetor [0][i] == vetor [0][j]){
                    printf ("ID invalido, digite novamente!\n");
                    scanf ("%d", &vetor[0][i]);
                    validar = 0;
                }
            }
            validar = 1;
        }
    }


    printf ("Digite o vagao destino:\n");
    scanf ("%d", &destino);

    for (i = (numero-1); i >= 0; i--){ //imprimir vetor
        printf ("%d ", vetor [0][i]);
    }




    return 0;
}
