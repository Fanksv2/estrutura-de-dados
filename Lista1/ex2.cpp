#include <stdio.h>

int main(){
    int soma = 0;
    int qtd = 0;

    
    int valor = 0;
    do{
        scanf("%i", &valor);
        soma += valor;
        qtd++;
    }while(valor != 0);

    double media = (double) soma/qtd;

    printf("Soma: %i\n", soma);
    printf("Media: %f", media);

    return 0;
}