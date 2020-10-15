#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node *next;
};

struct node *push(struct node *head, char e)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = e;
	new->next = head;
	head = new;
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
		free(temp);
	}
	return head;
}

char top(struct node *head)
{
	return head->data;
}

int empty(struct node *head)
{
	if (head == NULL)
		return 1;
	else
		return 0;
}

int precedence(char operator)
{
	if (operator== '+' || operator== '-')
		return 1;
	else if (operator== '*' || operator== '/')
		return 2;
	else
		return 0;
}

void postfixOf(char *infix)
{
	struct node *stack = NULL;
	for (int i = 0; infix[i] <= 'z' && infix[i] >= 'a' || precedence(infix[i]); i++)
	{
		if (infix[i] <= 'z' && infix[i] >= 'a')
			printf("%c", infix[i]);
		else
		{
			if (empty(stack))
				stack = push(stack, infix[i]);
			else if (precedence(top(stack)) < precedence(infix[i]))
				stack = push(stack, infix[i]);
			else
			{
				while (precedence(top(stack)) >= precedence(infix[i]))
				{
					printf("%c", top(stack));
					stack = pop(stack);
					if (empty(stack))
						break;
				}
				stack = push(stack, infix[i]);
			}
		}
	}
	while (!empty(stack))
	{
		printf("%c", top(stack));
		stack = pop(stack);
	}
}

int main()
{
	printf("Enter the Infix Expression: ");
	char infix[10];
	scanf("%s", &infix);

	printf("\nThe Postfix Expression is: ");
	postfixOf(infix);

	printf("\n\n\n");
	system("pause");
	return 0;
}