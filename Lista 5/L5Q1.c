#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente {
    char nome [81];
    int idade;
    char sexo;
    float altura;
    float peso;
    float ideal;

};
typedef struct paciente Paciente;

/*A funcao cria uma variavel do tipo paciente, inicializa as variaveis e retorna a variavel*/
Paciente f_cadastro (){
    Paciente cliente;

    printf ("\n\nDigite o nome do paciente:"); //coletar nome
    fflush (stdin);
    scanf ("%80[^\n]", &cliente.nome);

    printf ("\nDigite a idade:"); //coletar idade
    scanf ("%d", &cliente.idade);

    printf ("\nDigite o sexo (M F):"); //coletar sexo
    fflush (stdin);
    cliente.sexo = getchar();
    while ((cliente.sexo != 'M') && (cliente.sexo != 'm') && (cliente.sexo != 'F') && (cliente.sexo != 'f')){ //verificar se o caractere digitado e possivel
        printf ("sexo invalido, digite novamente:\n");
        printf ("\nDigite o sexo (M F):");
        cliente.sexo = getchar();
    }

    printf ("\n\nDigite a altura (em metros):"); //coletar altura
    scanf ("%f", &cliente.altura);

    printf ("\nDigite o peso (em kilos):"); //coletar peso
    scanf ("%f", &cliente.peso);

    if ((cliente.sexo == 'M') || (cliente.sexo == 'm')){ //calcular o peso ideal para homens
        cliente.ideal = (72.7*cliente.altura)-58;
    }
    else{ //calcular o peso ideal para mulheres
        cliente.ideal = (62.1*cliente.altura)-44.7;
    }

    printf ("\nNome: %s\nIdade:%d     Sexo:%c\nAltura:%.2f     Peso:%.2f\nPeso Ideal: %.2f\n\n", cliente.nome, cliente.idade, cliente.sexo, cliente.altura, cliente.peso, cliente.ideal);

    return cliente;
}

/*A funcao vai armazenar em um vetor os pacientes com o peso acima do ideal e vai exibir*/
void f_acimaPeso (Paciente* vetor, int cont, int tamanho){
        Paciente* acima;
        int contAcima, tamanhoAcima, i;

        contAcima = 0; //numero de elementos no vetor de pacientes acima do peso ideal
        tamanhoAcima = 1; //tamanho do vetor de pacientes acima do peso ideal
        acima = (Paciente*) malloc (sizeof (Paciente));

        if (cont ==0){ //caso nenhum paciente tenha sido registrado
            printf ("Nenhum Paciente foi registrado\n");
        }

        else{

            for (i = 0; i < cont; i++){ //laco para verificar os pacientes registrados
                if (vetor[i].ideal < vetor[i].peso){ //armazenar no vetor "acima" apenas os pacientes acima do peso ideal
                    if (contAcima == tamanhoAcima){ //verifica se o vetor esta cheio
                        tamanhoAcima++;
                        acima = (Paciente*) realloc (acima, tamanhoAcima*sizeof (Paciente));
                    }
                    strcpy (acima [contAcima].nome, vetor[i].nome);
                    acima [contAcima].idade = vetor[i].idade;
                    acima [contAcima].sexo = vetor[i].sexo;
                    acima [contAcima].altura = vetor[i].altura;
                    acima [contAcima].peso = vetor[i].peso;
                    acima [contAcima].ideal = vetor[i].ideal;
                    contAcima++;
                }
            }

            printf ("Pacientes acima do peso ideal\n");
            for (i=0; i<contAcima; i++){ //exibir os pacientes acima do peso ideal
                printf ("\nNome:%s\n", acima[i].nome);
                printf ("Idade:%d\n", acima[i].idade);
                printf ("Sexo:%c\n", acima[i].sexo);
                printf ("Altura:%.2f\n", acima[i].altura);
                printf ("Peso:%.2f\n", acima[i].peso);
                printf ("Peso Ideal:%.2f\n", acima[i].ideal);
                printf ("O paciente esta %.2f kilos acima do peso ideal\n", acima[i].peso-acima[i].ideal);
            }
        }

        printf ("\n");
        free (acima); //liberar o vetor
}

/*A funcao determina o nome e o peso do paciente mais pesado e exibe*/
void f_maisPesado (Paciente* vetor, int cont, int tamanho){
    Paciente maisPesado;
    int i;

    if (cont ==0){ //caso nenhum paciente tenha sido registrado
        printf ("Nenhum Paciente foi registrado\n");
    }

    else{
        maisPesado.peso = 0;
        for (i=0; i<cont; i++){ //verificar todos os pacientes registrados
            if (maisPesado.peso < vetor[i].peso){ //armazenar o paciente mais pesado
                strcpy (maisPesado.nome, vetor[i].nome);
                maisPesado.peso = vetor[i].peso;
            }
        }

        printf ("\nO Paciente mais pesado e:\n"); //exibir o paciente mais pesado
        printf ("Nome:%s\n", maisPesado.nome);
        printf ("Peso:%.2f\n\n", maisPesado.peso);
    }
}

/*A funcao vai armazenar em um vetor os pacientes com o peso acima do ideal e vai exibir*/
void f_abaixoPeso (Paciente* vetor, int cont, int tamanho){
        Paciente* abaixo;
        int contAbaixo, tamanhoAbaixo, i;


        contAbaixo = 0; //numero de elementos no vetor de pacientes acima do peso ideal
        tamanhoAbaixo = 1; //tamanho do vetor de pacientes acima do peso ideal
        abaixo = (Paciente*) malloc (sizeof (Paciente));

        if (cont ==0){ //caso nenhum paciente tenha sido registrado
            printf ("Nenhum Paciente foi registrado\n");
        }

        else{

            for (i = 0; i < cont; i++){ //laco para verificar os pacientes registrados
                if (vetor[i].ideal > vetor[i].peso){ //armazenar no vetor "acima" apenas os pacientes acima do peso ideal
                    if (contAbaixo == tamanhoAbaixo){ //verifica se o vetor esta cheio
                        tamanhoAbaixo++;
                        abaixo = (Paciente*) realloc (abaixo, tamanhoAbaixo*sizeof (Paciente));
                    }
                    strcpy (abaixo [contAbaixo].nome, vetor[i].nome);
                    abaixo [contAbaixo].idade = vetor[i].idade;
                    abaixo [contAbaixo].sexo = vetor[i].sexo;
                    abaixo [contAbaixo].altura = vetor[i].altura;
                    abaixo [contAbaixo].peso = vetor[i].peso;
                    abaixo [contAbaixo].ideal = vetor[i].ideal;
                    contAbaixo++;
                }
            }

            printf ("Pacientes abaixo do peso ideal\n");
            for (i=0; i<contAbaixo; i++){ //exibir os pacientes acima do peso ideal
                printf ("\nNome:%s\n", abaixo[i].nome);
                printf ("Idade:%d\n", abaixo[i].idade);
                printf ("Sexo:%c\n", abaixo[i].sexo);
                printf ("Altura:%.2f\n", abaixo[i].altura);
                printf ("Peso:%.2f\n", abaixo[i].peso);
                printf ("Peso Ideal:%.2f\n", abaixo[i].ideal);
                printf ("O paciente esta %.2f kilos abaixo do peso ideal\n", abaixo[i].ideal-abaixo[i].peso);
            }
        }
        printf ("\n");
        free (abaixo); //liberar o vetor
}

int main()
{
    Paciente* vetor;
    int menu, tamanho, cont;

    vetor = (Paciente*) malloc (sizeof (Paciente)); //allocar dinamicamente o cadastro dos usuarios
    tamanho = 1; //tamanho do vetor
    cont = 0; //elementos no vetor


    printf("Banco de dados da clinica\n\n");

    while (menu != 5){ //o programa so finaliza quando o usuario desejar

        printf ("Menu:\n1.Cadastrar Cliente\n");
        printf ("2.Determinar o nome do paciente mais pesado\n");
        printf ("3.Mostrar nomes e idades dos pacientes que estejam acima do peso ideal\n");
        printf ("4.Mostrar nomes dos pacientes que estejam abaixo do peso ideal\n");
        printf ("5.finalizar\n");
        scanf ("%d", &menu);    //coletar o menu

        while ((menu < 1) || (menu > 5 )){ //verificacao de possibilidade para o menu
            printf ("Menu invalido, digite novamente!\n");
            scanf ("%d", &menu);
        }

        switch (menu){
            case 1: if (cont == tamanho){ //verificar se o vetor de pacientes ja esta cheio
                        tamanho++;
                        vetor = (Paciente*) realloc (vetor, tamanho*sizeof (Paciente));
                    }

                    vetor[cont] = f_cadastro (); //cadastrar novo cliente
                    cont++; //mais um paciente

                    break;

            case 2: f_maisPesado (vetor, cont, tamanho);
                    break;

            case 3: f_acimaPeso (vetor, cont, tamanho);
                    break;

            case 4: f_abaixoPeso (vetor, cont, tamanho);
                    break;

            case 5: menu = 5;
                    break;

            default:printf ("Erro!\n");
                    break;
        }

    }

    free (vetor);
    return 0;
}
