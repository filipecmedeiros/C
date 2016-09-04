#include <stdio.h>
#include <stdlib.h>

//Questao 2

float funcao_media (int semana, int MarcacaoDeDia) { //funcao que calcula a media do lucro para determinado dia de acordo com o numero de dias que tiveram
    int contador = 0;
    float media = 0;
    float lucro;

    printf ("\nDigite os lucros obtidos durante as %das\n", MarcacaoDeDia);

    while (contador < semana){ //vai somar os lucros durante os dias
        scanf ("%f", &lucro);
            while (lucro < 0){ //caso de erro
                printf ("lucro invalido, digite novamente:");
                scanf ("%f", &lucro);
            }
        media = media + lucro; //calcula uma pseudo-media
        contador = contador +1;
        }

    return media/semana; //retorna a media real
    }

int funcao_dia (){ //funcao identifica o dia na semana q vai receber desconto
    int dia;

    printf ("\nQual dia na semana ira receber desconto ?\n");
    printf ("1.segunda    2.terca    3.quarta    4.quinta      5.sexta\n");
    scanf ("%d", &dia);

    while ( (dia < 1) || (dia > 5)){ //caso de erro
    printf ("Dia invalido, Digite novamente");
    scanf ("%d", &dia);
    }

    return dia;
}

float funcao_desconto (){ //funcao identifica o desconto
    float desconto;

    printf ("Digite o percentual de desconto:");
    scanf ("%f", &desconto);

    while ((desconto <= 0) && (desconto >100)){ //caso de erro
        printf ("\nDesconto invalido, digite novamente:");
        scanf ("%f", desconto);
    }

    return desconto;
}

int main()
{
    int semana, dia, menu, MarcacaoDeDia;
    float desconto, segunda, terca, quarta, quinta, sexta;


    printf ("Digite o numero da semana ( 2 < semana <= 16 ):\n");
    scanf ("%d", &semana);

    while ( (semana <= 2)|| (semana > 16)){ //caso de erro
        printf ("\nSemana invalida, digite novamente:\n");
        scanf ("%d", &semana);
    }

    MarcacaoDeDia = 2;
    segunda = funcao_media (semana, MarcacaoDeDia); //calcula a media na segunda

    MarcacaoDeDia = 3;
    terca = funcao_media (semana, MarcacaoDeDia); //calcula a media na terca

    MarcacaoDeDia = 4;
    quarta = funcao_media (semana, MarcacaoDeDia); //calcula a media na quarta

    MarcacaoDeDia = 5;
    quinta = funcao_media (semana, MarcacaoDeDia); //calcula a media na quinta

    MarcacaoDeDia = 6;
    sexta = funcao_media (semana, MarcacaoDeDia); //calcula a media na sexta

    printf ("Media na segunda:%.2f   Terca:%.2f   Quarta:%.2f   Quinta:%.2f   Sexta:%.2f", segunda, terca, quarta, quinta, sexta);


    desconto = funcao_desconto(); //identifica o desconto
    dia = funcao_dia(); //identifica o dia que vai receber desconto

    switch (dia) { //calcula o desconto para o determinado dia
        case 1: segunda = segunda + segunda*( (1.2*desconto)*0.01); //desconto na segunda
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 2: segunda = segunda - segunda*( (desconto*0.5)*0.01); //desconto na terca
                terca = terca + terca*( (1.2*desconto)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 3: segunda = segunda - segunda*( (desconto*0.5)*0.01); //desconto na quarta
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta + quarta*( (1.2*desconto)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 4: segunda = segunda - segunda*( (desconto*0.5)*0.01); //desconto na quinta
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta + quinta*( (1.2*desconto)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 5: segunda = segunda - segunda*( (desconto*0.5)*0.01); //desconto na sexta
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta + sexta*( (1.2*desconto)*0.01);
                break;

        default:    printf ("Erro!\n");
    }

    printf ("Segunda:%.2f   Terca:%.2f   Quarta:%.2f   Quinta:%.2f   Sexta:%.2f\n", segunda, terca, quarta, quinta, sexta);



    printf ("Digite:\n1.Estou satisfeito\n2.Alterar desconto\n3.Alterar dia com desconto\n4.continuar assim\n"); //menu
    scanf ("%d", &menu);

        while ( (menu < 1) || (menu > 4) ){ //menu invalido
        printf ("Resposta invalida, digite novamente:\n");
        scanf ("%d", &menu);
        }

    while (menu != 1) { //caso o menu seja 1, o programa finaliza

        if (menu == 2) { //alterar desconto
                desconto = funcao_desconto();

                switch (dia) { //calcula desconto para o dia
        case 1: segunda = segunda + segunda*( (1.2*desconto)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 2: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca + terca*( (1.2*desconto)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 3: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta + quarta*( (1.2*desconto)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 4: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta + quinta*( (1.2*desconto)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 5: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta + sexta*( (1.2*desconto)*0.01);
                break;

        default:    printf ("Erro!\n");
    }

                if ( (segunda == 0) || (terca == 0) || (quarta == 0) || (quinta == 0) || (sexta == 0)){ //caso de falencia
                    printf ("Falencia\n");
                    menu = 1;
                }
                else { //se nao for a falencia, volta pro menu
                    printf ("Segunda:%.2f   Terca:%.2f   Quarta:%.2f   Quinta:%.2f   Sexta:%.2f\n", segunda, terca, quarta, quinta, sexta);
                    printf ("Digite:\n1.Estou satisfeito\n2.Alterar desconto\n3.Alterar dia com desconto\n4.continuar assim\n");
                    scanf ("%d", &menu);

                    while ( (menu < 1) || (menu > 4) ){ //menu invalido
                        printf ("Resposta invalida, digite novamente:\n");
                        scanf ("%d", &menu);
                    }
                }
        }

        else if (menu == 3) { //alterar dia com desconto
            dia = funcao_dia(); //identifica o novo desconto

             switch (dia) { //calcula o desconto para o novo dia
        case 1: segunda = segunda + segunda*( (1.2*desconto)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 2: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca + terca*( (1.2*desconto)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 3: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta + quarta*( (1.2*desconto)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 4: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta + quinta*( (1.2*desconto)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 5: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta + sexta*( (1.2*desconto)*0.01);
                break;

        default:    printf ("Erro!\n");
    }

                if ( (segunda == 0) || (terca == 0) || (quarta == 0) || (quinta == 0) || (sexta == 0)){ //caso de falencia
                    printf ("Falencia\n");
                    menu = 1;
                }
                else { //se nao for a falencia, volta pro menu
                    printf ("Segunda:%.2f   Terca:%.2f   Quarta:%.2f   Quinta:%.2f   Sexta:%.2f\n", segunda, terca, quarta, quinta, sexta);
                    printf ("Digite:\n1.Estou satisfeito\n2.Alterar desconto\n3.Alterar dia com desconto\n4.continuar assim\n");
                    scanf ("%d", &menu);

                    while ( (menu < 1) || (menu > 4) ){ //menu invalido
                        printf ("Resposta invalida, digite novamente:\n");
                        scanf ("%d", &menu);
                    }
                }
        }

        else if (menu == 4){ //continua a calcular
             switch (dia) { //calcula novamente
        case 1: segunda = segunda + segunda*( (1.2*desconto)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 2: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca + terca*( (1.2*desconto)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 3: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta + quarta*( (1.2*desconto)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 4: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta + quinta*( (1.2*desconto)*0.01);
                sexta = sexta - sexta*( (desconto*0.5)*0.01);
                break;

        case 5: segunda = segunda - segunda*( (desconto*0.5)*0.01);
                terca = terca - terca*( (desconto*0.5)*0.01);
                quarta = quarta - quarta*( (desconto*0.5)*0.01);
                quinta = quinta - quinta*( (desconto*0.5)*0.01);
                sexta = sexta + sexta*( (1.2*desconto)*0.01);
                break;

        default:    printf ("Erro!\n");
        }

                if ( (segunda == 0) || (terca == 0) || (quarta == 0) || (quinta == 0) || (sexta == 0)){ //caso de falencia
                    printf ("Falencia\n");
                    menu = 1;
                }
                else { //se nao for a falencia, volta pro menu
                    printf ("Segunda:%.2f   Terca:%.2f   Quarta:%.2f   Quinta:%.2f   Sexta:%.2f\n", segunda, terca, quarta, quinta, sexta);
                    printf ("Digite:\n1.Estou satisfeito\n2.Alterar desconto\n3.Alterar dia com desconto\n4.continuar assim\n");
                    scanf ("%d", &menu);

                    while ( (menu < 1) || (menu > 4) ){ //menu invalido
                        printf ("Resposta invalida, digite novamente:\n");
                        scanf ("%d", &menu);
                    }
                }

        }

    }


    return 0;
}
