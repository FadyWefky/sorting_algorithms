#include <stdio.h>
#include <stdlib.h>

typedef struct listint_t
{
    int n;
    struct listint_t *prev;
    struct listint_t *next;
} listint_t;

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
    listint_t *temp_prev;

    if (node1 == node2) return;

    temp_prev = node1->prev;
    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;
    node1->prev = node2->prev;
    node2->prev = temp_prev;

    temp_prev = node1->next;
    node1->next = node2->next;
    node2->next = temp_prev;

    if (node1->prev == NULL)
        *list = node1;
    if (node2->prev == NULL)
        *list = node2;
}

void insertion_sort_list(listint_t **list) {
    listint_t *current;
    listint_t *key, *prev;

    if (*list == NULL || (*list)->next == NULL) return;

    current = (*list)->next;

    while (current != NULL)
    {
        key = current;
        prev = current->prev;

        while (prev != NULL && key->n < prev->n)
        {
            swap_nodes(list, key, prev);
            prev = key->prev;
        }

        // Print the list after each iteration
        print_list(*list);

        current = current->next;
    }
}

listint_t *create_node(int n) {
    listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
    if (new_node != NULL)
    {
        new_node->n = n;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

void append_node(listint_t **list, listint_t *new_node) {
    listint_t *last_node;
    
    if (*list == NULL)
    {
        *list = new_node;
    }
    else
    {
        last_node = *list;
        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

void print_list(listint_t *list) {
    while (list != NULL)
    {
        printf("%d ", list->n);
        list = list->next;
    }
    printf("\n");
}

void free_list(listint_t **list) {
    listint_t *current = *list;
    while (current != NULL)
    {
        listint_t *next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}
