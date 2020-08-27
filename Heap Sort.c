#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	printf("Enter the number of elements in the array: ");
	int n;
	scanf("%d", &n);
	printf("Enter the elements of the array: ");
	int *arr = (int *)calloc(n + 1, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	// Heap Sort
	int last = n - 1;
	while (last >= 0)
	{
		int i = (last - 1) / 2;
		while (i >= 0)
		{
			int leftChild = i * 2;
			int rightChild = i * 2 + 1;
			int largerChild = arr[leftChild] > arr[rightChild] ? leftChild : rightChild;

			if (arr[i] < arr[largerChild])
			{
				int temp = arr[i];
				arr[i] = arr[largerChild];
				arr[largerChild] = temp;
			}
			i--;
		}

		int temp = arr[0];
		arr[0] = arr[last];
		arr[last] = temp;
		last--;
	}
	if (arr[0] > arr[1])
	{
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}

	printf("\nThe Sorted array is: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n\n\n");
	system("pause");
	return 0;
}