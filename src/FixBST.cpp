/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

5
/ \
2   3
\
30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

9
/ \
4   1
/     \
20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};


void find(struct node *, struct node **, struct node **,struct node **);
void swap(struct node*, struct node *);

void fix_bst(struct node *root)
{
	struct node *first = NULL, *second = NULL;
	struct node *prev=NULL;
	find(root, &first, &second,&prev);
	if (first != NULL)
	{
		if (second == NULL)
		{
			second = prev;
			swap(first, second);
		}
	}
}

void find(struct node *root, struct node ** first, struct node ** second,struct node **prev)
{
	if (!root)
		return;
	else
	{
		find(root->left, first, second,prev);
		if (!(*first))
		{
			if (!(*prev))
			{
				*prev = root;
			}
			else
			{
				if ((*prev)->data > root->data)
				{
					*first = *prev;
				}
			}
		}
		else
		{
			if ((*first)->data < root->data)
			{
				*second = *prev;
				swap(*first, *second);
				return;
			}
		}
		*prev = root;
		find(root->right, first, second,prev);
	}
}

void swap(struct node * temp1, struct node *temp2)
{
	int temp=temp1->data;
	temp1->data = temp2->data;
	temp2->data = temp;
}