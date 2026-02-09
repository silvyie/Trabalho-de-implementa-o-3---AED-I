#include <stdio.h>
#include <stdlib.h>

/*================================================================
   Estruturas
  ================================================================*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*================================================================
   Constrói uma BST balanceada a partir de um array ordenado
  ================================================================*/

struct TreeNode* construirBST(int valores[], int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = inicio + (fim - inicio) / 2;

    struct TreeNode* raiz = malloc(sizeof(struct TreeNode));
    raiz->val = valores[meio];

    raiz->left = construirBST(valores, inicio, meio - 1);
    raiz->right = construirBST(valores, meio + 1, fim);

    return raiz;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    int tamanho = 0;
    struct ListNode* atual = head;
    while (atual != NULL) {
        tamanho++;
        atual = atual->next;
    }

    int* valores = malloc(tamanho * sizeof(int));
    atual = head;
    for (int i = 0; i < tamanho; i++) {
        valores[i] = atual->val;
        atual = atual->next;
    }

    struct TreeNode* raiz = construirBST(valores, 0, tamanho - 1);

    free(valores);
    return raiz;
}




/*==============================================================================================================
  Funções auxiliares para teste: Função de Criar lista, Imprimir em ordem, liberar memória da árvore e da lista
  ==============================================================================================================*/

struct ListNode* criarLista(int arr[], int n) {
    if (n == 0) return NULL;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* atual = head;
    for (int i = 1; i < n; i++) {
        struct ListNode* novo = malloc(sizeof(struct ListNode));
        novo->val = arr[i];
        novo->next = NULL;
        atual->next = novo;
        atual = novo;
    }

    return head;
}

void imprimirEmOrdem(struct TreeNode* raiz) {
    if (raiz == NULL) return;

    imprimirEmOrdem(raiz->left);
    printf("%d ", raiz->val);
    imprimirEmOrdem(raiz->right);
}

void liberarArvore(struct TreeNode* raiz) {
    if (raiz == NULL) return;

    liberarArvore(raiz->left);
    liberarArvore(raiz->right);
    free(raiz);
}

void liberarLista(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

/*================================================================
  Função main: Para fazer os testes
  ================================================================*/

int main() {
    int valores[] = {-10, -3, 0, 5, 9};
    int n = sizeof(valores) / sizeof(valores[0]);

    struct ListNode* lista = criarLista(valores, n);

    struct TreeNode* arvore = sortedListToBST(lista);

    printf("arvore em ordem: ");
    imprimirEmOrdem(arvore);
    printf("\n");

    liberarLista(lista);
    liberarArvore(arvore);

    return 0;
}
