#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *f, *r;

void enque(int e)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = e;
	new->next = NULL;
	if (r == NULL)
		f = r = new;
	else
	{
		r->next = new;
		r = new;
	}
	printf("Enqueued %d in the Queue\n", e);
}

void deque()
{
	if (f == NULL)
		printf("Underflow\n");
	else
	{
		struct node *temp = f;
		f = f->next;
		if (f == NULL)
			r = NULL;
		printf("Dequeued %d from the Queue\n", temp->data);
		free(temp);
	}
}

void display()
{
	printf("The Queue is: ");
	if (f != NULL && r != NULL)
	{
		struct node *i = f;
		while (i != r->next)
		{
			printf("%d ", i->data);
			i = i->next;
		}
	}
	printf("\n\n");
}

int main()
{
	r = f = NULL;

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
			enque(e);
		}
		else if (choice == 2)
			deque();

		display();
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}