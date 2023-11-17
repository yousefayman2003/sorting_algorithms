#include "sort.h"

/* function declaretion */
void swap(int *number1, int *number2);
int partition(int *array, int low, int high, size_t size);
void quick_sort_recursion(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts an array in ascending order
 *
 * @array: array to sort
 * @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - helper function for quicksort
 *
 * @array: given array
 * @low: low index
 * @high: high index
 * @size: size of the array
*/
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int index = partition(array, low, high, size);

		quick_sort_recursion(array, low, index - 1, size);
		quick_sort_recursion(array, index, high, size);
	}
}

/**
 * partition - partition the array around the pivot index
 *
 * @array: given array
 * @low: low index
 * @high: high index
 * @size: size of the array
 *
 * Return: pivot index
*/
int partition(int *array, int low, int high, size_t size)
{
	int j, i = low - 1, pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[j], &array[i]);
			if (i != j)
				print_array(array, size);
		}
	}

	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);

}

/**
 * swap - swaps two given numbers
 * @number1: pointer to first number
 * @number2: pointer to second number
*/
void swap(int *number1, int *number2)
{
	int tmp = *number1;
	*number1 = *number2;
	*number2 = tmp;
}
