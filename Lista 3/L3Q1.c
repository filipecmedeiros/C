#include <stdio.h>
#include <stdlib.h>

//Questao 1

int main()
{
    int vetor_ent [11] = {0}; //vetor de entrada
    int vetor_ext [11] = {0}; //vetor de saida
    int cont, div, soma; //div e a variavel para verificar os numeros divisiveis
                         //soma e a soma dos numeros divisiveis


    printf("Digite 10 valores inteiros ( entre 0 e 100.000 )\n");

    for (cont = 0; cont < 10; cont++){ //coletando 10 numeros inteiros positivos
        scanf ("%d", &vetor_ent [cont]);

        while ((vetor_ent [cont] < 0) || (vetor_ent [cont] > 100000)) { //caso de erro (o numero deve ser positivo e menor que 100.000)
            printf ("numero invalido, digite novamente\n");
            scanf ("%d", &vetor_ent [cont]);
        }

        soma = 0; //soma dos numeros divisiveis
        for (div = 1; div < vetor_ent[cont]; div++){ //loop para verificar a soma dos numeros divisiveis pelo numero digitado
            if (vetor_ent [cont] % div == 0){ //verifica os numeros divisiveis e soma
                soma = soma + div;
            }
        }

        if (vetor_ent [cont] == soma) { //gravar no vetor de saida os numeros perfeitos
            vetor_ext [cont] = cont;
        }

        }

        printf ("Indice dos numeros perfeitos: "); //exibir os indices dos numeros perfeitos
        printf ("%d  ", vetor_ext [cont]); //o numero perfeito pode estar no primeiro indice (0)
        for (cont = 1; cont < 11; cont++) //imprimir todos os valores do vetor de saida
            if (vetor_ext [cont] != 0) { //condicao para nao imprimir 0's
            printf ("%d  ", vetor_ext [cont]);
            }


    return 0;
}
