
// void Lcreate()
// {
//     list *L = (list *)malloc(sizeof(list));
//     L->head = NULL;
//     L->indicator = NULL;
// }

void Linsert(list *L, char nome[100])
{
    printf("inserindooo\n");
    node *no = (node *)malloc(sizeof(node));
    no->name = (char *)malloc(sizeof(char) * 100);
    strcpy(no->name, nome);
    if (L->head == NULL)
    {
        L->head = no;
        L->indicator = no;
        no->prev = NULL;
        no->next = NULL;
    }
    else
    {
        no->prev = L->indicator;
        no->next = L->indicator->next;
        L->indicator->next = no;
    }
}

void Lremove(list *L, char name[100])
{
    printf("Removendooo\n");
    node *lixo;
    node *aux = (node *)malloc(sizeof(node));
    aux = L->head;

    while (aux->next && aux->name != name)
    {
        aux = aux->next;
    }
    if (aux->name == name)
    {
        lixo = aux;
        if (L->head == aux)
        {
            L->head = lixo->next;
            L->head->prev = NULL;
            if (L->indicator == lixo)
                L->indicator = lixo->next;
        }
        else
        {
            lixo->prev->next = lixo->next;
            lixo->next->prev = lixo->prev;
        }
        free(lixo);
    }
}
void Lplay(list *L)
{
    printf("tocandooo\n");
        
    if (L->indicator)
    {
        printf("%s\n", L->indicator->name);
        if (L->indicator->next != NULL)
            L->indicator = L->indicator->next;
    }
}

void Lgo_back(list *L)
{
    printf("voltando\n");
    if (L->indicator->prev != NULL)
        L->indicator = L->indicator->prev;
}

void Lfinal(list *L)
{
    printf("finalllll\n");
    while (L->indicator)
    {
        Lplay(L);
    }
}

void Linvert(list *L)
{
    printf("invertendooooo\n");
    if ((L->head == NULL) || (L->head->next == NULL))
        return;

    node *atual, *aux = (node *)malloc(sizeof(node));

    atual = L->head;

    while (atual)
    {
        aux = atual->prev;
        atual->prev = atual->next;
        atual->next = aux;
        atual = atual->prev;
    }
}

void Lfree(list *L)
{
    printf("liberandooo");
    node *aux;
    while (L->head != NULL)
    {
        aux = L->head;
        L->head = L->head->next;
        free(aux);
    }
}