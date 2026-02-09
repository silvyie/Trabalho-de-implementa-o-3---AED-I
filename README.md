# Trabalho de implementação 3 - AED I

- Nome: Silvana Dias
- Turma: M2

- Sobre o código:

Primeiro eu percorro a lista encadeada para contar quantos elementos ela possui, porque a lista não permite acesso 
direto ao meio. Em seguida, copio os valores da lista para um vetor auxiliar, mantendo a ordem crescente.

Depois disso, construo a árvore de forma recursiva: escolho o elemento central do vetor como raiz para garantir o 
balanceamento da árvore, e faço chamadas recursivas para construir a subárvore esquerda com os elementos anteriores 
ao meio e a subárvore direita com os elementos posteriores.

O caso base da recursão ocorre quando o intervalo do vetor fica vazio, retornando NULL. 
Ao final, retorno a raiz da árvore binária de busca balanceada.

- Complexidade:

O tempo é O(N log N) porque a construção da árvore ocorre de forma recursiva, dividindo o conjunto de dados ao meio a 
cada chamada, gerando log N níveis, e em cada nível todos os N elementos são considerados. 
O espaço é O(N) devido ao uso de um vetor auxiliar para armazenar os valores da lista.

- Testes feitos:

{}
{7}
{1, 2}
{1, 2, 3}
{-10, -8, -5, -2}
{-5, -2, 0, 3, 8}
{1, 2, 3, 4, 5, 6, 7}
{10, 20, 30, 40, 50, 60}
{-100000, -50000, 0, 50000, 100000}
{-3, -1, 2, 4, 9, 15}
