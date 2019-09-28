#include <stdio.h>
#include <stdlib.h>
#define M 10

void main() {
	
	size_t *espaco = calloc(M, sizeof(int)), chave;
	char escolha;

	while (escolha != '5') {
		visualizar(espaco);
		printf("Escolha uma as opcoes a seguir: \n 1 - Inserir \n 2 - Pesquisar \n 3 - deletar \n 4 - visualizar\n 5 - sair\n");
		scanf("%c", &escolha);
		
		switch (escolha) {
			case '1':
				printf("\n digite um valor: ");
				scanf("%i", &chave);
				inserir(chave, espaco);
			break;
			case '2':
				printf("\n digite um valor: ");
				scanf("%i", &chave);
				printf("o valor encontrado foi: %i na posicao %i", pesquisar(chave, espaco), hash(chave));
			break;
			case '3':
				printf("\n digite um valor: ");
				scanf("%i", &chave);
				deletar(chave, espaco);
	 		break;
			case '4':
				visualizar(espaco);
			break;
			case '5':
				printf("saindo...");
			break;
		}
	}
	
	free(espaco);
}

int hash(int chave) {
	return chave%M;
}

void inserir(int chave, int *espaco) {
	*(espaco+hash(chave)) = chave;
}

int pesquisar(int chave, int *espaco) {
	return *(espaco+hash(chave));
}

void deletar(int chave, int *espaco) {
	*(espaco+hash(chave)) = 0;
}

void visualizar (int *espaco) {
	printf("\n---------------------------------------------------------------------------------------------------------\n | ");
	for (short i = 0; i<M; i++) {
		printf("%i | ", *(espaco+i));
	}
	printf("\n---------------------------------------------------------------------------------------------------------\n");
}
