#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Essa funcao vai transformar numero em caractere, porem o caractere vai estar na ordem inversa*/
void f_transformarString (int entrada, char* string)
{
    int resto, tamanho, cont, i;

    tamanho = 1; //tamanho da string

    for (cont = 0; entrada != 0; ){
        resto = entrada%10; //localizando o ultimo caractere

        string [cont] = resto + '0'; //armazenar na string como caractere
        cont++;
        entrada = entrada-resto; //retirar o ultimo numero
        entrada = entrada/10; //retirar o ultimo caractere

        if ((cont == tamanho) && (entrada != 0)){ //armazenar dinamicamente
            tamanho = tamanho*2;
            string = (char*) realloc (string, tamanho*sizeof (char));
        }
    }
    string [cont] = '\0'; //fechar string
}

/*Essa funcao inverte os caracteres de uma dada string*/
void f_inverterString (char* string)
{
    char* stringCopia; //string para auxiliar a copia
    int i, j, cont, tamanho; //variavel auxiliar

    tamanho = 1;
    stringCopia = (char*) malloc (sizeof(char)); //string comeca com tamanho 1;

    for (i = 0; string [i] != '\0'; i++){ //laço para saber o tamanho da string
    }
    i--;  //i posicao anterior ao '\0'

    cont = 0;
    for (j = 0; i >= 0; j++, i--){
        stringCopia [j] = string [i];  //os caraceteres finais da string original devem ser os caracteres iniciais da stringCopia
        cont++;

        if (cont == tamanho){
            tamanho = tamanho*2;
            string = (char*) realloc (string, tamanho*sizeof (char));
        }
    }
    stringCopia [j] = '\0';


    for (i = 0; stringCopia [i] != '\0' ; i++){ //laco para copiar os caracteres da stringCopia para a string original
        string [i] = stringCopia [i];
    }
    string [i] = '\0';
}

/*funcao verifica se uma string e palindroma, se for ela retorna 1, caso contrario retorna 0*/
int f_palindromo (char* string)
{
    int i, j, resposta;

    for (i=0; (string [i] != '\0') && (resposta != 0); i++){ //verificar tamanho da string
    }
    i--;

    resposta = 1;
    for (j = 0; (j < i) && (resposta == 1); j++, i--){
        if (string [j] == string [i]){ //verificar se os caracteres sao iguais
            resposta = 1; //1 para verdadeiro
        }
        else{
            resposta = 0; //0 para falso
        }
    }

    return resposta;
}


/*Funcao recebe um numero e transforma em binario numa string*/
void f_binario (int* numero, char* string)
{
    int i, cont, tamanho;

    tamanho = 1; //tamanho da string
    cont = 0; //contador para string

    if (*numero == 0){ //caso especial do algoritmo
        *string = '0';
    }

    else{
        for (i = 0; *numero != 0 ; i++){
            //verifica o tamanho primeiro
            if (cont == tamanho){ //reallocar de acordo com o tamanho
                tamanho = tamanho*2; //tamanho dobra
                string = (char*) realloc (string, tamanho*sizeof (char));
            }

            string [i] = (*numero%2) + '0';
            cont++; //mais uma posicao na string
            *numero = *numero/2;
        }
    }

    if (cont == tamanho){ //verifica se tem tamanho pra fechar string
        tamanho++;
        string = (char*) realloc (string, tamanho*sizeof (char));
    }

    cont++;
    string [cont] = '\0'; //fechar a string


    f_inverterString (string);
    free (numero);
}


int main()
{
    int entrada, inteiro, binario, palindromo, sub, i;
    char* string;
    int* vetorInt, cont, tamanho;

    printf("Digite um numero inteiro positivo:\n");
    scanf ("%d", &entrada);

    while (entrada < 0){  //numero de entrada deve ser positivo
        printf ("Numero invalido, digite novamente:\n");
        scanf ("%d", &entrada);
    }

    string = (char*) malloc (sizeof (char)); //string tamanho 1

    vetorInt = (int*) malloc (sizeof (int)); //tamanho inicial do vetor: 1
    tamanho = 1; //tamanho do vetor de inteiros
    cont = 0;    //contagem de elementos no vetor

    /* variavel entrada permanece constante*/
    for (sub = entrada; entrada-sub <= entrada; sub--){
        inteiro = entrada-sub;
        f_transformarString (inteiro, string); //transforma inteiro em string
        f_inverterString (string);              //inverte a string
        palindromo = f_palindromo (string);     //verifica se e palindromo

        if (palindromo == 1){

            if (cont == tamanho){                                            //se o vetor estiver cheio
                tamanho++;                                                  //aumentar um tamanho e
                vetorInt = (int*) realloc (vetorInt, tamanho*sizeof (int)); //realloca
            }
            vetorInt [cont] = inteiro; //inteiro palindromo e armazenado no vetor
            cont++;  //contagem do vetor
        }
    }

    printf ("Palindromos decimais:\n");
    for (cont = 0; cont < tamanho; cont++){ //imprime o vetor de inteiros
        printf ("%d\n", vetorInt [cont]);
    }

    free (vetorInt); //libera o vetor de inteiros

    printf ("\n\n");

    printf ("Palindromos Binarios:\n");

    /*Entrada permanece constante*/
    for (sub = entrada; entrada-sub <= entrada; sub--){
        binario = entrada-sub;
        f_binario (&binario, string); //transforma um numero em uma "string binaria"
        palindromo = f_palindromo (string); //verifica se e palindromo

        if (palindromo == 1){

            for (i = 0; string [i] != '\0'; i++){ //imprimir se for palindromo
                printf ("%c", string [i]);
            }
            printf ("\n");
        }
    }

    free (string); //libera string


    return 0;
}
