#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Pi 3.14159265l

//Questao 5

int main()
{
    float Raio, Distancia, CoordX, CoordY, Angulo, ComprimentoDoCirculo;

    printf("Calculo da posicao final do planeta Marte\n");

    printf ("\nDigite o Raio da circunferencia\n");
    scanf ("%f", &Raio);

    printf ("\nDigite a Distancia a ser percorrida pelo planeta\n");
    scanf ("%f", &Distancia);

    Angulo = (  (Distancia - Raio)/Raio  ); /* COMPRIMENTO DE ARCO: Comp = Ang*Pi*Raio/Pi ~> Ang = Comp/Raio PARA QUAL Comp = Dist-Raio ~> Ang=(Dist - Raio)/Raio*/

    ComprimentoDoCirculo = 2*Pi*Raio;


    if (Distancia <= Raio){  //Calculando a distancia antes de entrar no circulo
        CoordX = Distancia;
        CoordY = 0;

        printf ("\nA posicao final do planeta e: (X=%f, Y=%f)\n", CoordX, CoordY);
    }

    else if (  (Distancia > Raio) && (Distancia < (Raio + ComprimentoDoCirculo)  )  ){ //Calculando a Distancia no circulo
        CoordX = (Raio + (Raio* sin(Angulo)  )  );
        CoordY = (Raio - (Raio* cos(Angulo)  )  );

        printf ("\nA posicao final do planeta e: (X=%f, Y=%f)\n", CoordX, CoordY);
    }

    else if ( Distancia >= (Raio + ComprimentoDoCirculo)  ){ //Calculando a distancia depois de ter completado o circulo
        CoordX = (Distancia - ComprimentoDoCirculo);
        CoordY = 0;

        printf ("\nA posicao final do planeta e: (X=%f, Y=%f)\n", CoordX, CoordY);
    }

    else if (Distancia <= 0) { //Erro para numeros negativos e distancia de 0
        printf ("\nErro! Distancia igual ou inferior a zero\n");
        return 0;
    }

    else { //Caso a distancia inserida pelo usuario passe da rota do planeta
        printf ("\nErro! Distancia fora da rota\n");
        return 0;
    }


    return 0;
}
