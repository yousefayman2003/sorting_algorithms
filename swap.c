#include "sort.h"

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
