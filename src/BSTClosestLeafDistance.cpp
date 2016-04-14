/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
  struct node * left;
  int data;
  struct node *right;
};
void find(struct  node *, int, int *,int *,int *);
int get_min_dist_below(struct node *);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	int res = -1,i=0,j=0;
	if (root == NULL || temp == NULL)
	{
		return -1;
	}
	else
	{
		find(root, temp->data,&res,&i,&j);
		return res;
	}
}
void find(struct node *root, int key, int *res,int *i,int *j)
{
	(*i)++;//used to know height of recursive stack(AKA height of present node from root)
	struct node *prev;
	int temp;
	if (root == NULL)
	{
		return;
	}
	if (key == root->data)
	{
		*res = get_min_dist_below(root);
		(*j) = (*i) - 1;//tracks top index of recursive stack(AKA distance from present node to key node )
	}
	else if (key < root->data)
	{
		prev = root;
		find(root->left,key,res,i,j);
		if (*res != -1)
		{
			temp = get_min_dist_below(prev) + ( *i ) - ( *j );
			(*j)--;
			if (*res>temp)
			{
				*res = temp;
			}
		}
	}
	else
	{

		prev = root;
		find(root->right,key,res,i,j);
		if (*res != -1)
		{
			temp = get_min_dist_below(prev) + (*i) - (*j);
			(*j) --;
			if (*res > temp)
			{
				*res = temp;
			}
		}
	}
}
int get_min_dist_below(struct node *root)
{
	int left = -1,right=-1;
	if (root->left == NULL&&root->right == NULL)
	{
		return 0;
	}
	if (root->left != NULL)
		left = get_min_dist_below(root->left);
	if (root->right != NULL)
		right = get_min_dist_below(root->right);
	if (left == -1)
	{
		if (right != -1)
		{
			return  right+1;
		}
		else
		{
			return -1;
		}
	}
	else if (right == -1)
	{
		return left+1;
	}
	else
	{
		return left<right ? left + 1 : right + 1;
	}
}