/*Essa funcao transforma uma string de numeros em um numero inteiro*/
int f_transformarNumero (char* pntString)
{
    int i, j, base, numero, h;

    for (i = 0; pntString [i] != '\0'; i++){ //saber o tamanho da string
    }
    i--; //i agora tem o valor do indice anterior ao '\0'

    numero = 0; //inicializar

    for (j = 0; i >= 0; j++, i--){
        //base = pow (10, i);
        base = 1;
        for (h = 1; h <= i; h++){ //funcao pow da math.h tava dando erro !
                base = base*10;
        }

        numero = numero + ( (pntString[j]-'0')*base); //numero recebe o caractere inicial multiplicado pela base indicada, o modelo segue
    }

    return numero;
}
