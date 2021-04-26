#include "search_algos.h"
/**
 * print_array - Function that prints an array during a binary search.
 * @array: array to print.
 * @low: first item of the array range.
 * @high: last item of the array range.
 */
void print_array(int *array, int low, int high)
{
	int idx;

	printf("Searching in array: ");
	for (idx = low; idx < high + 1; idx++)
	{
		if (idx < high)
			printf("%d, ", array[idx]);
		else
			printf("%d\n", array[idx]);
	}
}
/**
 * adv_binary_search - function that searches for a value in a sorted array.
 * @array: array to search the value.
 * @low: first item of the array range.
 * @high: last item of the array range.
 * @value: value to search into the array.
 * Return: the index of the value, otherwhise it will return -1.
 */
int adv_binary_search(int *array, int low, int high, int value)
{
	int mid;

	if (low > high)
		return (-1);

	mid = low + (high - low) / 2;

	print_array(array, low, high);
	if (array[mid] < value)
		low = mid + 1;

	else if (array[mid] > value)
		high = mid;

	else if (array[mid] == value && array[mid - 1] == value)
		high = mid;

	else
		return (mid);

	return (adv_binary_search(array, low, high, value));
}
/**
 * advanced_binary - function that searches for a value in a sorted array.
 * @array: array to search the value.
 * @size: size of the array.
 * @value: value to search into the array.
 * Return: the index of the value, otherwhise it will return -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int low = 0;
	int high = (int)size - 1;

	if (!array || size == 0)
		return (-1);

	return (adv_binary_search(array, low, high, value));
}
