//Matrix Chain Multiplication Memoization
#include<stdio.h>
#include<limits.h>
#include<string.h>
int static t[1001][1001];
int solve(int arr[],int i,int j)
{
	if(i>=j)
	return 0;
	if(t[i][j]!=-1)
	return t[i][j];
	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		if(tempans<mn)
		mn=tempans;
	}
	return t[i][j]=mn;
}
int main()
{
	int arr[20]={40,20,30,10,30};
	int n=5;
	memset(t,-1,sizeof(t));
	printf("Minimum Cost : %d",solve(arr,1,n-1));
	return 0;
}
