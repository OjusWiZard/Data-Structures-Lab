#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter the number of Elements: ");
	scanf("%d", &n);
	int *array = (int *)calloc(n, sizeof(int));
	printf("\nEnter the Array Elements: ");
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &array[i]);
	}

	// Insertion Sort
	for (int i = 1; i<n; i++)
	{
		int temp = array[i], j;
		for (j = i; j>0&&temp<array[j-1]; j--)
		{
			array[j] = array[j-1];
		}
		array[j] = temp;
	}

	printf("\nThe Sorted Array is: ");
	for (int i = 0; i<n; i++)
	{
		printf("%d ", array[i]);
	}
	free(array);
	printf("\n\n");
	system("pause");
	return 0;
}

