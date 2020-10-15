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

char *postfixOf(char *infix)
{
	struct node *stack = NULL;
	char *postfix = (char *)calloc(10, sizeof(char));
	int j = 0;
	for (int i = 0; infix[i] <= 'z' && infix[i] >= 'a' || precedence(infix[i]); i++)
	{
		if (infix[i] <= 'z' && infix[i] >= 'a')
			postfix[j++] = infix[i];
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
					postfix[j++] = top(stack);
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
		postfix[j++] = top(stack);
		stack = pop(stack);
	}
	postfix[j] = '\0';
	return postfix;
}

char *reverse(char *string)
{
	int length = 0;
	while (string[length] != '\0')
		length++;

	for (int i = 0; i < length / 2; i++)
	{
		char temp = string[i];
		string[i] = string[length - 1 - i];
		string[length - 1 - i] = temp;
	}
	return string;
}

void prefixOf(char *infix)
{
	char *reverseInfix = reverse(infix);
	char *reversePostfix = postfixOf(reverseInfix);
	char *prefix = reverse(reversePostfix);

	printf("%s", prefix);
}

int main()
{
	printf("Enter the Infix Expression: ");
	char infix[10];
	scanf("%s", &infix);

	printf("\nThe Prefix Expression is: ");
	prefixOf(infix);

	printf("\n\n\n");
	system("pause");
	return 0;
}