//sum(s1)=(diff+sum(arr))/2
//sum(s1)=(1+7)/2=4
//same as Count Of Subset Sum Problem
#include<stdio.h>
int main()
{
	int arr[20]={1,1,2,3},diff=1,n=4;
	int sum=4; 
	int t[n+1][sum+1];
	//Base Condition
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
			t[i][j]=0;
			if(j==0)
			t[i][j]=1;
		}
	}
	//Main Program
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
			else
				t[i][j]=t[i-1][j]; 
		}
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	printf("Count Number Of Subset Sum With Given Difference : %d",t[n][sum]);
	return 0;
}
