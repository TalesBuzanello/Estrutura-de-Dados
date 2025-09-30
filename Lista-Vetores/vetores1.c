#include <stdio.h>
#include <string.h>


//Define o tamanho dos itens, e o maximo
#define MaxItens 10
#define TamItem 20

typedef char tpLista[MaxItens][TamItem];

// Cria deixando todas as posições vazias
void criaLista(tpLista l) {
    for (int i = 0; i < MaxItens; i++) {
        l[i][0] = '\0';
    }
}

// Imprime lista
void imprimeLista(tpLista l) {
    printf("\nItens da lista:\n");
    for (int i = 0; i < MaxItens && strlen(l[i]) > 0; i++) {
        printf("%d - %s\n", i+1, l[i]);
    }
}

// Conta elementos
int contaLista(tpLista l) {
    int i;
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++);
    return i;
}

// Insere elemento
void insereLista(tpLista l, char *item) {
    int i;
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++);
    
    if (i < MaxItens) {
        strcpy(l[i], item);
        printf("\nItem (%s) inserido com sucesso!\n", item);
    } else {
        printf("\nLista cheia, não pode inserir.\n");
    }
}

// Retira elemento
void retiraLista(tpLista l, char *item) {
    int i;
    for (i = 0; i < MaxItens && strlen(l[i]) > 0 && strcmp(l[i], item) != 0; i++);
    
    if (i < MaxItens && strcmp(l[i], item) == 0) {
        printf("\nItem (%s) encontrado, removendo...\n", item);
        for (; i < (MaxItens-1) && strlen(l[i]) > 0; i++) {
            strcpy(l[i], l[i+1]);
        }
        l[MaxItens-1][0] = '\0';
    } else {
        printf("\nItem (%s) não encontrado.\n", item);
    }
}

// Programa principal (menu)
int main() {
    tpLista lista;
    int opcao;
    char item[TamItem];

    criaLista(lista);

    do {
        printf("\n=====MENU=====\n");
        printf("1. Inserir elemento\n");
        printf("2. Retirar elemento\n");
        printf("3. Criar lista (limpar)\n");
        printf("4. Contar elementos\n");
        printf("5. Exibir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // consumir \n

        switch (opcao) {
            case 1:
                printf("Digite o item a inserir: ");
                fgets(item, TamItem, stdin);
                item[strcspn(item, "\n")] = '\0'; // remover \n
                insereLista(lista, item);
                break;

            case 2:
                printf("Digite o item a retirar: ");
                fgets(item, TamItem, stdin);
                item[strcspn(item, "\n")] = '\0';
                retiraLista(lista, item);
                break;

            case 3:
                criaLista(lista);
                printf("\nLista recriada (vazia).\n");
                break;

            case 4:
                printf("\nA lista contém %d elemento(s).\n", contaLista(lista));
                break;

            case 5:
                imprimeLista(lista);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
