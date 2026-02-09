/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

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
    if (head == NULL){
        return NULL;
    }

    int tamanho = 0;
    struct ListNode *atual = head;
    while(atual != NULL){
        tamanho++;
        atual = atual->next;
    }



    

    int *valores = malloc(sizeof(int));
    free(valores);
}
