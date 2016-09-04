#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Questao 1

int main()
{
    int random, entrada; //random e o numero a ser sorteado, entrada e o numero que o usuario vai digitar

    printf ("Adivinhe um numero !\n");

    srand ( time (NULL)); //para que o numero sorteado seja sempre diferente e que nao precise informar a semente
    random = rand () % 1000 + 1; //sorteando um numero entre 1 e 1000



    printf ("Digite um numero (entre 1 e 1000):");
    scanf ("%d", &entrada); //primeiro numero que o usuario digita

    while ((entrada > 1000) || (entrada < 0)){ //caso de erro
        printf ("\nNumero invalido! digite novamente:");
        scanf ("%d", &entrada);
    }

    while ((entrada != random) && (entrada != 0)) { //loop ate o usuario acertar o numero ou querer sair

        if (entrada > random) {  //para o numero digitado pelo usuario ser maior que o numero sorteado
            printf ("\nO numero esta abaixo! tente novamente:");
            scanf ("%d", &entrada);

                while ((entrada > 1000) || (entrada < 0)){ //caso de erro
                    printf ("\nNumero invalido! digite novamente:");
                    scanf ("%d", &entrada);
                }
        }

        else if (entrada < random){ //para o numero digitado pelo usuario ser menor que o numero sorteado
            printf ("\nO numero esta acima! tente novamente:");
            scanf ("%d", &entrada);

            while ((entrada > 1000) || (entrada < 0)){ //caso de erro
                    printf ("\nNumero invalido! digite novamente:");
                    scanf ("%d", &entrada);
                }
        }

    }

    if (entrada == random){
        printf ("\nExelente! voce adivinhou!\n");
    }

    return 0;
}
