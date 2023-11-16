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
	size_t i, j, index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		/* get the minimum element index */
		for (j = i + 1; j < size; j++)
		{
			if (array[index] > array[j])
				index = j;
		}

		/* if the curr element is not the min swap */
		if (i != index)
		{
			swap(&array[i], &array[index]);
			print_array(array, size);
		}
	}
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
