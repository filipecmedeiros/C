#include <stdio.h>
#include <stdlib.h>

//Questao 3

int funcao_fatorial (float n){ //funcao para calcular um fatorial
    float fatorial;

    if ((n == 0) || (n==1)){ //caso base
        fatorial = 1;
    }

    else { //recursao
        fatorial = n*funcao_fatorial (n-1);
    }

    return fatorial;

}


int funcao_combinatoria (float a, float b) { //funcao para analise combinatoria
    int combinacao;

    combinacao = funcao_fatorial(a) / funcao_fatorial(a-b)*funcao_fatorial(b);

    return combinacao;
}

int main()
{
    int total, escolha;
    float verde, azul, probabilidade, combinacao1, combinacao2;

    printf("Digite o numero total de bolas\n");
    scanf ("%d", &total);

    printf ("Digite a porcentagem de bolas verdes\n");
    scanf ("%f", &verde);

    printf ("Digite a porcentagem de bolas azuis\n");
    scanf ("%f", &azul);

    while (verde + azul != 100) { //caso de erro
        printf ("Erro! porcentagem invalida!\n");

        printf ("Digite a porcentagem de bolas verdes\n");
        scanf ("%f", &verde);

        printf ("Digite a porcentagem de bolas azuis\n");
        scanf ("%f", &azul);
    }

    printf ("Digite o numero de bolas a serem escolhidas aleatoriamente\n");
    scanf ("%d", &escolha);

    while (escolha > total) { //caso de erro
        printf ("Erro! numero de bolas escolhidas invalidas, digite novamente:\n");
        scanf ("%d", &escolha);
    }

    azul = azul*total*0.01; //extraindo o numero de bolas azuis
    verde = verde*total*0.01; //extraindo o numero de bolas verdes



    combinacao1 = funcao_combinatoria (total, verde);
    combinacao2 = funcao_combinatoria (total, escolha);


    probabilidade = ((combinacao2-combinacao1)/combinacao2)*100; //combinacao simples
    printf ("A probabilidade de sair ao menos uma bola azul e: %.2f%%", probabilidade);



    return 0;
}
