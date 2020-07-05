/*
	Name: LISTA ENCADEADA CIRCULAR;
	Course: Ciência da computação; 
	Author: Murilo Augusto Krugner Almeida Leite;
	Description: Quiz Aula 15 - Estrutura de dados;
	Creation date: 05/07/2020;
	Copyright: Licence MIT;
	
	Repository: https://github.com/murilokrugner/Lista-Encadeada-Circular
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//DEFINE A ESTRUTURA DO NODO
typedef struct TipoNo {
	int info;
	struct TipoNo *prox;
}TNo;

// CRIA O INICIO DA LISTA
typedef struct TipoLista {
	TNo *inicio;
	TNo *fim;
}TLista;

// FUNCAO QUE DEFINE A LISTA COMO VAZIA
void inicializarLista(TLista *pLista) {
	pLista->inicio = NULL;
	pLista->fim = NULL;
}

//FUNCAO QUE INSERE UM ELEMENTO DO INICIO DA LISTA
void inserir(TLista *pLista) {
	TNo *novoElemento;
	
	novoElemento = new TNo;
	
	printf("\n Informe o valor para lista circular: ");
	scanf("%d", &novoElemento->info);
	novoElemento->prox = NULL;
	
	if (pLista->inicio == NULL) {
		pLista->inicio = novoElemento;
	} else {
		pLista->fim->prox = novoElemento;
	}
	
	pLista->fim = novoElemento;
	novoElemento->prox = pLista->inicio;
}

// FUNCAO QUE IMPRIME TODA A LISTA
void apresentar(TLista *pLista) {
	TNo *aux;
	
	if (pLista->inicio == NULL) {
		printf("--- fim da lista --- \n\n");
		return;
	} else { // caso a lista esteja vazia
		aux = pLista->inicio;
		
		do {
			printf("\nInfo = %d", aux->info);
			aux = aux->prox;
		} while (aux != pLista->inicio);
				
		printf("\n --- fim da lista --- \n\n");
		getch();
	}
}

// FUNCAO QUE BUSCA UM ELEMENTO NA LISTA
void consultar(TLista *pLista) {
	if (pLista->inicio == NULL) {
		printf("--- fim da lista --- \n\n");
	} else {
		TNo *aux;
		int pesquisa;
		int achou = 0;
		
		printf("\n Informe o dado a ser pesquisado: ");
		scanf("%d", &pesquisa);
		
		aux = pLista->inicio;
		
		do {
			if (aux->info == pesquisa) {
				printf("++Achou o %d\n", aux->info);
				achou = 1;
			} else {
				aux = aux->prox;
			}
		} while (aux != pLista->inicio && achou == 0);
		
		if (achou == 0) {
			printf("\n Valor nao encontrado");
		}
		
		getch();
	}
}

// funcao que remove um elemento especificado
void excluir(TLista *pLista) {
	if (pLista->inicio == NULL) {
		printf("--- fim da lista --- \n\n");
	} else {
		TNo *atual, *anterior;
		int pesquisa;
		
		printf("\nInforme dado a ser excluido");
		scanf("%d", &pesquisa);
		
		// caso a lista nao esteja vazia
		atual = pLista ->inicio;
		anterior = pLista->inicio;
		
		do {
			if (atual->info == pesquisa) {
				//se elemento está no inicio da lista
				if (atual == pLista->inicio) {
					pLista->inicio = atual->prox;
					pLista->fim->prox = atual->prox;
					free(atual);
					break;
				} else { //caso nao seja o primeiro elemento
					anterior->prox = atual->prox;
					
					if (atual == pLista->fim) { //caso seja o ultimo elemento
						pLista->fim = anterior;
					}
					
					free(atual);
					break;
				}
			} else {
				anterior = atual;
				atual = atual->prox;
			}
		} while (atual != pLista->inicio);
	}
}

int main() {
	int opcao;
	
	TLista listaCircular;
	
	inicializarLista(&listaCircular);
	
	do {
		printf("\n\n **** LISTA ENCADEADA CIRCULAR  ****\n\n");
		printf("\nOpcoes: \n\n");
		printf(" 1 - INSERIR NOVO NUMERO \n");
		printf(" 2 - CONSULTAR NUMERO \n");
		printf(" 3 - REMOVER NUMERO \n");
		printf(" 4 - LISTAR TODOS OS NUMEROS \n");
		printf(" 0 - PARA SAIR \n\n");
		printf(" Entre com a sua opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
			case 1: inserir(&listaCircular); break;
			case 2: consultar(&listaCircular); break;
			case 3: excluir(&listaCircular); break;
			case 4: apresentar(&listaCircular); break;
			case 0: break;
			default: printf("\n\n Opcao invalida"); getch(); break;
		}
	} while (opcao != 0);
}



