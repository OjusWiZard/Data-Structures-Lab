#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *front, *rear;

void enQueue(int d)
{
	struct node *new = malloc(sizeof(struct node));
	new->data = d;
	if (front == NULL)
		front = new;
	else
		rear->next = new;
	rear = new;
	new->next = front;
	printf("enQueued %d into the Circular Linked List\n", d);
}

void deQueue()
{
	if (front == NULL)
		printf("Queue is empty!\n");
	else if (front == rear)
	{
		free(front);
		front = rear = NULL;
	}
	else
	{
		printf("deQueued %d into the Circular Linked List\n", front->data);
		struct node *temp = front;
		front = front->next;
		rear->next = front;
		free(temp);
	}
}

void display()
{
	printf("Current data: ");
	struct node *itr = front;
	int looped = 0;
	while ((itr != front || looped == 0) && itr != NULL)
	{
		printf("%d ", itr->data);
		itr = itr->next;
		looped = 1;
	}
	printf("\n\n");
}

int main()
{
	front = NULL, rear = NULL;

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
			enQueue(e);
		}
		else if (choice == 2)
			deQueue();

		display(front);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}