#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
	int sum=0,n=12;
	for(int i=0;i<n;i++)
	sum=sum+arr[i];
	if(sum%2!=0)
	printf("False");
	else
	{
	int t[n+1][(sum/2)+1];
	//Base Condition
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<(sum/2)+1;j++)
		{
			if(i==0)
			t[i][j]=false;
			if(j==0)
			t[i][j]=true;
		}
	}
	//Main Program
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<(sum/2)+1;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
			else
				t[i][j]=t[i-1][j]; 
		}
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<(sum/2)+1;j++)
		{
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	if(t[n][sum/2]==true)
	printf("True");
	else
	printf("False");
	}
	return 0;
}
