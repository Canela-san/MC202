// Gabriel Canela
// RA243453

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *str;
    struct node *next;
};

void append(struct node **head_ref, char *new_str)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->str = (char *)malloc(sizeof(char) * (strlen(new_str) + 1));
    strcpy(new_node->str, new_str);
    new_node->next = NULL;
    struct node *last = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

struct node *get_difference_min_occur(struct node *list1, struct node *list2, int n)
{
    struct node *diff_list = NULL;
    struct node *tmp = NULL;
    while (list1 != NULL)
    {
        int count = 0;
        tmp = list1;
        while (tmp != NULL)
        {
            if (strcmp(list1->str, tmp->str) == 0)
            {
                count++;
            }
            tmp = tmp->next;
        }
        if (count >= n)
        {
            int found = 0;
            struct node *prev = NULL;
            struct node *curr = diff_list;
            while (curr != NULL)
            {
                if (strcmp(list1->str, curr->str) == 0)
                {
                    found = 1;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if (!found)
            {
                append(&diff_list, list1->str);
            }
        }
        list1 = list1->next;
    }

    return diff_list;
}

struct node *remove_duplicates(struct node *list)
{
    struct node *unique_list = NULL;
    struct node *curr = list;
    struct node *prev = NULL;

    while (curr != NULL)
    {
        int found = 0;
        struct node *tmp = unique_list;
        while (tmp != NULL)
        {
            if (strcmp(curr->str, tmp->str) == 0)
            {
                found = 1;
                break;
            }
            tmp = tmp->next;
        }
        if (!found)
        {
            append(&unique_list, curr->str);
            prev = curr;
        }
        else
        {
            prev->next = curr->next;
            free(curr);
        }
        curr = prev->next;
    }
    return unique_list;
}
int main()
{
    struct node *list1 = NULL;
    struct node *list2 = NULL;

    char str[109];
    char *subnome;
    const char s[2] = " ";
    int n = 0;
    while (1)
    {
        char temp1[100] = "";
        char temp2[100] = "";
        fgets(str, 109, stdin); // lê a entrada do usuário
        if (str[1] == '\0')
        {
            break;
        }
        subnome = strtok(str, s);
        n++;
        while (strcmp(subnome, "conhece") != 0)
        {
            strcat(temp1, subnome);
            strcat(temp1, " ");
            subnome = strtok(NULL, " ");
        }

        while (subnome != NULL)
        {

            strcat(temp2, subnome);
            strcat(temp2, " ");
            if (strcmp(subnome, "conhece") == 0)
            {
                strcpy(temp2, "");
            }
            subnome = strtok(NULL, " ");
        }

        temp2[strlen(temp2) - 2] = '\0';
        temp1[strlen(temp1) - 1] = '\0';

        append(&list1, temp2);
        append(&list2, temp1);
    }

    struct node *aaaaaa = remove_duplicates(list2);

    int count = 0;
    while (aaaaaa != NULL)
    {
        count++;
        aaaaaa = aaaaaa->next;
    }

    struct node *diff_list = get_difference_min_occur(list1, list2, count);

    if (diff_list == NULL)
    {
        printf("Nao ha' celebridade.");
    }
    else
    {
        while (diff_list != NULL)
        {
            printf("%s e' celebridade.", diff_list->str);
            diff_list = diff_list->next;
        }
    }

    return 0;
}
