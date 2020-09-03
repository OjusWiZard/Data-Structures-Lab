#include <stdio.h>

const int SIZE = 32;
int front = -1, rear = -1;

void enque(int *q, int e)
{
	if (rear == SIZE - 1)
		printf("Overflow\n");
	else
	{
		q[++rear] = e;
		printf("Enqueued %d in the Queue\n", e);
	}
}

int deque(int *q)
{
	if (front == rear)
		printf("Underflow\n");
	else
	{
		front++;
		printf("Dequeued %d from the Queue\n", q[front]);
		return q[front - 1];
	}
}

void display(int *q)
{
	printf("The Queue is: ");
	for (int i = front + 1; i <= rear; i++)
		printf("%d ", q[i]);
	printf("\n\n");
}

int main()
{
	int *queue = (int *)calloc(SIZE, sizeof(int));

	printf("-1 to Exit\n1 <element> to enque\n2 <element> to deque\n\n");
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
			enque(queue, e);
		}
		else if (choice == 2)
			deque(queue);

		display(queue);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}