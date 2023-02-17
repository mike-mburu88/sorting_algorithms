#ifndef _SORT_H
#define _SORT_H
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
/**
 *struct listint_s - a doubly linked list
 *@n: the integer variable stored in the node
 *@next: A pointer variable to the next list element
 *@prev: pointer variable to the previous list element
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
#endif
