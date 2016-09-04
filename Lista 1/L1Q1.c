#include <stdio.h>
#include <stdlib.h>

// Questao 1

int main()
{
    int ValorSaque, nota100, nota50, nota20, nota10, nota5, nota2, nota1; //ValorSaque e o valor de entrada

    printf ("Digite o valor de saque:\n");
    scanf ("%d", &ValorSaque);

    if (ValorSaque > 0) {  /* o numero de cedulas que devera chegar ao cliente e o menor possivel */

        nota100 = ValorSaque/100; //colocar o maior numero de cedulas de 100 (se possivel)
        nota50 = (ValorSaque-nota100*100)/50;  //o maior numero de cedulas de 50 devera ser o valor inicial menos a quantidade de cedulas de 100

        nota20 = (ValorSaque-nota50*50-nota100*100)/20; //o modelo para calcular o numero de cedulas de 50 se repete nas demais...
        nota10 = (ValorSaque-nota20*20-nota50*50-nota100*100)/10;

        nota5 = (ValorSaque-nota10*10-nota20*20-nota50*50-nota100*100)/5;
        nota2 = (ValorSaque-nota5*5-nota10*10-nota20*20-nota50*50-nota100*100)/2;

        nota1 = (ValorSaque-nota2*2-nota5*5-nota10*10-nota20*20-nota50*50-nota100*100);


        /* As funcoes adiante servem para mostrar na saida apenas as cedulas necessarias*/

        if (nota100 >= 1){
            printf ("Cedulas de 100:%d\n", nota100);
        }

        if (nota50 >= 1) {
            printf ("\nCedulas de 50:%d\n", nota50);
        }

        if (nota20 >= 1){
            printf ("\nCedulas de 20:%d\n", nota20);
        }

        if (nota10 >= 1) {
            printf ("\nCedulas de 10:%d\n", nota10);
        }

        if (nota5 >= 1) {
            printf ("\nCedulas de 05:%d\n", nota5);
        }

        if (nota2 >= 1) {
            printf ("\nCedulas de 02:%d\n", nota2);
        }

        if (nota1 >= 1) {
            printf ("\nCedulas de 01:%d\n", nota1);
        }

    }


    else {

        printf ("\nSaque impossivel\n");
    }

    return 0;
}
