#include <stdio.h>

int main(){
    int soma = 0;
    int qtd = 0;

    for(int i = 0; i < 10; i++){
        int valor = 0;
        scanf("%i", &valor);
        soma += valor;
        qtd++;
    }

    double media = (double) soma/qtd;

    printf("Soma: %i\n", soma);
    printf("Media: %f", media);

    return 0;
}