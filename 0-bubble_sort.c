#include "sort.h"

void swap(int *number1, int *number2);

/**
 * bubble_sort - sorts a given array in ascending order
 *
 * @array: array to sort
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
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
