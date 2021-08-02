#include<stdio.h>
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	int coin[]={1,2,3},n=3;
	int sum=5,t[n+1][sum+1],INT_MAX=2147483647,i;
		//Base Condition
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
			t[i][j]=INT_MAX-1;
			if(j==0 && i>0)
			t[i][j]=0;
		}
	}
	i=1;
	for(int j=1;j<sum+1;j++)
	{
		if(j%coin[0]==0)
		t[i][j]=j/coin[0];
		else
		t[i][j]=INT_MAX-1;
	}
	//Main Program
	for(int i=2;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(coin[i-1]<=j)
				t[i][j]=min(t[i][j-coin[i-1]]+1, t[i-1][j]);
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
