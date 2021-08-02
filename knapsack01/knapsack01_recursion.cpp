#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int knapsack(int wt[20],int val[20],int W,int n)
{
	if(n==0 || W==0)
	return 0;
	if(wt[n-1]<=W)
	return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
	else if(wt[n-1]>W)
	return knapsack(wt,val,W,n-1);
	
}
int main()
{
	int wt[20]={1,3,4,5};
	int val[20]={1,4,5,7};
	int W=7;
	int n=4;
	printf("%d",knapsack(wt,val,W,n));
	return 0;
}
