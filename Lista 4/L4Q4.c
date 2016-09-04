#include <stdio.h>
#include <stdlib.h>


void f_fruta (int* galpao, int tamanho, int*vetor)
{
    int* fruta;
    int i, caixas, qtdFruta;

    galpao = (int*) realloc (galpao, tamanho*sizeof (int));

    galpao [tamanho] = vetor;
    vetor [0] = fruta;

    printf ("Digite o nome da fruta:\n");
    fflush (stdin);
    scanf ("%s", &*fruta);

    printf ("Digite a quantidade da fruta:\n");
    scanf ("%d", &qtdFruta);
    vetor[1] = qtdFruta;

    printf ("Digite a capacidade das caixas:\n");
    scanf ("%d" &vetor[2]);

    caixas = (vetor[1]/vetor[2])+1;
    vetor = (int*) realloc (vetor, caixas*sizeof (int));

    for (i =3; qtdFruta < = caixas; i++){
        vetor [i] = caixas;
        qtdFruta = qtdFruta - caixas;
    }
    vetor [i] = qtdFruta;

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
