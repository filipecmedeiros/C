#include <stdio.h>
#include <stdlib.h>

//Questao 2

int main()
{
    char digito;

    printf ("Decodificador do Codigo Morse\n");
    printf ("\nDigite um unico caractere alfa-numerico\n");
    scanf ("%c", &digito);

    switch (digito){                                       //ALFABETO MENUSCULO *******
        case 'a': printf (".- dit dah\n");
        break;

        case 'b': printf ("-... dah dit dit dit\n");
        break;

        case 'c': printf ("-.-. dah dit dah dit\n");
        break;

        case 'd': printf ("-.. dah dit dit\n");
        break;

        case 'e': printf (". dit \n");
        break;

        case 'f': printf ("..-. dit dit dah dit\n");
        break;

        case 'g': printf ("--. dah dah dit\n");
        break;

        case 'h': printf (".... dit dit dit dit\n");
        break;

        case 'i': printf (".. dit dit\n");
        break;

        case 'j': printf ("	.--- dit dah dah dah\n");
        break;

        case 'k': printf ("-.- dah dit dah \n");
        break;

        case 'l': printf (".-..dit dah dit dit\n");
        break;

        case 'm': printf ("-- dah dah\n");
        break;

        case 'n': printf ("-.dah dit\n");
        break;

        case 'o': printf ("--- dah dah dah\n");
        break;

        case 'p': printf (".--. dit dah dah dit\n");
        break;

        case 'q': printf ("--.- dah dah dit dah\n");
        break;

        case 'r': printf (".-. dit dah dit\n");
        break;

        case 's': printf ("...dit dit dit\n");
        break;

        case 't': printf ("- dah\n");
        break;

        case 'u': printf ("..- dit dit dah\n");
        break;

        case 'v': printf ("...- dit dit dit dah\n");
        break;

        case 'w': printf (".-- dit dah dah\n");
        break;

        case 'x': printf ("-..- dah dit dit dah\n");
        break;

        case 'y': printf ("-.-- dah dit dah dah\n");
        break;

        case 'z': printf ("--.. dah dah dit dit\n");
        break;

        case 'A': printf (".- dit dah\n");  //ALFABETO MAIUSCULO *********
        break;

        case 'B': printf ("-... dah dit dit dit\n");
        break;

        case 'C': printf ("-.-. dah dit dah dit\n");
        break;

        case 'D': printf ("-.. dah dit dit\n");
        break;

        case 'E': printf (". dit\n");
        break;

        case 'F': printf ("..-. dit dit dah dit\n");
        break;

        case 'G': printf ("--. dah dah dit\n");
        break;

        case 'H': printf (".... dit dit dit dit\n");
        break;

        case 'I': printf (".. dit dit\n");
        break;

        case 'J': printf ("	.--- dit dah dah dah\n");
        break;

        case 'K': printf ("-.- dah dit dah\n");
        break;

        case 'L': printf (".-.. dit dah dit dit\n");
        break;

        case 'M': printf ("-- dah dah\n");
        break;

        case 'N': printf ("-. dah dit\n");
        break;

        case 'O': printf ("--- dah dah dah\n");
        break;

        case 'P': printf (".--. dit dah dah dit\n");
        break;

        case 'Q': printf ("--.- dah dah dit dah\n");
        break;

        case 'R': printf (".-. dit dah dit\n");
        break;

        case 'S': printf ("... dit dit dit\n");
        break;

        case 'T': printf ("- dah\n");
        break;

        case 'U': printf ("..- dit dit dah\n");
        break;

        case 'V': printf ("...- dit dit dit dah\n");
        break;

        case 'W': printf (".-- dit dah dah\n");
        break;

        case 'X': printf ("-..- dah dit dit dah\n");
        break;

        case 'Y': printf ("-.-- dah dit dah dah\n");
        break;

        case 'Z': printf ("--.. dah dah dit dit\n");
        break;

        case '0': printf ("----- dah dah dah dah dah\n");  //NUMEROS ********
        break;

        case '1': printf (".---- dit dah dah dah dah\n");
        break;

        case '2': printf ("..--- dit dit dah dah dah\n");
        break;

        case '3': printf ("...-- dit dit dit dah dah\n");
        break;

        case '4': printf ("....- dit dit dit dit dah\n");
        break;

        case '5': printf ("..... dit dit dit dit dit\n");
        break;

        case '6': printf ("-.... dah dit dit dit dit\n");
        break;

        case '7': printf ("--... dah dah dit dit dit\n");
        break;

        case '8': printf ("---.. dah dah dah dit dit\n");
        break;

        case '9': printf ("	----. dah dah dah dah dit\n");
        break;
        default: printf ("Erro! Caractere nao-alfa-numerico digitado\n");
        }

return 0;

}
