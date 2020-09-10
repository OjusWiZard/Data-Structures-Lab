#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int size, int key)
{
	int res = -1;
	for (int i = 0; i < size; i++)
		if (arr[i] == key)
		{
			res = i;
			break;
		}
	return res;
}

int main()
{
	printf("Enter the number of elements in the Array: ");
	int n, key;
	scanf("%d", &n);
	int *arr = (int *)calloc(n, sizeof(int));
	printf("\nEnter the elements of the Array: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("\nEnter the element to be searched: ");
	scanf("%d", &key);

	int result = linearSearch(arr, n, key);
	if (result == -1)
		printf("\nElement not found in the Array");
	else
		printf("\n%d found at index %d!", key, result);

	printf("\n\n\n");
	system("pause");
	return 0;
}