//it is same as Count Number Of Subset With Given Sum
#include<stdio.h>
int main()
{
	int arr[20]={1,1,2,3},sum=1,n=4; //or diff=1
	int s=4; //from sum(s1)=(diff+(sum(arr))/2
	int t[n+1][s+1];
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
	
	printf("Target Sum : %d",t[n][s]);
	return 0;
}
