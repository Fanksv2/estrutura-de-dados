#include <stdio.h>

int qtd = 0;

int calcula(int soma){
    int valor = 0;
    scanf("%i", &valor);
    soma += valor;
    if(valor != 0){
        qtd++;
        soma = calcula(soma);
    }
    return soma;   
}

int main(){
    int soma = 0;

    soma = calcula(soma);

    double media = (double) soma/qtd;

    printf("Soma: %i\n", soma);
    printf("Media: %f", media);

    return 0;
}

