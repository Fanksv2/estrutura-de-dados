/* O que faz este programa ? */
// Esse programa é uma fila com alocação dinâmica

#include <stdio.h> //Incluindo a biblioteca stdio ao programa
#include <stdlib.h> //Incluindo a biblioteca stdlib ao programa

typedef struct no{ //Declaração da struct nó
	int info; //Variável da struct nó que guarda os dados
	struct no *prox; //Variável da struct nó que aponta para o próximo nó da fila
}NO;

NO *varA = NULL; //Variável usada para guardar o nó do inicio da fila
NO *varB = NULL; //Variável usada para guardar o nó do fim da fila


void funcao1(int x){  // Declaração de uma função para adicionar um dado na fila
	NO *novo = (NO *)malloc(sizeof(NO)); // Uma nova variavel para guardar o novo nó, e alem disso tambem é feita a alocação da memória
	novo->info = x; // O dado passado no parâmetro é colocado dentro do nó
	novo->prox = NULL; // Como não existe um nó a frente do novo nó, esse atributo recebe NULL

	if(varB != NULL){ // Se o nó do final for diferente de NULL
		varB->prox = novo; // O atributo "prox" do variavel que guarda o ultimo nó recebe o nó novo
		varB = novo; // O ultimo nó recebe o nó novo
	}else{ 
		varA=novo; // A variavel que guarda o nó do inicio recebe o novo nó
		varB = novo; // A variavel que guarda o nó do fim recebe o novo nó
	}
}

int funcao2(){ // Declaração de uma função para remover um nó do inicio da fila
	int r; //Declara uma nova variavel int
	NO *temp = varA; //Cria um nó temporário que recebe o nó de inicio da fila antes da remoção
	if(varA != NULL){ //Se o nó do inicio for diferente de NULL
		varA = varA->prox; //O nó de inicio vira o proximo nó da fila, por causa da remoção
		if(varA == NULL) varB = NULL; //Se o nó do inicio for NULL, quer dizer que não existe nó na fila, logo o nó de fim deve ser NULL também
		r = temp->info; //O dado da variavel temp (que é a variavel de inicio antes da remoção) é atribuida a variavel "r"
		free(temp); //Libera a memória da variável "temp"
		return r; //Retorna o valor de r
	}else{
		return -1; //Retorna o numero -1
	}
}


int main(){
	printf("Atividade 02.\n");

}