#include "sort.h"

/* function declaretion */
void recursion(int *array, int low, int high);
void merge(int *array, int low, int mid, int high);

/**
 * merge_sort - sorts an array
 *
 * @array: array to sort
 * @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	recursion(array, 0, size - 1);
}

/**
 * recursion - recursivly sorts the and then merges it
 *
 * @array: array to sort
 * @low: low index
 * @high: high index
*/
void recursion(int *array, int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;

		recursion(array, low, mid);
		recursion(array, mid + 1, high);
		merge(array, low, mid, high);
		printf("Merging...\n[left]: ");
		print_array(array + low, mid - low + 1);
		printf("[right]: ");
		print_array(array + mid + 1, high - mid);
		printf("[Done]: ");
		print_array(array + low, high - low + 1);
	}
}

/**
 * merge - merge two arrays
 *
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @mid: middle index
*/
void merge(int *array, int low, int mid, int high)
{
	int left_size = mid - low + 1;
	int right_size = high - mid;
	int *temp = malloc(sizeof(int) * (left_size + right_size));
	int i, j, k;

	/* fill temp */
	for (i = 0; i < left_size; i++)
		temp[i] = array[low + i];

	/* fill temp2 */
	for (j = 0; j < right_size; j++)
		temp[left_size + j] = array[mid + 1 + j];

	/* merge two sorted arrays */
	i = 0, j = 0, k = low;

	while (i < left_size && j < right_size)
	{
		if (temp[i] <= temp[left_size + j])
		{
			array[k] = temp[i];
			i++;
		}
		else
		{
			array[k] = temp[left_size + j];
			j++;
		}
		k++;
	}
	/* copy remaining elements if any */
	while (i < left_size)
	{
		array[k] = temp[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		array[k] = temp[left_size + j];
		j++;
		k++;
	}
	free(temp);
}
