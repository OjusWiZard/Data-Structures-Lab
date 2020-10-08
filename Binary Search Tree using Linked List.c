#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *insert(struct node *root, int data)
{
	if (root == NULL)
	{
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->data = data;
		new->left = new->right = NULL;
		return new;
	}
	else if (data <= root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	return root;
}

struct node *delete (struct node *root, int data)
{
	if (root->data == data)
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		if ((root->left == NULL) ^ (root->right == NULL))
		{
			struct node *temp;
			if (root->left != NULL)
				temp = root->left;
			else
				temp = root->right;
			free(root);
			return temp;
		}
		else if (root->left != NULL && root->right != NULL)
		{
			root->data = root->left->data;
			root->left = delete (root->left, root->left->data);
			return root;
		}
	}
	else if (root == NULL)
		return NULL;
	else if (data <= root->data)
		root->left = delete (root->left, data);
	else
		root->right = delete (root->right, data);
	return root;
}

int search(struct node *root, int data)
{
	if (root == NULL)
		return 0;
	else if (root->data == data)
		return 1;
	else if (data <= root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

void displayInOrder(struct node *root)
{
	if (root->left != NULL)
		displayInOrder(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		displayInOrder(root->right);
}

int main()
{
	struct node *root = NULL;
	printf("-1 to Exit\n1 <element> to insert\n2 <element> to delete\n3 <element> to search\n\n");
	while (1)
	{
		int choice, element;
		scanf("%d", &choice);
		scanf("%d", &element);
		if (choice == -1)
			break;

		if (choice == 1)
			root = insert(root, element);
		else if (choice == 2)
			root = delete (root, element);
		else if (choice == 3)
			if (search(root, element))
				printf("%d is present in the tree\n", element);
			else
				printf("%d is not present in the tree\n", element);
		printf("Current Tree (inOrder): ");
		displayInOrder(root);
		printf("\n\n");
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}