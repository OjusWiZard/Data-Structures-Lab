#include <stdio.h>
#include <stdlib.h>

int *quickSort(int *arr, int l, int r)
{
	// Base Case
	if (l>=r)
		return arr;

	// Partitioning 
	int pivot = r, start = l, end = r;
	r--;
	while (l<=r)
	{
		if (arr[l]>=arr[pivot]&&arr[pivot]>=arr[r])
		{
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
		if (arr[l]<=arr[pivot])
			l++;
		if (arr[pivot]<=arr[r])
			r--;
	}

	// Placing the Pivot
	int temp = arr[pivot];
	arr[pivot] = arr[l];
	arr[l] = temp;

	// Sorting both halves
	quickSort(arr, start, l-1);
	quickSort(arr, l+1, end);

	return arr;
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
	int *sortedArr = quickSort(arr, 0, n-1);
	for (int i = 0; i<n; i++)
	{
		printf("%d ", sortedArr[i]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}