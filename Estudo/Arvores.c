#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

typedef struct treeB
{
    node *root;
} treeB;

treeB *Create_treeB(void)
{
    treeB *tree = (treeB *)malloc(sizeof(treeB));
    tree->root = NULL;
    return tree;
}

void inserir_treeB(treeB *t, int value)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    if (t->root == NULL)
    {
        t->root = new_node;
    }
    else
    {
        node *current = t->root;
        node *parent = NULL;
        while (current != NULL)
        {
            parent = current;
            if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        if (value < parent->data)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }
}

void print_treeB(node *root)
{
    if (root == NULL)
        return;

    print_treeB(root->left);
    printf("%d ", root->data);
    print_treeB(root->right);
}

node *remover_treeB(node *root, int value)
{
    if (root == NULL)
        return NULL;
    if (value < root->data)
        root->left = remover_treeB(root->left, value);
    else if (value > root->data)
        root->right = remover_treeB(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node *temp = root->right;
            node *temp_min = root->left;
            while (temp_min->left != NULL)
            {
                temp_min = temp_min->left;
            }
            root->data = temp_min->data;
            root->left = remover_treeB(root->left, temp_min->data);
        }
    }
    return root;
}

int Conta_numero_de_descendentes(node *no)
{
    int quant = 0;
    if (no == NULL)
        return 0;
    else
    {
        quant = quant + Conta_numero_de_descendentes(no->left);
        quant = quant + Conta_numero_de_descendentes(no->right);
        quant = quant + 1;
    }
    return quant;
}

int verifica_se_completa(node *no)
{
    if (no == NULL)
        return;
    else
    {
        verifica_se_completa(no->left);
        verifica_se_completa(no->right);
        if (no->left == NULL && no->right == NULL)
            return;
        else
        {
            if (no->left == NULL)
                return 1;
            if (no->right == NULL)
                return 1;
            if (no->left != NULL && no->right != NULL)
            {
                return 0;
            }
        }
    }
}
    int main(void)
    {
        treeB *T = Create_treeB();
        int entrada;
        scanf("%d", &entrada);
        while (entrada)
        {
            inserir_treeB(T, entrada);
            print_treeB(T->root);
            printf("\n");
            scanf("%d", &entrada);
            printf("Quantidade de filhos do filho a direita: %d\n", Conta_numero_de_descendentes(T->root->right));
            printf("Quantidade de filhos do filho a esquerda: %d\n\n", Conta_numero_de_descendentes(T->root->left));
        }

        return 0;
    }