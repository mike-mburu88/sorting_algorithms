#include "sort.h"

/**
 * selection_sort - sorts an array using selection method
 * @array: a pointer to an array of integers to sort
 * @size: array size
 *
 *Return: None
 */
void selection_sort(int *array, size_t size)
{
size_t a, b, minIndex;
int tmp;
if (array == NULL || size < 2)
return;
for (a = 0; a < size; a++)
{
minIndex = a;
for (b = a + 1; b < size; b++)
{
if (array[b] < array[minIndex])
minIndex = b;
}
if (array[minIndex] != array[a])
{
tmp = array[minIndex];
array[minIndex] = array[a];
array[a] = tmp;
print_array(array, size);
}
}
}
