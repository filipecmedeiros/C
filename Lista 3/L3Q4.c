#include <stdio.h>
#include <stdlib.h>

//Questao 4

void funcao_inserir (char palavra [], int posicao, char letra, char saida []){
    int contador, tamanho;

    for (contador = 0; palavra [contador] != '\0'; contador++){ //achando o numero de letras
    }
    tamanho = contador +1;

    for (contador = 0; contador < posicao; contador++){ //copiando os caracteres antes da posicao para a nova string
        saida [contador] = palavra [contador];
    }

    saida [posicao] = letra; //inserindo a letra na string

    for (contador = posicao; contador < tamanho; contador++){ //continuando a copiar o resto da string
        saida [contador+1] = palavra [contador];
    }



}

void funcao_remover (char palavra [], int posicao,  char saida []){
    int contador, tamanho;

    for (contador = 0; palavra [contador] != '\0'; contador++){ //achando o numero de letras
    }
    tamanho = contador +1;

    for (contador = 0; contador < posicao; contador++){ //copiando os caracteres antes da posicao para a nova string
        saida [contador] = palavra [contador];
    }                                                    //removeu o caractere

    for (contador = posicao; contador < tamanho; contador++){ //continuando a copiar o resto da string
        saida [contador] = palavra [contador +1];
    }
}

void funcao_substituir (char palavra [], int posicao, char letra,  char saida []){
    int contador, tamanho;

    for (contador = 0; palavra [contador] != '\0'; contador++){ //achando o numero de letras
    }
    tamanho = contador +1;

    for (contador = 0; contador < posicao; contador++){ //copiando os caracteres antes da posicao para a nova string
        saida [contador] = palavra [contador];
    }

    saida [posicao] = letra; //substituindo a letra na string

    for (contador = posicao; contador < tamanho; contador++){ //continuando a copiar o resto da string
        saida [contador+1] = palavra [contador+1];
    }
}

void funcao_alternar (char palavra [], int posicao, int constante,  char saida []){
    int contador, tamanho;

    for (contador = 0; palavra [contador] != '\0'; contador++){ //achando o numero de letras
    }
    tamanho = contador +1;

    for (contador = 0; contador < posicao; contador++){ //copiando os caracteres antes da posicao para a nova string
        saida [contador] = palavra [contador];
    }

    saida [posicao] = saida [posicao] + constante; //alterando a letra na string

    for (contador = posicao; contador < tamanho; contador++){ //continuando a copiar o resto da string
        saida [contador+1] = palavra [contador+1];
    }
}

int funcao_comparar (char palavra [],  char saida []){
    int contador, resposta;

    printf ("Digite uma palavra\n"); //pedir uma palavra para ser comparada lexicograficamente
    scanf ("%s", saida);

    for (contador = 0; ((resposta == 1) || (resposta == 0)); contador++){ //comparar letra por letra
        if (palavra [contador] > saida [contador]){
            resposta = 1; //1 para a palavra inicial ser depois
        }
        else if (palavra [contador] < saida [contador]){
            resposta = 0; //0 para a palavra inicial ser primeiro
        }
    }                   //se os caracteres forem iguais, contador e incrementado e volta pro if/else
    return resposta;
}

void funcao_concaternacao (char palavra [],  char saida []){
    char conc [21]; //tamanho max e 20
    int i, j;

    printf ("Digite uma palavra\n"); //coletando nova string
    scanf ("%s", conc);

    for (i = 0; palavra [i] != '\0';i++){ //copiando o inicio da palavra
        saida [i] = palavra [i];
    }

    for (j =0; saida [j] != '\0'; j++){ //copiando a nova string
        saida [j+i+1] = conc [j];
    }
    saida [ j+1] = '\0'; //fechando string
}

void funcao_copia (char palavra[], char saida []){ //funcao copia a string inicial para uma nova string para poder fazer as alteracoes
    int contador;

    for (contador = 0; saida [contador] != '\0'; contador++){ //copiar string
        palavra [contador] = saida [contador];
    }
    palavra [contador+1] = '\0'; //fechar string
}

int main()
{
    char palavra [21];
    char saida [51];
    int posicao, menu, constante, resposta;
    char letra;

    printf("Digite uma palavra\n");
    scanf ("%s", palavra);

    while (menu != 7){ //o usuario vai fazer mudancas ate finalizar

    printf ("Digite uma funcao:\n1.Inserir      2.Remover\n3.Substituir   4.Alternar\n5.Comparar     6.Concaternar\n      7.Finalizar\n"); //menu
    scanf ("%d", &menu);
        while ((menu < 1) || (menu > 7)){ //caso de menu invalido
            printf ("menu invalido ! digite novamente:\n");
            scanf ("%d", &menu);
        }

    switch (menu){
        case 1:     printf ("Digite uma posicao\n"); //coletando posicao
/*inserir*/         scanf ("%d", &posicao);

                    printf ("digite uma letra\n"); //coletando a letra
                    fflush(stdin);
                    scanf ("%c", &letra);

                    funcao_inserir (palavra, posicao, letra, saida); //chamada de funcao
                    funcao_copia (palavra, saida); //atualizar saida
                    break;

        case 2:     printf ("Digite uma posicao\n"); //coletando posicao
/*remover*/         scanf ("%d", &posicao);

                    funcao_remover (palavra, posicao, saida); //chamada de funcao
                    funcao_copia (palavra, saida); //atualizar saida
                    break;

        case 3:     printf ("Digite uma posicao\n"); //coletando posicao
/*substituir*/      scanf ("%d", &posicao);

                    printf ("digite uma letra\n"); //coletando letra
                    fflush(stdin);
                    scanf ("%c", &letra);

                    funcao_substituir (palavra, posicao, letra, saida);//chamada de funcao
                    funcao_copia (palavra, saida); //atualizar saida
                    break;

        case 4:     printf ("Digite uma posicao\n"); //coletando posicao
/*alternar*/        scanf ("%d", &posicao);

                    if ((palavra [posicao] >= 95) || (palavra [posicao] <= 122)){ //se for menuscula
                        constante = -32;
                    }

                    else if ((palavra [posicao] >= 65) || (palavra [posicao] <=90)){ //se for maiuscula
                        constante = 32;
                    }
                    else{        //nem maiuscula nem menuscula (nao faz nada)
                        constante = 0;
                    }

                    funcao_alternar (palavra, posicao, constante, saida); //chamada de funcao
                    funcao_copia (palavra, saida); //atualizar saida
                    break;


        case 5:     resposta = funcao_comparar (palavra, saida); //chamada de funcao
/*comparar*/
                    if (resposta == 1){
                        printf ("A palavra e lexicograficamente afrente\n");
                    }

                    else {
                        printf ("A palavra e lexicograficamente posterior\n");
                    }
                    funcao_copia (palavra, saida); //atualizar saida
                    break;

        case 6:     funcao_concaternacao (palavra, saida); //chamada de funcao
/*concaternacao*/   funcao_copia (palavra, saida); //atualizar saida
                    break;

        default:    menu = 7; //finalizar
/*finalizar*/       break;

        }
    }

    printf ("%s", saida); //imprimir resultado

    return 0;
    }
