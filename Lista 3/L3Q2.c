#include <stdio.h>
#include <stdlib.h>

//Questao 2

int main()
{
    int entrada [12] = {0};
    int saida [12] = {0};
    int final [12] = {0};
    int contador, auxiliar, verificador;


    printf("Digite uma sequencia musical:\n");

    for (contador  = 0; contador < 12; contador++){ //coletando a sequencia
        scanf ("%d", &auxiliar);
        entrada [auxiliar] = contador;

        while ( (auxiliar < 0) || (auxiliar > 11) ){ //caso de erro
            printf ("sequencia invalida, digite novamente\n");
            scanf ("%d", &auxiliar);
            entrada [auxiliar] = contador;
        }
    }

    printf ("\n"); //pular uma linha

    auxiliar = 0;  //Serie retrograda: o vetor de saida deve receber o idice "final" menos o valor contido no indice "inicial" mais o indice correspondente
    for (contador = 11; contador >= 0; contador--){
        saida [auxiliar] = contador - entrada [auxiliar] + auxiliar;
        auxiliar++;
    }

    for(auxiliar = 0, contador = 0; auxiliar < 12; auxiliar++){ //encontrando os indices de acordo com a ordem
        for(contador = 0; contador < 12; contador++){
                if(saida[auxiliar] == 0 + contador){
                    final[contador] = auxiliar;
                }
        }
    }

        for (contador = 0; contador < 12; contador++){ //Imprimir saida
            printf ("%d ", final [contador]);
    }



    return 0;
}
