#include <stdio.h>
#include <stdlib.h>

//Questao 3

int main()
{
    int dia, mes, ano, hora, min, tempo; //A variavel 'tempo' e o tempo que ira passar

    printf ("Calculo de tempo\n");

    printf ("\nDigite uma data (dia mes ano)\n");
    scanf ("%d %d %d", &dia, &mes, &ano);

    printf ("\nDigite uma hora (hora min)\n");
    scanf ("%d %d", &hora, &min);

    printf ("\nDigite o tempo a ser decorrido\n");
    scanf ("%d", &tempo);

    if (min >= 60) {  //Teste de erro
        printf ("\nErro! minutos invalidos\n");
        return 0;
    }

    if (hora >= 24) { //Teste de erro
        printf ("\nErro! hora invalida\n");
        return 0;
    }

    if (dia > 30) { //Teste de erro
        printf ("\nErro! dia invalido\n");
        return 0;
    }

    if (mes > 12) { //Teste de erro
        printf ("\nErro! mes invalido\n");
        return 0;
    }

    min = min + tempo; //tempo digitado pelo usuario sera em minutos

    if (min >=60){  /*min nao pode ser igual ou maior que 60, caso, deve ser feita a divisao inteira por 60 e deve ser adicionada em hora, min deve ficar com o resto da divisao*/
        hora = hora + min/60;
        min = min%60;
    }

    if (hora >= 24) {  /*hora nao pode ser igual ou maior que 24, caso, deve ser feita a divisao inteira por 24 e deve ser adicionada em dia, hora deve ficar com o resto da divisao*/
        dia = dia + hora/24;
        hora = hora%24;
    }

    if (dia > 30) { /*dia nao pode passar de 30, se passar, deve ser feita a divisao inteira por 30 e deve ser adicionada em mes, dia deve ficar com o resto da divisao*/
        mes = mes + dia/30;
        dia = dia%30;
    }

    if (mes > 12) { /*mes nao pode passar de 12, se passar, deve ser feita a divisao inteira por 12 e deve ser adicionada em ano, mes deve ficar com o resto da divisao*/
        ano = ano + mes/12;
        mes = mes%12;
    }

    printf ("\n%d/%d/%d as %dh %d\n", dia, mes, ano, hora, min);



    return 0;
}
