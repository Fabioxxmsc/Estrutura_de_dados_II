#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;		    // Chave de identificação do nodo
	node *left, *right;	// Ponteiros para os filhos
};

// Busca por uma chave K na árvore com raiz r
// caso a chave não estiver na árvore retorna NULL
node * search(node *r, int key){
	if(!r || r->key == key)
		return r;	   // n encontrou a chave
	if(key <= r->key)
		return search(r->left, key);
	return search(r->right, key);
}

// Mostra todas as chaves da árvore em Percurso Pre-Ordem
void printPre(node *r){
	if(r != NULL){
		printf("%d ", r->key);
  	printPre(r->left);
  	printPre(r->right);
	}
}

// Mostra todas as chaves da árvore em Percurso Em-Ordem
void printIn(node *r){
	if(r != NULL){
  	printIn(r->left);
  	printf("%d ", r->key);
  	printIn(r->right);
	}
}

// Mostra todas as chaves da árvore em Percurso Pos-Ordem
void printPos(node *r){
	if(r != NULL){
  	printPos(r->left);
  	printPos(r->right);
		printf("%d ", r->key);  	
	}
}

// Insere um nodo com chave key na árvore com raiz r
// retornando um ponteiro para a raiz da árvore
node * insert(node *r, int key){
	node  *n = (node *)malloc(sizeof(node));
	n->left = n->right = NULL;
	n->key = key;	
	if(!r)
		return n;            // Se a árvore estiver vazia
	node *it = r;
	while(1){
		if(key < it->key){
			if(!it->left){
				it->left = n; // Atualiza o filho da esquerda de r
				break;
			}
			it = it->left;
		}else{
			if(!it->right){
				it->right = n; // Atualiza o filho da direita de r
				break;	
			}
			it = it->right;
		}
	}
	return r;
}

// Remove o nodo da árvore com a raiz r que possui chave igual
// a key (Lembrar de dar free no nodo)
void remove(node *r, int key);

int main(void){
	int n, qtd, op;
	
	node *root, *b = NULL;

	do{
		printf("\nMenu\n");
		printf("1 - Inserir\n");
		printf("2 - Buscar\n");
		printf("3 - Mostrar (Pré-Order)\n");
		printf("4 - Mostrar (In-Order)\n");
		printf("5 - Mostrar (Pos-Order)\n");
		printf("6 - Remover\n");
		printf("0 - Sair\n");
		printf("Sua opção: ");
		scanf("%d", &op);
		printf("\n");
		switch (op){
			case 1: // Insere valores
				printf("Informe a quantidade de valores a serem inseridos: ");
				scanf("%d", &qtd);		
				for(int i = 0; i < qtd; i++){
					printf("\nInforme o valor a ser inserido: ");
					scanf("%d", &n);
					if ((root = insert(root, n)))
						printf("\nValor %d foi inserido.\n", n);
					else
						printf("\nValor não inserido\n");
				}
				break;
			case 2: // Busca um valor específico
				printf("\nInforme o valor a ser buscado: ");
				scanf("%d", &n);
				b = search(root, n);
				if(!b)
					printf("\nValor não encontrado\n");
				else
					printf("\nValor %d encontrado\n", b->key);
				break;
			case 3: // Mostra todos os valores em Percurso Pre-Ordem
				printPre(root);
				printf("\n");
				break;
			case 4: // Mostra todos os valores em Percurso Em-Ordem
				printIn(root);
				printf("\n");
				break;
			case 5: // Mostra todos os valores em Percurso Pos-Ordem
				printPos(root);
				printf("\n");
				break;
			case 6: // Remove um valor específico
				break;
				printf("\nInforme o valor a ser removido: ");
				scanf("%d", &n);
				remove(root, n);
			case 0: // Exit
				printf("Saindo...\n");
				break;
			default: // Tratamento
				printf("Opção incorreta\n");
		}
	}while(op != 0);

	return 0;
}
