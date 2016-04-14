/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is
6                        <-- Copy this first
/ \
4  10                      <-- Copy this row next from 10 and next 4 ..
/ \   \
1   5   15                   <-- Order her is 15 ,5 ,1
\
17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};

int *arr;
int getheight(struct node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int left, right;
		left = getheight(root->left);
		right = getheight(root->right);
		if (left >= right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}
void pushtoArray(struct node *root, int level, int *index)
{
	if (root == NULL)
	{
		return;
	}
	if ((level == 1))
	{
		if (*index != 0)
		{
			arr = (int *)realloc(arr, sizeof(int)*((*index) + 1));
		}
		arr[*index] = root->data;
		(*index) = (*index) + 1;
	}
	else
	{
		pushtoArray(root->right, level - 1, index);
		pushtoArray(root->left, level - 1, index);
	}
}

int* BSTRighttoLeftRows(struct node* root)
{
	int  height = 0, level = 0, index = 0;
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
	arr = (int *)malloc(sizeof(int));
	if (root == NULL)
		return NULL;
	else
	{
		height = getheight(root);
		for (level = 0; level < height; level++)
		{
			pushtoArray(root, level + 1, &index);
		}
	}
	return arr;
}