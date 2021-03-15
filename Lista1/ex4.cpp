#include <stdio.h>
#include <cstdlib>

int calcula(int soma, int* qtd, int* greaters, float* media){
    int valor = 0;
    scanf("%i", &valor);
    soma += valor;
    if(valor != 0){
        (*qtd)++;
        soma = calcula(soma, qtd, greaters, media);
        *media = (double) soma/(*qtd);
        if(*media < valor)
            (*greaters)++;
    }
    return soma;   
}

int main(){
    int soma = 0;
    int* qtd, *greaters;
    float *media;
    qtd = (int*) malloc(sizeof(int));
    greaters = (int*) malloc(sizeof(int));
    media = (float*) malloc(sizeof(float));

    *qtd = 0;
    *greaters = 0;
    *media = 0.f;

    soma = calcula(soma, qtd, greaters, media);

    *media = (float) soma/(*qtd);

    printf("Soma: %i\n", soma);
    printf("Media: %f\n", *media);
    printf("Maiores: %i", *greaters);

    return 0;
}

