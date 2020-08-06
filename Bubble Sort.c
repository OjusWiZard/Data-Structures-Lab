#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter the number of Elements: ");
	scanf("%d", &n);
	int *array = (int*)malloc(n*sizeof(int));
	printf("\nEnter the Array Elements: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	
	// Bubble Sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j+1 < n-i; j++)
		{
			if(array[j]>array[j+1])
			{ 
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

	printf("\nThe Sorted Array is: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	free(array);
	printf("\n\n");
	system("pause");
	return 0;
}

