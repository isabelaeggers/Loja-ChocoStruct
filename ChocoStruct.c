#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Produto {
	int id;
	char nome[MAX];
	int tipo;
    float preco;
    int quantidade;
    int peso; //o peso está como int, porque as barras de chocolate não tem peso "quebrado"
    int status;
};

typedef struct Produto TProduto;

void imprimirTipo(int tipo) {
    
	switch(tipo) {
        
		case 1:
			printf("Ao leite");
			break;
        case 2:
			printf("Branco");
			break;
        case 3:
			printf("Amargo");
			break;
        case 4:
			printf("Com castanhas");
			break;
        default:
			printf("Opcao invalida");
			break;
    }
}

void cadastrar(TProduto chocolates[], int pos) {
	
	printf("\nEntre com os dados:\n");
	
		chocolates[pos].id = pos;
	
		printf("Nome do Chocolate: ");
		fgets(chocolates[pos].nome, MAX-1, stdin);   
		
		do {
			printf("Tipo do Chocolate:\n1 - Ao leite\n2 - Branco\n3 - Amargo\n4 - Com Castanhas\n");
    		printf("Escolha uma opcao (1-4): ");
    		scanf("%d", &chocolates[pos].tipo);
    		getchar();
    	
    		if(chocolates[pos].tipo < 1 || chocolates[pos].tipo > 4) {
           		printf("\nOpcao invalida! Tente novamente.\n\n");
        	}
    	}
		
		while(chocolates[pos].tipo < 1 || chocolates[pos].tipo > 4);
		
			printf("Preco: ");
			scanf("%f", &chocolates[pos].preco);
			getchar();
		
			printf("Quantidade: ");
			scanf("%d", &chocolates[pos].quantidade);
			getchar();
		
			printf("Peso (em gramas): ");
			scanf("%d", &chocolates[pos].peso);
			getchar();
		
		chocolates[pos].status = 1;
}

void listar(TProduto chocolates[], int n){
	
	int i;
	int existe;
	
	existe = 0;

    for (i = 0; i < n; i++) {
        
		if (chocolates[i].status == 1) {
            existe = 1;
            break;
        }
    }

    if (!existe) {
        printf("\nNenhum produto cadastrado\n");
        return;
    }
		
		printf("\n*****Chocolates Cadastrados*****\n");
	
	for (i = 0; i < n; i++) {
		
		if(chocolates[i].status == 1){
			printf("ID: %d\n", chocolates[i].id);
			printf("Nome do Chocolate: %s", chocolates[i].nome);
			printf("Tipo do Chocolate: ");
			imprimirTipo(chocolates[i].tipo);
			printf("\n");
			printf("Preco: R$ %.2f\n", chocolates[i].preco);
			printf("Quantidade: %d unidades\n", chocolates[i].quantidade);
			printf("Peso: %d gramas\n\n", chocolates[i].peso);
		}
	}	
}

void contar(TProduto chocolates[], int n) {
    
    int i;
    int contarLeite, contarBranco, contarAmargo, contarCastanhas, total;
    
    contarLeite = 0;
	contarBranco = 0;
	contarAmargo = 0;
	contarCastanhas = 0;
	total = 0;

    for(i = 0; i < n; i++) {
        
		if(chocolates[i].status == 1) {
            
			switch(chocolates[i].tipo) {
                case 1:
					contarLeite += chocolates[i].quantidade;
					break;
                case 2:
					contarBranco += chocolates[i].quantidade;
					break;
                case 3:
					contarAmargo += chocolates[i].quantidade;
					break;
                case 4:
					contarCastanhas += chocolates[i].quantidade;
					break;
            }
            
			total += chocolates[i].quantidade;
        }
    }

    printf("\n*****Quantidade de Chocolates*****\n");
    printf("Ao leite: %d unidades\n", contarLeite);
    printf("Branco: %d unidades\n", contarBranco);
    printf("Amargo: %d unidades\n", contarAmargo);
    printf("Com Castanhas: %d unidades\n", contarCastanhas);
    printf("Total de Chocolates: %d unidades\n", total);
}

void valorTotal(TProduto chocolates[], int n) {
    int i;
    float total;
	
	total = 0;

    for(i = 0; i < n; i++) {
        if(chocolates[i].status == 1) {
            total += chocolates[i].quantidade * chocolates[i].preco;
        }
    }

    printf("\nValor Total do Estoque = R$ %.2f\n", total);
}

void pesquisar(TProduto chocolates[], int n) {
	char nome[MAX];
    int i;
	int encontrou;
	
	encontrou = 0;

    printf("\nEntre com o nome do chocolate: ");
    fgets(nome, MAX-1, stdin);

    for (i = 0; i < n; i++) {
        
		if (chocolates[i].status == 1 && strcmp(chocolates[i].nome, nome) == 0) {
            printf("\nProduto encontrado:\n");
            printf("ID: %d\n", chocolates[i].id);
            printf("Nome do Chocolate: %s", chocolates[i].nome);
            printf("Tipo do Chocolate: ");
			imprimirTipo(chocolates[i].tipo);
			printf("\n");
            printf("Preco: R$ %.2f\n", chocolates[i].preco);
            printf("Quantidade: %d unidades\n", chocolates[i].quantidade);
            printf("Peso: %d gramas\n", chocolates[i].peso);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("\nNenhum chocolate encontrado com esse nome\n");
    }
}

void remover(TProduto chocolates[], int n) {
	
	int i;
	int id;
	int existe;
	
	existe = 0;

    for (i = 0; i < n; i++) {
        
		if (chocolates[i].status == 1) {
            existe = 1;
            break;
        }
    }

    if (!existe) {
        printf("\nNenhum produto cadastrado!\n");
        return;
    }

    printf("\nEntre com o ID do produto: ");
    scanf("%d", &id);
    getchar();
    
    if (id < 0 || id >= n){
		printf("ID invalido\n");
		return;
	}
	
	if (chocolates [id].status == 1){
		chocolates [id].status = 0;
		printf("\nProduto removido com sucesso!\n");
	}
}

void atualizar(TProduto chocolates[], int n) {
	
	int i;
	int id;
	int existe;
	char resposta;
	
	existe = 0;

    for (i = 0; i < n; i++) {
        
		if (chocolates[i].status == 1) {
            existe = 1;
            break;
        }
    }

    if (!existe) {
        printf("\nNenhum produto cadastrado\n");
        return;
    }

    printf("\nEntre com o ID do produto: ");
    scanf("%d", &id);
    getchar();

	if (id < 0 || id >= n){
		printf("ID invalido\n");
		return;
	}

    if (chocolates [id].status == 1){
        
		printf("\nDeseja atualizar TODOS os dados do produto? (S/N): ");
        scanf("%c", &resposta);
        getchar();
        
        if (resposta == 'S' || resposta == 's') {
            printf("Entre com o nome do chocolate atualizado: ");
            fgets(chocolates[id].nome, MAX-1, stdin);

            printf("Entre com o tipo do chocolate atualizado: ");
            printf("Tipo do Chocolate:\n1 - Ao leite\n2 - Branco\n3 - Amargo\n4 - Com Castanhas\n");
    		printf("Escolha uma opcao (1-4): ");
            scanf("%d", &chocolates[id].tipo);
			getchar();

            printf("Entre com o preco atualizado: ");
            scanf("%f", &chocolates[id].preco);
            getchar();
            
            printf("Entre com a quantidade atualizada: ");
            scanf("%d", &chocolates[id].quantidade);
            getchar();

            printf("Entre com o peso atualizado (em gramas): ");
            scanf("%d", &chocolates[id].peso);
            getchar();

            printf("Todos os dados atualizados com sucesso!\n");
        }
		
		else {
            printf("Deseja atualizar o nome? (S/N): ");
            scanf("%c", &resposta);
            getchar();
            
			if (resposta == 'S' || resposta == 's') {
                printf("Entre com o nome do chocolate atualizado: ");
                fgets(chocolates[id].nome, MAX-1, stdin);
            }

            printf("Deseja atualizar o tipo do chocolate? (S/N): ");
            scanf("%c", &resposta);
            getchar();
            
			if (resposta == 'S' || resposta == 's') {
                printf("Entre com o tipo do chocolate atualizado: ");
                printf("Tipo do Chocolate:\n1 - Ao leite\n2 - Branco\n3 - Amargo\n4 - Com Castanhas\n");
    			printf("Escolha uma opcao (1-4): ");
                scanf("%d", &chocolates[id].tipo);
				getchar();
            }

            printf("Deseja atualizar o preco? (S/N): ");
            scanf("%c", &resposta);
            getchar();
            
			if (resposta == 'S' || resposta == 's') {
                printf("Entre com o preco atualizado: ");
                scanf("%f", &chocolates[id].preco);
                getchar();
            }
            
            printf("Deseja atualizar a quantidade? (S/N): ");
            scanf("%c", &resposta);
            getchar();
            
			if (resposta == 'S' || resposta == 's') {
                printf("Entre com a quantidade atualizada: ");
                scanf("%d", &chocolates[id].quantidade);
                getchar();
            }

            printf("Deseja atualizar o peso? (S/N): ");
            scanf("%c", &resposta);
            getchar();
            
			if (resposta == 'S' || resposta == 's') {
                printf("Entre com o peso atualizado (em gramas): ");
                scanf("%d", &chocolates[id].peso);
                getchar();
            }

            printf("Atualizacao finalizada!\n");
        }
	}
}
	
void menu() {
	printf(" _________________________________________ \n");
	printf("|  Cadastro de Produtos Loja ChocoStruct  |\n");
	printf("|_________________________________________|\n");
	printf("|                                         |\n");
	printf("|      1 - Cadastrar Produtos             |\n");
	printf("|      2 - Listar Produtos                |\n");
	printf("|      3 - Contar Estoque de Produtos     |\n");
	printf("|      4 - Estimar Valor do Estoque       |\n");
	printf("|      5 - Pesquisar Produto por Nome     |\n");
	printf("|      6 - Remover Produto                |\n");
	printf("|      7 - Atualizar Produto              |\n");
	printf("|      8 - Sair                           |\n");
	printf("|_________________________________________|\n");
}

int main() {

	TProduto *chocolates;
	int n, opcao;
	
	n= 0;
	
	do {
		
		menu();
		printf("\nEntre com a opcao: ");
		scanf("%d", &opcao);
		getchar();
		
		switch (opcao) {
			case 1:
				n++;
				
				if(n == 1){
					chocolates = (TProduto *) malloc(sizeof(TProduto)); //não coloquei o n * antes porque n = 1 e fica redundante
				}
				else{
					chocolates = (TProduto *) realloc(chocolates, n * sizeof(TProduto));
				}
				
				if (chocolates == NULL) {
					printf("Erro em alocacao de memoria\n");
	                exit(1);
                }
				cadastrar(chocolates, n-1);
				printf("\nCadastro realizado com sucesso!\n");
				break;
			
			case 2:
				if (n == 0) {
					printf("\nNenhum produto cadastrado ainda.\n");
				}
				else {
					listar(chocolates, n);
				}
				break;
			
			case 3:
				if (n == 0) {
                    printf("\nNenhum produto cadastrado ainda.\n");
                }
				else {
				    contar(chocolates, n);
                }
				break;
			
			case 4:
				if (n == 0) {
                    printf("\nNenhum produto cadastrado ainda.\n");
                }
				else {
				    valorTotal(chocolates, n);
                }
				break;
					
			case 5:
				if (n == 0) {
                    printf("\nNenhum produto cadastrado ainda.\n");
                }
				else {
				    pesquisar(chocolates,n);
                }
				break;
			
			case 6:
				if (n == 0) {
                    printf("\nNenhum produto cadastrado ainda.\n");
                }
				else {
				    remover(chocolates,n);
                }
				break;
			
			case 7:
				if (n == 0) {
                    printf("\nNenhum produto cadastrado ainda.\n");
                }
				else {
				    atualizar(chocolates,n);
                }
				break;
			
			case 8:
				break;
				
			default:
				printf("Opcao invalida\n");
				break;
		}
		printf("\n");
		
	} while (opcao != 8);
	
	free(chocolates);
	chocolates = NULL;
    
	return 0;
}
