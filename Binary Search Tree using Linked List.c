#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *insert(struct node *root, int data, char *path)
{
	if (root == NULL)
	{
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->data = data;
		new->left = new->right = NULL;
		return new;
	}
	else if (path[0] == 'L')
		root->left = insert(root->left, data, &path[1]);
	else
		root->right = insert(root->right, data, &path[1]);
	return root;
}

struct node *delete (struct node *root, char *path)
{
	if (root->left == NULL && root->right == NULL)
	{
		free(root);
		root = NULL;
	}
	else if (path[0] == 'L')
		root->left = delete (root->left, &path[1]);
	else
		root->right = delete (root->right, &path[1]);
	return root;
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
	printf("-1 to Exit\n1 <element> <path with L&R> to insert\n2 <element> <path with L&R> to delete\n\n");
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
			char path[10] = {'\0'};
			if (root != NULL)
				scanf("%s", path);
			root = insert(root, e, path);
		}
		else if (choice == 2)
		{
			char path[10];
			scanf("%s", path);
			root = delete (root, path);
		}
		printf("Current Tree (inOrder): ");
		displayInOrder(root);
		printf("\n\n");
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}