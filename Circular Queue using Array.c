#include <stdio.h>
#include <stdlib.h>

const int capacity = 3;
int front = 0, rear = -1, size = 0;

void enQueue(int *q, int d)
{
	if (size == capacity)
		printf("Queue is full!\n");
	else
	{
		rear = (rear + 1) % capacity;
		q[rear] = d;
		size++;
		printf("enQueued %d into the Circular Linked List\n", d);
	}
}

void deQueue(int *q)
{
	if (size == 0)
		printf("Queue is empty!\n");
	else
	{
		printf("deQueued %d into the Circular Linked List\n", q[front % capacity]);
		front = (front + 1) % capacity;
		size--;
	}
}

void display(int *q)
{
	printf("Current data: ");
	for (int i = 0, j = front; i < size; i++, j++)
		printf("%d ", q[j % capacity]);
	printf("\n\n");
}

int main()
{
	int *queue = (int *)calloc(capacity, sizeof(int));

	printf("-1 to Exit\n1 <element> to enQueue\n2 <element> to deQueue\n\n");
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
			enQueue(queue, e);
		}
		else if (choice == 2)
			deQueue(queue);

		display(queue);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}