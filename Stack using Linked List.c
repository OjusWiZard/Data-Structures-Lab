#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *push(struct node *head, int e)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = e;
	new->next = head;
	head = new;
	printf("Pushed %d\n", e);
	return head;
}

struct node *pop(struct node *head)
{
	if (head == NULL)
		printf("Stack Underflow\n");
	else
	{
		struct node *temp = head;
		head = head->next;
		printf("%d Popped\n", temp->data);
		free(temp);
	}
	return head;
}

void display(struct node *head)
{
	struct node *temp = head;
	printf("\nThe Stack is: ");
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	struct node *head = NULL;
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
			head = push(head, e);
		}
		else if (choice == 2)
			head = pop(head);

		display(head);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}