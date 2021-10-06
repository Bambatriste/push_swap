#include "push_swap.h"

void	swap(int *array, int left, int right)
{
	int	tmp;

	tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

int	partition(int *array, int start, int end)
{
	int	pivot;
	int	pivot_location;
	int	leftwall;

	pivot = array[start];
	pivot_location = start;
	leftwall = start;
	start = start + 1;
	while (start < end)
	{
		if (array[start] < pivot)
		{
			swap(array, start, leftwall + 1);
			leftwall = leftwall + 1;
		}
		start++;
	}
	swap(array, pivot_location, leftwall);
	return (leftwall);
}

void	quicksort(int *array, int start, int end)
{
	int	pivot_location;

	if (start < end)
	{
		pivot_location = partition(array, start, end);
		quicksort(array, start, pivot_location);
		quicksort(array, pivot_location + 1, end);
	}
}
