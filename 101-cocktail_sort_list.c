#include "sort.h"

void swap(listint_t *, listint_t *);
void cocktail_sort_list(listint_t **list);

/**
 * swap - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @right: A pointer to the head of a doubly-linked list of integers.
 * @left: A pointer to the tail of the doubly-linked list.
  */
void swap(listint_t *left, listint_t *right)
{
if (left->prev != NULL)
left->prev->next = right;
if (right->next != NULL)
right->next->prev = left;
left->next = right->next;
right->prev = left->prev;
left->prev = right;
right->next = left;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
listint_t *curr, *start, *end;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
start = *list;
end = NULL;
while (start->next != end) /* start and end are sorted */
{
curr = start;
while (curr->next != end)
{
if (curr->n > curr->next->n)
{
if (curr == *list)
*list = start = curr->next;
swap(curr, curr->next);
print_list(*list);
}
else
curr = curr->next;
}
end = curr; /* curr is sorted */
curr = curr->prev;
while (curr != start)
{
if (curr->prev != NULL && curr->n < curr->prev->n)
{
if (curr->prev == *list)
*list = start = curr;
swap(curr->prev, curr);
print_list(*list);
}
else
curr = curr->prev;
}
start = curr; /* curr is sorted */
}
}
