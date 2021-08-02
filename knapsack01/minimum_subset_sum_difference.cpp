#include<stdio.h>
int findMin(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	bool t[n+1][sum+1];
	for(int i=0;i<=n;i++)
	t[i][0]=true;
	for(int i=1;i<=sum;i++)
	t[0][i]=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			t[i][j]=t[i-1][j];
			if(arr[i-1]<=j)
			t[i][j] |=t[i-1][j-arr[i-1]];
		}
	}
	int diff;
	for(int j=sum/2;j>=0;j--)
	{
		if(t[n][j]==true)
		{
			diff=sum-2*j;
			break;
		}
	}
	return diff;
}
int main()
{
	int arr[10]={1,6,11,5};
	int n=4;
	printf("The minimum difference between 2 sets : %d",findMin(arr,n));
	return 0;
}
