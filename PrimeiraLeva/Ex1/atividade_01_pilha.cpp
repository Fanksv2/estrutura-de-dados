#include <stdio.h>  //Inclui a biblioteca stdio ao programa
#include <stdlib.h> //Inclui a biblioteca stdlib ao programa
#include <string.h> //Inclui a biblioteca string ao programa

typedef struct no { //Declaração da estrutura do nó
	char info;      //Declaração da variavel que guarda informações do nó
	struct no *ant; //Declaração da variavel que guarda o ponteiro do no anterior
}NO;                

NO *topo = NULL; //Inicializacao da variavel topo, que é do tipo nó

void push(int i){ //Declaração do metodo push
	NO *novo = (NO*)malloc(sizeof(NO)); //Declaração e alocação de memória para a variável ponteiro "novo"
	novo->info = i; //A variável info do nó "novo" recebe a informação passada do parâmetro
	novo->ant = topo; //O ponteiro "ant" do nó "novo" começa a apontar para o nó "topo"
	topo = novo; //A variável topo receba a variável novo
	//
	// Basicamente esse método recebe um parâmetro de uma informação para colocar na pilha
	// O programa aloca um novo nó para a pilha, colocando o dado dentro do nó e fazendo o novo nó apontar para o antigo topo
	// Depois, o nó novo passa a ser o topo
	// 
}

void pop(){ //Declaracao do método pop
	if(topo != NULL){ // Se existir pelo menos um nó na pilha
		NO *aux = topo; // Uma nova variavel auxiliar recebe as informações da variavel topo
		char i = aux->info; // A variável "i" não é usada, portanto essa linha não tem uso
		topo = topo->ant; // O nó anterior ao topo agora é o topo
		free(aux); //Libera a memória da variavel aux
	}
	// Esse método vai retirar o topo da pilha e apontar o nó anterior para ser o novo nó do topo
}

void imprime(){ // Declaracao do metodo imprime
	NO *no = topo; //Declaração de uma nova variavel nó, e ela recebe o nó do topo
	while(no != NULL){ //Enquanto nó não é NULL
		printf("%d\n", no->info); // Printa o dado do nó
		no = no->ant; // Agora a variavel nó recebe o nó anterior da que estava sendo analizada
	}
}


int main(){
	/* instrucoes:
	sair: sair
	empilha <n>: empilhar o numero n
	desempilha: desempilhar e imprimir
	*/	

	char instrucao[15]; // Declara um array de 15 posições
	int  num; //Declara uma variavel int
	scanf("%s",&instrucao); //Recebe um input do teclado e coloca dentro da variavel instrucao
	while(strcmp(instrucao,"sair")){ // Enquanto a variavel instrucao for diferente de sair

		if(!strcmp(instrucao,"empilha")){ // Se a variavel instrucao for igual a empilha
			scanf("%d",&num); //Lê um valor do input do teclado e coloca na variavel "num"
			push(num); //Adiciona o valor da variavel "num" a pilha
		}

		else if(!strcmp(instrucao,"desempilha")){ // Se a variavel instrucao for igual a desempilha
			pop(); //Retira o nó no topo da pilha
		}

		else if(!strcmp(instrucao,"imprime")){ // Se a variavel instrucao for igual a imprime
			imprime(); // Chama a funçao de imprimir
		}
		scanf("%s",&instrucao); //Lê um input do teclado e coloca na variavel instrucao

	}
}
