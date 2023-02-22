#include "sort.h"

void _bitonicMerge(int *array, size_t low, size_t cnt, size_t dir);

/**
 * _bitonicSort - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @cnt: the no of elements to start from low.
 * @dir: The bitonic subsequence ( 0 for descent, 1 for increase)
 * @low: lower index of subarray.
 */
void _bitonicSort(int *array, size_t low, size_t cnt, size_t dir, size_t size)
{
size_t k = cnt / 2;
if (cnt > 1)
{
printf("%s [%lu/%lu] (%s):\n",
"Merging",
cnt, size,
dir ? "UP" : "DOWN");
print_array(array + low, cnt);
_bitonicSort(array, low, k, 1, size);
_bitonicSort(array, low + k, k, 0, size);
_bitonicMerge(array, low, cnt, dir);
printf("%s [%lu/%lu] (%s):\n", "Result", cnt, size,
dir ? "UP" : "DOWN");
print_array(array + low, cnt);
}
}
/**
 *_bitonicMerge -function to merge subroutine for bitonic sequences.
 * @array: An array of integers.
 * @low: the lower index of subarray.
 * @cnt: the number of elements in subarray to merge.
 * @dir: direction of bitonic subsequence (1 is ascending, 0 is decreasing).
 */
void _bitonicMerge(int *array, size_t low, size_t cnt, size_t dir)
{
size_t i, k = cnt / 2;
int tmp;
if (cnt > 1)
{
for (i = low; i < low + k; i++)
{
if (!(dir ^ (array[i] > array[i + k])))
{
tmp = array[i];
array[i] = array[i + k];
array[i + k] = tmp;
}
}
_bitonicMerge(array, low, k, dir);
_bitonicMerge(array, low + k, k, dir);
}
}


/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
_bitonicSort(array, 0, size, 1, size);
}
