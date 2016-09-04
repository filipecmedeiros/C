#include <stdio.h>
#include <stdlib.h>

//Questao 4

int main()
{
    int salario, mes, horas;
    float MediaDiaria, valor1, valor2, valor3; // valor3 sera o valor final, valor2 e valor1 ira auxiliar o calculo

    printf ("\nPrograma de idenizacao ao trabalhador\n");

    printf ("\nDigite o Salario do funcionario\n");
    scanf ("%d", &salario);

    printf ("\nDigite o tempo (em meses) que ele trabalhou\n");
    scanf ("%d", &mes);

    printf ("\nDigite a quantidade de horas que ele trabalhou\n");
    scanf ("%d", &horas);


    MediaDiaria = horas/(mes*30);

    if (MediaDiaria >= 24) { //A media diaria de trabalho nao pode ser superior a 24 horas
        printf ("Erro! Quantidade de horas invalida");
    }

    if (salario < 500) { //Se o salario for inferior a 500, deve ser aumentado em 120%
        valor1 = salario *2.2;
    }

    else if ((salario >= 500) && (salario <= 1500)) { //Se o salario estiver entre 500 e 1500, deve ser aumentado em 250%
        valor1 = salario*3.5;
    }

    else if (salario >1500) { //Se o salario for maior que 1500, deve ser aumentado em 350%
        valor1 = salario*4.5;
    }

    if (MediaDiaria < 6) { //Se a media diaria for menor que 6 horas, aumente 10% do ultimo valor obtido
        valor2 = valor1 *1.1;
    }

    if ((MediaDiaria >= 6) && (MediaDiaria <=8)){ //Se a media diaria estiver entre 6 a 8 horas, aumente 15% do ultimo valor obtido
        valor2 = valor1 *1.15;
    }

    if (MediaDiaria >8) { //Se a media diaria for maior que 8 horas, aumente 25% do ultimo valor obtido
        valor2 = valor1 *1.25;
    }

    if (mes <= 3) { //Se os meses trabalhados for menor ou igual a 3 meses, decresça 25% do ultimo valor obtido
        valor3 = valor2 *0.75;
    }

    if ((mes > 3) && (mes < 7)){ //Se os meses trabalhados for superior a 3 meses e inferior a 7 meses, aumente 10% do ultimo valor obtido
        valor3 = valor2 *1.1;
    }

    if (mes >=7) { //Se os meses trabalhados for de 7 meses ou mais, aumente 15% do ultimo valor obtido.
        valor3 = valor2 *1.15;
    }

    printf ("\nO valor da idenizacao foi de: %f\n", valor3);


    return 0;
}
