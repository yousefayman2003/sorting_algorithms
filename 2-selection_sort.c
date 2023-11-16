#include "sort.h"

/* function declaretion */
int get_min(int *array, int size, int min, size_t index);
void swap(int *number1, int *number2);

/**
 * selection_sort - sorts a given array in ascending order
 *
 * @array: given array to sort
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	int min, index;
	size_t i;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		/* get the minimum element index */
		index = get_min(array, size, min, i);
		min = array[index];

		/* if the curr element is not the min swap */
		if (array[i] != min)
		{
			swap(&array[i], &array[index]);
			print_array(array, size);
		}
	}
}

/**
 * get_min - get the minimum element index from an array starting
 *		given index
 *
 * @array: given array
 * @size: size of the array
 * @min: current min element
 * @index: index to start searching from
 *
 * Return: min element starting from given index
*/
int get_min(int *array, int size, int min, size_t index)
{
	int j;

	for (j = index + 1; j < size; j++)
	{
		if (min > array[j])
		{
			min = array[j];
			index = j;
		}
	}

	return (index);
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
