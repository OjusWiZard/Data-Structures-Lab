#include <stdio.h>
#include <stdlib.h>

int *mergeSort(int *arr, int size)
{
	// Base Case
	if (size<2)
		return arr;

	// Dividing
	int *p1 = mergeSort(arr, size/2);
	int *p2 = mergeSort(arr+size/2, size-size/2);

	// Array to be returned
	int *sorted = (int *)calloc(size, sizeof(int));

	// Merging
	int s = 0, i = 0, j = 0;
	while (i<size/2&&j<(size-size/2))
	{
		if (p1[i]<p2[j])
		{
			sorted[s] = p1[i];
			i++;
		}
		else
		{
			sorted[s] = p2[j];
			j++;
		}
		s++;
	}
	while (i<size/2)
	{
		sorted[s] = p1[i];
		i++;
		s++;
	}
	while (j<(size-size/2))
	{
		sorted[s] = p2[j];
		j++;
		s++;
	}

	return sorted;
}

int main()
{
	int n;
	printf("Entert the number of elements: ");
	scanf("%d", &n);
	printf("Enter the array: ");
	int *arr = (int *)calloc(n, sizeof(int));
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\nThe Sorted Array is: ");
	int *sortedArr = mergeSort(arr, n);
	for (int i = 0; i<n; i++)
	{
		printf("%d ", sortedArr[i]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}