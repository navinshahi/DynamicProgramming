//Return maximum path sum from leaf to leaf.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    // Allocate memory for new node
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
 
    // Assign data to this node
    node->data = data;
 
    // Initialize left and
    // right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int solve(node* root,int* res)
{   //Base Condition
	if(root==NULL)
	return 0;
	//Hypothesis
	int l=solve(root->left,res);
	int r=solve(root->right,res);
	//Induction
	int temp=max(l,r)+root->data;
	if(root->left==NULL && root->right==NULL)
	temp=max(temp,root->data);
	int ans=max(temp,l+r+root->data);
	*res=max(*res,ans);
	return temp;
}
int main()
{
	struct node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->left->right->left=newNode(6);
	root->left->right->right=newNode(7);
	root->right->right=newNode(8);
	root->right->right->right=newNode(9);
	root->right->right->right->left=newNode(10);
	root->right->right->right->right=newNode(11);
	int res=INT_MIN;
	solve(root,&res);
	printf("Maximum Path Sum from Leaf to Leaf : %d",res);
	return 0;
}
