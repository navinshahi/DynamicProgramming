//Matrix Chain Multiplication Recursive Approach
#include<stdio.h>
#include<limits.h>
int solve(int arr[],int i,int j)
{
	if(i>=j)
	return 0;
	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		if(tempans<mn)
		mn=tempans;
	}
	return mn;
}
int main()
{
	int arr[20]={40,20,30,10,30};
	int n=5;
	printf("Minimum Cost : %d",solve(arr,1,n-1));
	return 0;
}
