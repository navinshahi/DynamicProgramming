#include<stdio.h>
int main()
{
	int coin[]={1,2,3},n=3;
	int sum=5,t[n+1][sum+1];
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
			if(coin[i-1]<=j)
				t[i][j]=t[i][j-coin[i-1]] + t[i-1][j];
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
	printf("Result : %d",t[n][sum]);
	return 0;
}
