#include <stdio.h>
#include <stdlib.h>

void solveTower(int n, char S, char A, char D)
{
	if (n == 1)
		printf("\nMove from %c to %c", S, D);
	else
	{
		solveTower(n - 1, S, D, A);
		solveTower(1, S, A, D);
		solveTower(n - 1, A, S, D);
	}
}

int main()
{
	printf("Enter the number of rings: ");
	int n;
	scanf("%d", &n);

	solveTower(n, 'A', 'B', 'C'); // S=Source, A=Auxiliary, D=Destination

	printf("\n\n\n");
	system("pause");
	return 0;
}