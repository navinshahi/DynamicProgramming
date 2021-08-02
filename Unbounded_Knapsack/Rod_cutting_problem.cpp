#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int Length[]={1,2,3,4,5,6,7,8};
	int Price[]={1,5,8,9,10,17,17,20};
	int l=8,n=8;
	int t[n+1][l+1];
	//Initialization
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<l+1;j++)
		{
			if(i==0 || j==0)
			t[i][j]=0;
		}
	}
	//Main Code
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<l+1;j++)
		{
			if(Length[i-1]<=j)
				t[i][j]=max(Price[i-1]+t[i][j-Length[i-1]],t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<l+1;j++)
		{
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	printf("Result : %d",t[n][l]);
	return 0;
}
