#include <stdio.h>
#include <stdlib.h>

const int MAXSIZE = 10;
int sp = -1;

void push(int *stack, int e)
{
	if (sp == MAXSIZE - 1)
		printf("Stack Overflow\n");
	else
		printf("Pushed %d\n", stack[++sp] = e);
}

void pop(int *stack)
{
	if (sp == -1)
		printf("Stack Underflow\n");
	else
		printf("%d Popped\n", stack[sp--]);
}

void display(int *stack)
{
	printf("\nThe Stack is: ");
	for (int i = sp; i >= 0; i--)
		printf("%d ", stack[i]);
	printf("\n");
}

int main()
{
	int *stack = (int *)calloc(MAXSIZE, sizeof(int));

	printf("-1 to Exit\n1 <element> to push\n2 <element> to pop\n\n");
	while (1)
	{
		int choice;
		scanf("%d", &choice);
		if (choice == -1)
			break;

		if (choice == 1)
		{
			int e;
			scanf("%d", &e);
			push(stack, e);
		}
		else if (choice == 2)
			pop(stack);

		display(stack);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}