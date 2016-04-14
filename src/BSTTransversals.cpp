/*
Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder
Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .
Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs
Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void post(struct node *,int *,int *);
void pre(struct node *, int *, int *);
void in(struct node *, int *, int *);


void inorder(struct node *root, int *arr){
	int index1 = 0;
	if (root != NULL && arr!=NULL)
	{
		in(root, arr, &index1);
	}
	else
		return;
}

void preorder(struct node *root, int *arr){
	int index2 = 0;
	if (root != NULL&& arr!=NULL)
	{
		pre(root, arr, &index2);
	}

	else
		return;
}

void postorder(struct node *root, int *arr)
{
	int index3 = 0;
	if (root != NULL && arr!=NULL)
	{
		post(root, arr, &index3);
	}
	else
		return;
}
void in(struct node *root, int *arr, int *index1)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		in(root->left, arr, index1);
		arr[*index1] = root->data;
		(*index1)++;
		in(root->right, arr, index1);
	}
}
void pre(struct node *root, int *arr, int *index2)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		arr[*index2] = root->data;
		(*index2)++;
		pre(root->left, arr, index2);
		pre(root->right, arr, index2);
	}
}
void post(struct node *root, int *arr, int *index3)
{
	if (root==NULL)
		return;
	else
	{
		post(root->left, arr, index3);
		post(root->right, arr, index3);
		arr[*index3] = root->data;
		(*index3)++;
	}
}